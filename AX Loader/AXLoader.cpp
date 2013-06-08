#include "stdafx.h"
#include "AXLoader.h"

/*
    AX Loader. Upload compiled sketches to an Arduino Board.
    Copyright (C) 2013 José Andrés García Sáenz.

	This file is part of AX Loader.
    AX Loader is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AX Loader is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Contact: <jags9415@gmail.com>
*/

using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Management;
using namespace System::Text;

namespace AXLoader
{

	/// <summary>
	/// Initializes a new instance of the <see cref="AXLoader" /> class.
	/// </summary>
	AXLoader::AXLoader(void)
	{
		this->UploadProcess = gcnew Process();
		this->Board = gcnew ArduinoBoard();
		this->Port = String::Empty;
		this->Target = String::Empty;
		this->Output = String::Empty;

		this->UploadProcess->StartInfo->FileName = "avrdude.exe";
		this->UploadProcess->StartInfo->UseShellExecute = false;
		this->UploadProcess->StartInfo->CreateNoWindow = true;
		this->UploadProcess->StartInfo->RedirectStandardError = true;
	}

	/// <summary>
	/// Uploads the Hex file specified by "Target" to the Arduino Board.
	/// </summary>
	/// <returns>
	/// Zero for exit succesfully.
	/// Any other number for an failed upload.
	/// </returns>
	int AXLoader::UploadTarget(void)
	{
		this->ResetBoard();
		this->UploadProcess->StartInfo->Arguments = GenerateArguments();
		this->UploadProcess->Start();
		this->Output = this->UploadProcess->StandardError->ReadToEnd();
		this->UploadProcess->WaitForExit();
		return this->UploadProcess->ExitCode;
	}

	/// <summary>
	/// Resets the board if needed.
	/// The avrdude upload protocol for most Arduino reset the board automatically.
	/// But If the board works with an ATmega32u4 MCU the avrdude upload protocol is avr109 and
	/// if the board works with an ATmega2560 MCU the avrdude upload protocol is wiring.
	/// This two protocol do not reset the board automatically.
	///
	/// The boards with ATmega32u4 are resetted by opening the serial port an closing it with a baud rate of 1200.
	/// The boards with ATmega2560 are reetted by turning the DTR line high and low.
	/// </summary>
	void AXLoader::ResetBoard(void)
	{
		SerialPort^ serialPort = gcnew SerialPort( this->Port );
		String^ Micro = this->Board->MicroController;

		if ( Micro->Equals("ATmega32u4") )
		{
			serialPort->BaudRate = 1200;
			serialPort->Close();
			serialPort->Open();
			serialPort->Close();
			Sleep(1000);
			this->Port = SearchArduino();
		}
		else if ( Micro->Equals("ATmega2560") )
		{
			serialPort->Close();
			serialPort->Open();
			serialPort->DtrEnable = true;
			Sleep(500);
			serialPort->DtrEnable = false;
			serialPort->Close();
			this->Port = SearchArduino();
		}
	}

	/// <summary>
	/// Searches in what serial port are the arduino connected.
	/// </summary>
	/// <returns>The name of the serial port if finded. Empty string otherwise.</returns>
	String^ AXLoader::SearchArduino(void)
	{
        ManagementObjectSearcher^ Searcher = gcnew ManagementObjectSearcher("Select * from Win32_SerialPort");
		ManagementObjectCollection^ Collection = Searcher->Get();

        for each (ManagementObject^ Obj in Collection)
        {
            if ( Obj["Description"]->ToString()->ToLower()->Contains("arduino") )
			{
				return Obj["DeviceID"]->ToString();
			}
        }

		return String::Empty;
	}

	/// <summary>
	/// Writes a log file with the output of the upload process.
	/// </summary>
	/// <param name="fileName">The name of the file.</param>
	void AXLoader::WriteLog(String^ fileName)
	{
		StreamWriter^ sw = gcnew StreamWriter( fileName, false );
		sw->Write( this->GetUploadOutput() );
		sw->Close();
	}

	/// <summary>
	/// Sets the board.
	/// </summary>
	/// <param name="boardName">The name of the board.</param>
	void AXLoader::SetBoard(String^ boardName)
	{
		for each (ArduinoBoard^ b in AXLoader::Boards)
		{
			if ( b->Name->Equals(boardName) )
			{
				this->Board = b;
			}
		}
	}

	/// <summary>
	/// Sets the Hex file target.
	/// </summary>
	/// <param name="target">The path of the file.</param>
	void AXLoader::SetTarget(String^ target)
	{
		this->Target = target;
	}

	/// <summary>
	/// Sets the serial port.
	/// </summary>
	/// <param name="port">The name of the port.</param>
	void AXLoader::SetSerialPort(String^ port)
	{
		this->Port = port;
	}

	/// <summary>
	/// Gets the upload process output.
	/// </summary>
	/// <returns>The upload process output.</returns>
	String^ AXLoader::GetUploadOutput(void)
	{
		return Output->Trim();
	}

	/// <summary>
	/// Checks if all the data is correct before attempting to upload an Hex file.
	/// </summary>
	Void AXLoader::CheckParameters(void)
	{
		if ( String::IsNullOrEmpty(this->Target) )
		{
			throw gcnew FileNotFoundException("No target specified.");
		}

		FileInfo^ File = gcnew FileInfo(this->Target);

		if ( !File->Exists )
		{
			throw gcnew FileNotFoundException("File not found.", File->Name);
		}
		else if ( File->Length > this->Board->MaxSize )
		{
			throw gcnew IOException("File too big for the selected board.");
		}
		else if ( String::IsNullOrEmpty(this->Port) )
		{
			throw gcnew IOException("No port selected.");
		}
		else if ( this->Port->Equals("None") )
		{
			throw gcnew IOException("No ports availables.");
		}
		else{
			try
			{
				SerialPort^ serialPort = gcnew SerialPort( this->Port );
				serialPort->Close();
				serialPort->Open();
				serialPort->Close();
			}
			catch (Exception^)
			{
				throw gcnew IOException("Can not open the selected port.");
			}
		}
	}

	/// <summary>
	/// Generates the arguments that will be passed to avrdude.
	/// </summary>
	/// <returns>The arguments that will be passed to avrdude.</returns>
	String^ AXLoader::GenerateArguments(void)
	{
		StringBuilder^ Builder = gcnew StringBuilder();

		Builder->Append( "-C avrdude.conf -c " );
		Builder->Append( this->Board->Programmer );
		Builder->Append( " -P " );
		Builder->Append( this->Port );
		Builder->Append( " -p " );
		Builder->Append( this->Board->MicroController );
		Builder->Append( " -b " );
		Builder->Append( this->Board->BaudRate );
		Builder->Append( " -v -v -v -D -U flash:w:" );
		Builder->Append( "\"" + this->Target + "\"" );
		Builder->Append( ":i" );

		return Builder->ToString();
	}

	/// <summary>
	/// Gets the name of the boards that supports the system.
	/// </summary>
	/// <returns>The name of the boards that supports the system.</returns>
	array<String^>^ AXLoader::GetBoards(void)
	{
		int BoardCount = AXLoader::Boards->Count;
		array<String^>^ BoardNames = gcnew array<String^>( BoardCount );

		for (int i=0; i<BoardCount; i++)
		{
			BoardNames[i] = AXLoader::Boards[i]->Name;
		}

		return BoardNames;
	}

	/// <summary>
	/// Initializes the boards that will be supported in the system.
	/// </summary>
	/// <returns>The boards that will be supported in the system.</returns>
	List<ArduinoBoard^>^ AXLoader::InitializeBoards(void)
	{
		List<ArduinoBoard^>^ Boards = gcnew List<ArduinoBoard^>();
		Boards->Add( gcnew ArduinoBoard("Leonardo", "ATmega32u4", "avr109", 57600, 28672) );
		Boards->Add( gcnew ArduinoBoard("Uno", "ATmega328p", "arduino", 115200, 32256) );
		Boards->Add( gcnew ArduinoBoard("Esplora", "ATmega32u4", "avr109", 57600, 28672) );
		Boards->Add( gcnew ArduinoBoard("Micro", "ATmega32u4", "avr109", 57600, 28672) );
		Boards->Add( gcnew ArduinoBoard("Mega 2560 / Mega ADK", "ATmega2560", "wiring", 115200, 258048) );
		Boards->Add( gcnew ArduinoBoard("Mega (ATmega1280)", "ATmega1280", "arduino", 57600, 126976) );
		Boards->Add( gcnew ArduinoBoard("Duemilanove (ATmega328)", "ATmega328p", "arduino", 57600, 30720) );
		Boards->Add( gcnew ArduinoBoard("Diecimila / Duemilanove (ATmega168)", "ATmega168", "arduino", 19200, 14336) );
		Boards->Add( gcnew ArduinoBoard("Nano (ATmega328)", "ATmega328p", "arduino", 57600, 30720) );
		Boards->Add( gcnew ArduinoBoard("Nano (ATmega168)", "ATmega168", "arduino", 19200, 14336) );
		Boards->Add( gcnew ArduinoBoard("Ethernet", "ATmega328p", "arduino", 115200, 32256) );
		Boards->Add( gcnew ArduinoBoard("BT (ATmega328)", "ATmega328p", "arduino", 19200, 28672) );
		Boards->Add( gcnew ArduinoBoard("BT (ATmega168)", "ATmega168", "arduino", 19200, 14336) );
		return Boards;
	}

}