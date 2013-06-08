#include "stdafx.h"
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

using namespace System::Diagnostics;

namespace AXLoader
{

	/// <summary>
	/// Initialize an instance of the <see cref="AboutForm"/> class.
	/// </summary>
	AboutForm::AboutForm(void)
	{
		InitializeComponent();
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="AboutForm"/> class.
	/// </summary>
	AboutForm::~AboutForm()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// Executed when click on the License logo.
	/// </summary>
	/// <param name="sender">The sender of the event.</param>
	/// <param name="e">The event arguments.</param>
	Void AboutForm::LicenseImage_Click(Object^ sender, EventArgs^ e)
	{
		Process::Start( "http://www.gnu.org/licenses/" );
	}

}