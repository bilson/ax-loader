#pragma once
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

using namespace System;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace AXLoader {

	ref class MainForm : public Form
	{

	public:
		
		MainForm(void);

	protected:

		~MainForm();

	private:

		System::Windows::Forms::ComboBox^  BoardsComboBox;
		System::Windows::Forms::ComboBox^  PortsComboBox;
		System::Windows::Forms::Label^  BoardsLabel;
		System::Windows::Forms::Label^  PortsLabel;
		System::Windows::Forms::Label^  TargetLabel;
		System::Windows::Forms::OpenFileDialog^  OpenFileDialog;
		System::Windows::Forms::TextBox^  TargetTextBox;
		System::Windows::Forms::Button^  OpenFileButton;
		System::Windows::Forms::StatusStrip^  StatusStrip;
		System::Windows::Forms::ToolStripStatusLabel^  ToolStripStatusLabel;
		System::Windows::Forms::Button^  UploadButton;
		System::Windows::Forms::Button^  AboutButton;
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->BoardsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->PortsComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->BoardsLabel = (gcnew System::Windows::Forms::Label());
			this->PortsLabel = (gcnew System::Windows::Forms::Label());
			this->TargetLabel = (gcnew System::Windows::Forms::Label());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->TargetTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OpenFileButton = (gcnew System::Windows::Forms::Button());
			this->StatusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->ToolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->UploadButton = (gcnew System::Windows::Forms::Button());
			this->AboutButton = (gcnew System::Windows::Forms::Button());
			this->StatusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// BoardsComboBox
			// 
			this->BoardsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->BoardsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoardsComboBox->FormattingEnabled = true;
			this->BoardsComboBox->Location = System::Drawing::Point(12, 34);
			this->BoardsComboBox->Name = L"BoardsComboBox";
			this->BoardsComboBox->Size = System::Drawing::Size(240, 24);
			this->BoardsComboBox->TabIndex = 1;
			this->BoardsComboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainForm::BoardsComboBox_SelectionChangeCommitted);
			// 
			// PortsComboBox
			// 
			this->PortsComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->PortsComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PortsComboBox->FormattingEnabled = true;
			this->PortsComboBox->Location = System::Drawing::Point(258, 34);
			this->PortsComboBox->Name = L"PortsComboBox";
			this->PortsComboBox->Size = System::Drawing::Size(121, 24);
			this->PortsComboBox->TabIndex = 2;
			this->PortsComboBox->DropDown += gcnew System::EventHandler(this, &MainForm::PortsComboBox_DropDown);
			this->PortsComboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &MainForm::PortsComboBox_SelectionChangeCommitted);
			// 
			// BoardsLabel
			// 
			this->BoardsLabel->AutoSize = true;
			this->BoardsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BoardsLabel->Location = System::Drawing::Point(12, 15);
			this->BoardsLabel->Name = L"BoardsLabel";
			this->BoardsLabel->Size = System::Drawing::Size(54, 16);
			this->BoardsLabel->TabIndex = 3;
			this->BoardsLabel->Text = L"Arduino";
			// 
			// PortsLabel
			// 
			this->PortsLabel->AutoSize = true;
			this->PortsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PortsLabel->Location = System::Drawing::Point(255, 15);
			this->PortsLabel->Name = L"PortsLabel";
			this->PortsLabel->Size = System::Drawing::Size(70, 16);
			this->PortsLabel->TabIndex = 4;
			this->PortsLabel->Text = L"Serial Port";
			// 
			// TargetLabel
			// 
			this->TargetLabel->AutoSize = true;
			this->TargetLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TargetLabel->Location = System::Drawing::Point(12, 69);
			this->TargetLabel->Name = L"TargetLabel";
			this->TargetLabel->Size = System::Drawing::Size(57, 16);
			this->TargetLabel->TabIndex = 5;
			this->TargetLabel->Text = L"Hex File";
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->Filter = L"Hex files (*.hex) | *.hex";
			// 
			// TargetTextBox
			// 
			this->TargetTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TargetTextBox->Location = System::Drawing::Point(12, 88);
			this->TargetTextBox->Name = L"TargetTextBox";
			this->TargetTextBox->Size = System::Drawing::Size(335, 22);
			this->TargetTextBox->TabIndex = 6;
			this->TargetTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::TargetTextBox_TextChanged);
			// 
			// OpenFileButton
			// 
			this->OpenFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->OpenFileButton->Location = System::Drawing::Point(353, 88);
			this->OpenFileButton->Name = L"OpenFileButton";
			this->OpenFileButton->Size = System::Drawing::Size(26, 23);
			this->OpenFileButton->TabIndex = 7;
			this->OpenFileButton->Text = L"...";
			this->OpenFileButton->UseVisualStyleBackColor = true;
			this->OpenFileButton->Click += gcnew System::EventHandler(this, &MainForm::OpenFileButton_Click);
			// 
			// StatusStrip
			// 
			this->StatusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ToolStripStatusLabel});
			this->StatusStrip->Location = System::Drawing::Point(0, 162);
			this->StatusStrip->Name = L"StatusStrip";
			this->StatusStrip->Size = System::Drawing::Size(394, 22);
			this->StatusStrip->SizingGrip = false;
			this->StatusStrip->TabIndex = 0;
			this->StatusStrip->Text = L"statusStrip";
			// 
			// ToolStripStatusLabel
			// 
			this->ToolStripStatusLabel->Name = L"ToolStripStatusLabel";
			this->ToolStripStatusLabel->Size = System::Drawing::Size(379, 17);
			this->ToolStripStatusLabel->Spring = true;
			this->ToolStripStatusLabel->Text = L"                                       ";
			this->ToolStripStatusLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// UploadButton
			// 
			this->UploadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->UploadButton->Location = System::Drawing::Point(91, 127);
			this->UploadButton->Name = L"UploadButton";
			this->UploadButton->Size = System::Drawing::Size(75, 23);
			this->UploadButton->TabIndex = 8;
			this->UploadButton->Text = L"Upload";
			this->UploadButton->UseVisualStyleBackColor = true;
			this->UploadButton->Click += gcnew System::EventHandler(this, &MainForm::UploadButton_Click);
			// 
			// AboutButton
			// 
			this->AboutButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AboutButton->Location = System::Drawing::Point(226, 127);
			this->AboutButton->Name = L"AboutButton";
			this->AboutButton->Size = System::Drawing::Size(75, 23);
			this->AboutButton->TabIndex = 9;
			this->AboutButton->Text = L"About";
			this->AboutButton->UseVisualStyleBackColor = true;
			this->AboutButton->Click += gcnew System::EventHandler(this, &MainForm::AboutButton_Click);
			// 
			// MainForm
			// 
			this->AcceptButton = this->UploadButton;
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(394, 184);
			this->Controls->Add(this->AboutButton);
			this->Controls->Add(this->UploadButton);
			this->Controls->Add(this->OpenFileButton);
			this->Controls->Add(this->TargetTextBox);
			this->Controls->Add(this->TargetLabel);
			this->Controls->Add(this->PortsLabel);
			this->Controls->Add(this->BoardsLabel);
			this->Controls->Add(this->PortsComboBox);
			this->Controls->Add(this->BoardsComboBox);
			this->Controls->Add(this->StatusStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(410, 223);
			this->MinimumSize = System::Drawing::Size(410, 223);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AX Loader";
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragEnter);
			this->StatusStrip->ResumeLayout(false);
			this->StatusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:

		AXLoader^ Loader;

		Void CheckFiles(void);
		Void FillBoardsComboBox(void);
		Void FillPortsComboBox(void);
		int Upload(void);
		
		Void OpenFileButton_Click(Object^ sender, EventArgs^ e);
		Void UploadButton_Click(Object^ sender, EventArgs^ e);
		Void AboutButton_Click(Object^  sender, EventArgs^  e);
		Void BoardsComboBox_SelectionChangeCommitted(Object^ sender, EventArgs^ e);
		Void PortsComboBox_SelectionChangeCommitted(Object^ sender, EventArgs^ e);
		Void PortsComboBox_DropDown(Object^ sender, EventArgs^ e);
		Void TargetTextBox_TextChanged(Object^ sender, System::EventArgs^ e);
		Void MainForm_DragEnter(Object^ sender, DragEventArgs^ e);
		Void MainForm_DragDrop(Object^ sender, DragEventArgs^ e);
};

}