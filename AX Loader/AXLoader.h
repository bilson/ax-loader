#pragma once
#include "ArduinoBoard.h"

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

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

namespace AXLoader
{

	ref class AXLoader
	{

	private:

		Process^ UploadProcess;
		ArduinoBoard^ Board;
		String^ Port;
		String^ Target;
		String^ Output;
		static List<ArduinoBoard^>^ Boards = InitializeBoards();

	public:

		AXLoader(void);
		Void CheckParameters(void);
		String^ GetUploadOutput(void);
		String^ SearchArduino(void);
		void SetBoard(String^ boardName);
		void SetTarget(String^ target);
		void SetSerialPort(String^ port);
		int UploadTarget(void);
		void WriteLog(String^ fileName);
		static array<String^>^ GetBoards(void);

	private:
		
		void ResetBoard(void);
		String^ GenerateArguments(void);
		static List<ArduinoBoard^>^ InitializeBoards(void);

	};

}

