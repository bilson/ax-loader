#pragma once

/*
    AX Loader. Upload compiled sketches to an Arduino Board.
    Copyright (C) 2013 Jos� Andr�s Garc�a S�enz.

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

namespace AXLoader
{

	ref class ArduinoBoard
	{

	public:

		String^ Name;
		String^ MicroController;
		String^ Programmer;
		int BaudRate;
		int MaxSize;

		ArduinoBoard(String^ name, String^ microController, String^ programmer, int baudRate, int maxSize);
		ArduinoBoard(void);

	};

}