#pragma once
#include "MainMenuForm.h"

namespace Prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� PersonalCabinetForm
	/// </summary>
	public ref class PersonalCabinetForm : public System::Windows::Forms::Form
	{
	public:
		PersonalCabinetForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
		PersonalCabinetForm(System::Windows::Forms::Form^ mainMenu)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			this->mainMenu = mainMenu;
			setupData();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~PersonalCabinetForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ mainMenu;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ labelInfoAccount;
	private: System::Windows::Forms::Label^ labelSurnameNP;

	private: System::Windows::Forms::Label^ labelSurname;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelProzv;
	private: System::Windows::Forms::Label^ labelBirthday;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Button^ buttonGetAllRecords;
	private: System::Windows::Forms::Button^ buttonGetRecord;
	private: System::Windows::Forms::Label^ labelInfoSurnameNP;








	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelInfoAccount = (gcnew System::Windows::Forms::Label());
			this->labelSurnameNP = (gcnew System::Windows::Forms::Label());
			this->labelSurname = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelProzv = (gcnew System::Windows::Forms::Label());
			this->labelBirthday = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->buttonGetAllRecords = (gcnew System::Windows::Forms::Button());
			this->buttonGetRecord = (gcnew System::Windows::Forms::Button());
			this->labelInfoSurnameNP = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����������ToolStripMenuItem,
					this->�����ToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(275, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &PersonalCabinetForm::����������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem1
			// 
			this->�����ToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�����������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem
			});
			this->�����ToolStripMenuItem1->Name = L"�����ToolStripMenuItem1";
			this->�����ToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem1->Text = L"�����";
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->�����������������ToolStripMenuItem->Text = L"����� � ������� ����";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &PersonalCabinetForm::�����������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->����������������ToolStripMenuItem->Text = L"����� �� ���������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &PersonalCabinetForm::����������������ToolStripMenuItem_Click);
			// 
			// labelInfoAccount
			// 
			this->labelInfoAccount->AutoSize = true;
			this->labelInfoAccount->Location = System::Drawing::Point(12, 27);
			this->labelInfoAccount->Name = L"labelInfoAccount";
			this->labelInfoAccount->Size = System::Drawing::Size(134, 13);
			this->labelInfoAccount->TabIndex = 5;
			this->labelInfoAccount->Text = L"���������� �� ������� ";
			// 
			// labelSurnameNP
			// 
			this->labelSurnameNP->AutoSize = true;
			this->labelSurnameNP->Location = System::Drawing::Point(12, 57);
			this->labelSurnameNP->Name = L"labelSurnameNP";
			this->labelSurnameNP->Size = System::Drawing::Size(87, 13);
			this->labelSurnameNP->TabIndex = 6;
			this->labelSurnameNP->Text = L"������� �.�.: ";
			// 
			// labelSurname
			// 
			this->labelSurname->AutoSize = true;
			this->labelSurname->Location = System::Drawing::Point(12, 73);
			this->labelSurname->Name = L"labelSurname";
			this->labelSurname->Size = System::Drawing::Size(62, 13);
			this->labelSurname->TabIndex = 7;
			this->labelSurname->Text = L"�������: ";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(12, 89);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(35, 13);
			this->labelName->TabIndex = 8;
			this->labelName->Text = L"���: ";
			// 
			// labelProzv
			// 
			this->labelProzv->AutoSize = true;
			this->labelProzv->Location = System::Drawing::Point(12, 105);
			this->labelProzv->Name = L"labelProzv";
			this->labelProzv->Size = System::Drawing::Size(60, 13);
			this->labelProzv->TabIndex = 9;
			this->labelProzv->Text = L"��������: ";
			// 
			// labelBirthday
			// 
			this->labelBirthday->AutoSize = true;
			this->labelBirthday->Location = System::Drawing::Point(12, 121);
			this->labelBirthday->Name = L"labelBirthday";
			this->labelBirthday->Size = System::Drawing::Size(92, 13);
			this->labelBirthday->TabIndex = 10;
			this->labelBirthday->Text = L"���� ��������: ";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(12, 137);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(114, 13);
			this->labelPassword->TabIndex = 11;
			this->labelPassword->Text = L"������ �� ��������: ";
			// 
			// buttonGetAllRecords
			// 
			this->buttonGetAllRecords->Location = System::Drawing::Point(28, 168);
			this->buttonGetAllRecords->Name = L"buttonGetAllRecords";
			this->buttonGetAllRecords->Size = System::Drawing::Size(216, 23);
			this->buttonGetAllRecords->TabIndex = 12;
			this->buttonGetAllRecords->Text = L"�������� ���������� � ���� �������";
			this->buttonGetAllRecords->UseVisualStyleBackColor = true;
			this->buttonGetAllRecords->Click += gcnew System::EventHandler(this, &PersonalCabinetForm::buttonGetAllRecords_Click);
			// 
			// buttonGetRecord
			// 
			this->buttonGetRecord->Location = System::Drawing::Point(28, 197);
			this->buttonGetRecord->Name = L"buttonGetRecord";
			this->buttonGetRecord->Size = System::Drawing::Size(216, 23);
			this->buttonGetRecord->TabIndex = 13;
			this->buttonGetRecord->Text = L"��������� ������ � ����� (�� �����)";
			this->buttonGetRecord->UseVisualStyleBackColor = true;
			this->buttonGetRecord->Click += gcnew System::EventHandler(this, &PersonalCabinetForm::buttonGetRecord_Click);
			// 
			// labelInfoSurnameNP
			// 
			this->labelInfoSurnameNP->AutoSize = true;
			this->labelInfoSurnameNP->Location = System::Drawing::Point(141, 27);
			this->labelInfoSurnameNP->Name = L"labelInfoSurnameNP";
			this->labelInfoSurnameNP->Size = System::Drawing::Size(0, 13);
			this->labelInfoSurnameNP->TabIndex = 14;
			// 
			// PersonalCabinetForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(275, 232);
			this->Controls->Add(this->labelInfoSurnameNP);
			this->Controls->Add(this->buttonGetRecord);
			this->Controls->Add(this->buttonGetAllRecords);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelBirthday);
			this->Controls->Add(this->labelProzv);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelSurname);
			this->Controls->Add(this->labelSurnameNP);
			this->Controls->Add(this->labelInfoAccount);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(291, 271);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(291, 271);
			this->Name = L"PersonalCabinetForm";
			this->Text = L"������ �������";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &PersonalCabinetForm::PersonalCabinetForm_HelpButtonClicked);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PersonalCabinetForm::PersonalCabinetForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool toForm = false;
	private: System::Void setupData();
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonGetAllRecords_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonGetRecord_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PersonalCabinetForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void PersonalCabinetForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
