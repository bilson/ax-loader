#include "stdafx.h"
#include "MainForm.h"
#include "AboutForm.h"

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

namespace AXLoader
{

	/// <summary>
	/// Initializes a new instance of the <see cref="MainForm"/> class.
	/// </summary>
	MainForm::MainForm(void)
	{
		this->InitializeComponent();
		this->Loader = gcnew AXLoader();
		this->FillBoardsComboBox();
		this->FillPortsComboBox();
		this->Loader->SetBoard( (String^) BoardsComboBox->SelectedItem );
		this->Loader->SetSerialPort( (String^) this->PortsComboBox->SelectedItem );
		this->CheckFiles();
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="MainForm"/> class.
	/// </summary>
	MainForm::~MainForm()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// Checks if the files needed to upload the hex file exist.
	/// </summary>
	Void MainForm::CheckFiles(void)
	{
		array<String^>^ FilesNeeded = {"avrdude.exe", "avrdude.conf", "libusb0.dll"};
		FileInfo^ File;

		for each (String^ f in FilesNeeded)
		{
			File = gcnew FileInfo(f);
			if (!File->Exists)
			{
				MessageBox::Show("File \"" + f + "\" not found. Without this file the program may not work properly.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}

	/// <summary>
	/// Fills the boards combo box.
	/// </summary>
	Void MainForm::FillBoardsComboBox(void)
	{
		this->BoardsComboBox->Items->Clear();
		this->BoardsComboBox->Items->AddRange( AXLoader::GetBoards() );
		this->BoardsComboBox->SelectedIndex = 0;
	}

	/// <summary>
	/// Fills the ports combo box.
	/// </summary>
	Void MainForm::FillPortsComboBox(void)
	{
		array<String^>^ Ports = SerialPort::GetPortNames();
		String^ ArduinoPort = this->Loader->SearchArduino();
		String^ SelectedPort = (String^) this->PortsComboBox->SelectedItem;
		this->PortsComboBox->Items->Clear();

		if (Ports->Length > 0)
		{
			this->PortsComboBox->Items->AddRange(Ports);
			if ( !String::IsNullOrEmpty(SelectedPort) && this->PortsComboBox->Items->Contains(SelectedPort) )
			{
				this->PortsComboBox->SelectedItem = SelectedPort;
			}
			else if ( !String::IsNullOrEmpty(ArduinoPort) )
			{
				this->PortsComboBox->SelectedItem = ArduinoPort;
			}
			else
			{
				this->PortsComboBox->SelectedIndex = 0;
			}
		}
		else
		{
			this->PortsComboBox->Items->Add("None");
			this->PortsComboBox->SelectedIndex = 0;
		}
		this->Loader->SetSerialPort( (String^) this->PortsComboBox->SelectedItem );
	}

	/// <summary>
	/// Initialize the process of uploading the hex file.
	/// </summary>
	/// <returns>The code returned by avrdude.</returns>
	int MainForm::Upload(void)
	{
		this->Loader->CheckParameters();
		this->ToolStripStatusLabel->Text = "Uploading...";
		this->Refresh();
		int ExitCode = this->Loader->UploadTarget();
		this->Loader->WriteLog("Log.txt");
		Sleep(1000);
		this->FillPortsComboBox();
		return ExitCode;
	}

	/// <summary>
	/// Executed when click on the open file button.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::OpenFileButton_Click(Object^  sender, EventArgs^  e)
	{
		this->OpenFileDialog->ShowDialog();
		String^ FileName = this->OpenFileDialog->FileName;

		if ( !String::IsNullOrEmpty(FileName) )
		{
			this->TargetTextBox->Text = FileName;
		}
	}

	/// <summary>
	/// Executed when click on the upload button.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::UploadButton_Click(Object^  sender, EventArgs^  e)
	{
		try
		{
			this->UploadButton->Enabled = false;
			if (Upload() == 0)
			{
				this->ToolStripStatusLabel->Text = "Uploaded Successfully.";
			}
			else
			{
				this->ToolStripStatusLabel->Text = "Upload Failed.";
			}
		}
		catch (Exception^ e)
		{
			this->ToolStripStatusLabel->Text = e->Message;
		}
		finally
		{
			this->UploadButton->Enabled = true;
		}
	}

	/// <summary>
	/// Executed when click on the about button.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::AboutButton_Click(Object^  sender, EventArgs^  e)
	{
		AboutForm^ About = gcnew AboutForm();
		About->ShowDialog();
	}

	/// <summary>
	/// Executed when the user changes the selected value in the boards combo box.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::BoardsComboBox_SelectionChangeCommitted(Object^ sender, EventArgs^ e)
	{
		this->Loader->SetBoard( (String^) BoardsComboBox->SelectedItem );
	}

	/// <summary>
	/// Executed when the user changes the selected value in the serial ports combo box.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::PortsComboBox_SelectionChangeCommitted(Object^ sender, EventArgs^ e)
	{
		this->Loader->SetSerialPort( (String^) this->PortsComboBox->SelectedItem );
	}

	/// <summary>
	/// Executed when the serial port combo box is dropped down.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::PortsComboBox_DropDown(Object^ sender, EventArgs^ e)
	{
		this->FillPortsComboBox();
	}

	/// <summary>
	/// Executed when the user changes the selected value in the target text box.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void MainForm::TargetTextBox_TextChanged(Object^ sender, EventArgs^ e)
	{
		this->Loader->SetTarget( this->TargetTextBox->Text );
	}

	Void MainForm::MainForm_DragEnter(Object^  sender, DragEventArgs^  e)
	{
		if ( e->Data->GetDataPresent(DataFormats::FileDrop) )
		{
			e->Effect = DragDropEffects::Copy;
		}
		else
		{
			e->Effect = DragDropEffects::None;
		}
	}

	Void MainForm::MainForm_DragDrop(Object^  sender, DragEventArgs^  e)
	{
		array<String^>^ files = (array<String^>^) e->Data->GetData(DataFormats::FileDrop);
		if (files->Length > 0)
		{
			this->TargetTextBox->Text = files[0];
		}
	}


}