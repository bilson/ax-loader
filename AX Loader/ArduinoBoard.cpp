#include "stdafx.h"
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

namespace AXLoader
{

	/// <summary>
	/// Initializes a new instance of the <see cref="ArduinoBoard"/> class.
	/// </summary>
	/// <param name="name">The name of the board.</param>
	/// <param name="microController">The microcontroller of the board.</param>
	/// <param name="programmer">The programmer used by avrdude.</param>
	/// <param name="baudRate">The baud rate used by avrdude.</param>
	/// <param name="maxSize">The maximum size for a compiled file.</param>
	ArduinoBoard::ArduinoBoard(String^ name, String^ microController, String^ programmer, int baudRate, int maxSize)
	{
		this->Name = name;
		this->MicroController = microController;
		this->Programmer = programmer;
		this->BaudRate = baudRate;
		this->MaxSize = maxSize;
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="ArduinoBoard"/> class.
	/// </summary>
	ArduinoBoard::ArduinoBoard(void)
	{
		this->Name = String::Empty;
		this->MicroController =String::Empty;
		this->Programmer = String::Empty;
		this->BaudRate = 0;
		this->MaxSize = 0;
	}

}