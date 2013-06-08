#pragma once

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
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AXLoader {

	ref class AboutForm : public Form
	{

	public:

		AboutForm(void);

	protected:

		~AboutForm();

	private:

		System::Windows::Forms::Label^ IconImage;
		System::Windows::Forms::Label^ TitleLabel;
		System::Windows::Forms::Label^ VersionLabel;
		System::Windows::Forms::Label^ CopyrightLabel;
		System::Windows::Forms::Label^ AutorLabel;
		System::Windows::Forms::Label^ LicenseImage;
		System::Windows::Forms::Label^ MailLabel;
		System::Windows::Forms::GroupBox^ GroupBox;
		System::Windows::Forms::LinkLabel^  DesignerLinkLabel;
		System::Windows::Forms::Label^  IconDesignerLabel;
		System::Windows::Forms::ColorDialog^  colorDialog1;
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->IconImage = (gcnew System::Windows::Forms::Label());
			this->TitleLabel = (gcnew System::Windows::Forms::Label());
			this->VersionLabel = (gcnew System::Windows::Forms::Label());
			this->CopyrightLabel = (gcnew System::Windows::Forms::Label());
			this->AutorLabel = (gcnew System::Windows::Forms::Label());
			this->LicenseImage = (gcnew System::Windows::Forms::Label());
			this->MailLabel = (gcnew System::Windows::Forms::Label());
			this->GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DesignerLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->IconDesignerLabel = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->GroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// IconImage
			// 
			this->IconImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"IconImage.Image")));
			this->IconImage->Location = System::Drawing::Point(12, -1);
			this->IconImage->Name = L"IconImage";
			this->IconImage->Size = System::Drawing::Size(109, 119);
			this->IconImage->TabIndex = 0;
			// 
			// TitleLabel
			// 
			this->TitleLabel->AutoSize = true;
			this->TitleLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TitleLabel->Location = System::Drawing::Point(127, 9);
			this->TitleLabel->Name = L"TitleLabel";
			this->TitleLabel->Size = System::Drawing::Size(104, 25);
			this->TitleLabel->TabIndex = 1;
			this->TitleLabel->Text = L"AX Loader";
			// 
			// VersionLabel
			// 
			this->VersionLabel->AutoSize = true;
			this->VersionLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->VersionLabel->Location = System::Drawing::Point(7, 15);
			this->VersionLabel->Name = L"VersionLabel";
			this->VersionLabel->Size = System::Drawing::Size(110, 17);
			this->VersionLabel->TabIndex = 2;
			this->VersionLabel->Text = L"Version 1.0 Alpha";
			// 
			// CopyrightLabel
			// 
			this->CopyrightLabel->AutoSize = true;
			this->CopyrightLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CopyrightLabel->Location = System::Drawing::Point(7, 35);
			this->CopyrightLabel->Name = L"CopyrightLabel";
			this->CopyrightLabel->Size = System::Drawing::Size(113, 17);
			this->CopyrightLabel->TabIndex = 3;
			this->CopyrightLabel->Text = L"Copyright © 2013";
			// 
			// AutorLabel
			// 
			this->AutorLabel->AutoSize = true;
			this->AutorLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AutorLabel->Location = System::Drawing::Point(7, 55);
			this->AutorLabel->Name = L"AutorLabel";
			this->AutorLabel->Size = System::Drawing::Size(158, 17);
			this->AutorLabel->TabIndex = 7;
			this->AutorLabel->Text = L"José Andrés García Sáenz";
			// 
			// LicenseImage
			// 
			this->LicenseImage->AccessibleDescription = L"";
			this->LicenseImage->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"LicenseImage.Image")));
			this->LicenseImage->Location = System::Drawing::Point(12, 108);
			this->LicenseImage->Name = L"LicenseImage";
			this->LicenseImage->Size = System::Drawing::Size(105, 67);
			this->LicenseImage->TabIndex = 8;
			this->LicenseImage->Tag = L"";
			this->LicenseImage->Click += gcnew System::EventHandler(this, &AboutForm::LicenseImage_Click);
			// 
			// MailLabel
			// 
			this->MailLabel->AutoSize = true;
			this->MailLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MailLabel->Location = System::Drawing::Point(7, 75);
			this->MailLabel->Name = L"MailLabel";
			this->MailLabel->Size = System::Drawing::Size(150, 17);
			this->MailLabel->TabIndex = 9;
			this->MailLabel->Text = L"<jags9415@gmail.com>";
			// 
			// GroupBox
			// 
			this->GroupBox->Controls->Add(this->DesignerLinkLabel);
			this->GroupBox->Controls->Add(this->IconDesignerLabel);
			this->GroupBox->Controls->Add(this->VersionLabel);
			this->GroupBox->Controls->Add(this->MailLabel);
			this->GroupBox->Controls->Add(this->CopyrightLabel);
			this->GroupBox->Controls->Add(this->AutorLabel);
			this->GroupBox->Location = System::Drawing::Point(132, 36);
			this->GroupBox->MaximumSize = System::Drawing::Size(176, 129);
			this->GroupBox->MinimumSize = System::Drawing::Size(176, 129);
			this->GroupBox->Name = L"GroupBox";
			this->GroupBox->Size = System::Drawing::Size(176, 129);
			this->GroupBox->TabIndex = 10;
			this->GroupBox->TabStop = false;
			// 
			// DesignerLinkLabel
			// 
			this->DesignerLinkLabel->AutoSize = true;
			this->DesignerLinkLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DesignerLinkLabel->Location = System::Drawing::Point(110, 105);
			this->DesignerLinkLabel->Name = L"DesignerLinkLabel";
			this->DesignerLinkLabel->Size = System::Drawing::Size(68, 17);
			this->DesignerLinkLabel->TabIndex = 11;
			this->DesignerLinkLabel->TabStop = true;
			this->DesignerLinkLabel->Text = L"acidrums4";
			this->DesignerLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::DesignerLinkLabel_LinkClicked);
			// 
			// IconDesignerLabel
			// 
			this->IconDesignerLabel->AutoSize = true;
			this->IconDesignerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->IconDesignerLabel->Location = System::Drawing::Point(7, 105);
			this->IconDesignerLabel->Name = L"IconDesignerLabel";
			this->IconDesignerLabel->Size = System::Drawing::Size(112, 17);
			this->IconDesignerLabel->TabIndex = 10;
			this->IconDesignerLabel->Text = L"Icon designed by ";
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 174);
			this->Controls->Add(this->GroupBox);
			this->Controls->Add(this->LicenseImage);
			this->Controls->Add(this->TitleLabel);
			this->Controls->Add(this->IconImage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AboutForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->GroupBox->ResumeLayout(false);
			this->GroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		
		Void LicenseImage_Click(Object^ sender, EventArgs^ e);
		Void DesignerLinkLabel_LinkClicked(Object^ sender, LinkLabelLinkClickedEventArgs^ e);
};

}
