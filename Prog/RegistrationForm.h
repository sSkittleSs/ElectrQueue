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
	/// —водка дл€ RegistrationForm
	/// </summary>
	public ref class RegistrationForm : public System::Windows::Forms::Form
	{
	public:
		RegistrationForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		RegistrationForm(System::Windows::Forms::Form^ mainMenu)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->mainMenu = mainMenu;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~RegistrationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form^ mainMenu;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ToolStripMenuItem^ оѕрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ выйти¬√лавноећенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выход»зѕрограммыToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ buttonCorrection;

	private: System::Windows::Forms::Button^ buttonSaveUser;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonCreateUser;










	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxName;


	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxSurname;

	private: System::Windows::Forms::Button^ buttonConfirmName;

	private: System::Windows::Forms::Button^ buttonConfirmSurname;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxPassword;


	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxProzv;

	private: System::Windows::Forms::Button^ buttonConfirmPassword;

	private: System::Windows::Forms::Button^ buttonConfirmProzv;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonConfirmBirthday;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerBirthday;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->оѕрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйти¬√лавноећенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выход»зѕрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCorrection = (gcnew System::Windows::Forms::Button());
			this->buttonSaveUser = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmBirthday = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->maskedTextBoxPassword = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBoxProzv = (gcnew System::Windows::Forms::MaskedTextBox());
			this->buttonConfirmPassword = (gcnew System::Windows::Forms::Button());
			this->buttonConfirmProzv = (gcnew System::Windows::Forms::Button());
			this->buttonCreateUser = (gcnew System::Windows::Forms::Button());
			this->maskedTextBoxName = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBoxSurname = (gcnew System::Windows::Forms::MaskedTextBox());
			this->buttonConfirmName = (gcnew System::Windows::Forms::Button());
			this->buttonConfirmSurname = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->оѕрограммеToolStripMenuItem,
					this->выходToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(403, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// оѕрограммеToolStripMenuItem
			// 
			this->оѕрограммеToolStripMenuItem->Name = L"оѕрограммеToolStripMenuItem";
			this->оѕрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оѕрограммеToolStripMenuItem->Text = L"ќ программе";
			this->оѕрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &RegistrationForm::оѕрограммеToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem1
			// 
			this->выходToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выйти¬√лавноећенюToolStripMenuItem,
					this->выход»зѕрограммыToolStripMenuItem
			});
			this->выходToolStripMenuItem1->Name = L"выходToolStripMenuItem1";
			this->выходToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem1->Text = L"¬ыход";
			// 
			// выйти¬√лавноећенюToolStripMenuItem
			// 
			this->выйти¬√лавноећенюToolStripMenuItem->Name = L"выйти¬√лавноећенюToolStripMenuItem";
			this->выйти¬√лавноећенюToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->выйти¬√лавноећенюToolStripMenuItem->Text = L"¬ыйти в главное меню";
			this->выйти¬√лавноећенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &RegistrationForm::выйти¬√лавноећенюToolStripMenuItem_Click);
			// 
			// выход»зѕрограммыToolStripMenuItem
			// 
			this->выход»зѕрограммыToolStripMenuItem->Name = L"выход»зѕрограммыToolStripMenuItem";
			this->выход»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->выход»зѕрограммыToolStripMenuItem->Text = L"¬ыход из программы";
			this->выход»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &RegistrationForm::выход»зѕрограммыToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->buttonCorrection);
			this->groupBox2->Controls->Add(this->buttonSaveUser);
			this->groupBox2->Location = System::Drawing::Point(12, 264);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(375, 67);
			this->groupBox2->TabIndex = 19;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"—охранение введенных данных";
			// 
			// buttonCorrection
			// 
			this->buttonCorrection->Location = System::Drawing::Point(255, 23);
			this->buttonCorrection->Name = L"buttonCorrection";
			this->buttonCorrection->Size = System::Drawing::Size(100, 30);
			this->buttonCorrection->TabIndex = 12;
			this->buttonCorrection->Text = L" оррекци€";
			this->buttonCorrection->UseVisualStyleBackColor = true;
			this->buttonCorrection->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonCorrection_Click);
			// 
			// buttonSaveUser
			// 
			this->buttonSaveUser->Enabled = false;
			this->buttonSaveUser->Location = System::Drawing::Point(21, 23);
			this->buttonSaveUser->Name = L"buttonSaveUser";
			this->buttonSaveUser->Size = System::Drawing::Size(100, 30);
			this->buttonSaveUser->TabIndex = 11;
			this->buttonSaveUser->Text = L"—охранить";
			this->buttonSaveUser->UseVisualStyleBackColor = true;
			this->buttonSaveUser->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonSaveUser_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->buttonConfirmBirthday);
			this->groupBox1->Controls->Add(this->dateTimePickerBirthday);
			this->groupBox1->Controls->Add(this->maskedTextBoxPassword);
			this->groupBox1->Controls->Add(this->maskedTextBoxProzv);
			this->groupBox1->Controls->Add(this->buttonConfirmPassword);
			this->groupBox1->Controls->Add(this->buttonConfirmProzv);
			this->groupBox1->Controls->Add(this->buttonCreateUser);
			this->groupBox1->Controls->Add(this->maskedTextBoxName);
			this->groupBox1->Controls->Add(this->maskedTextBoxSurname);
			this->groupBox1->Controls->Add(this->buttonConfirmName);
			this->groupBox1->Controls->Add(this->buttonConfirmSurname);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(375, 231);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ƒанные нового пользовател€";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(195, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 12);
			this->label5->TabIndex = 18;
			this->label5->Text = L"‘амили€";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(206, 84);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 12);
			this->label4->TabIndex = 17;
			this->label4->Text = L"»м€";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(195, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 12);
			this->label3->TabIndex = 16;
			this->label3->Text = L"ќтчество";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(184, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 12);
			this->label2->TabIndex = 15;
			this->label2->Text = L"ƒата рождени€";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(198, 180);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 12);
			this->label1->TabIndex = 14;
			this->label1->Text = L"ѕароль";
			// 
			// buttonConfirmBirthday
			// 
			this->buttonConfirmBirthday->Location = System::Drawing::Point(6, 126);
			this->buttonConfirmBirthday->Name = L"buttonConfirmBirthday";
			this->buttonConfirmBirthday->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmBirthday->TabIndex = 7;
			this->buttonConfirmBirthday->Text = L"ѕодтвердить";
			this->buttonConfirmBirthday->UseVisualStyleBackColor = true;
			this->buttonConfirmBirthday->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonConfirmBirthday_Click);
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(111, 128);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(224, 20);
			this->dateTimePickerBirthday->TabIndex = 6;
			// 
			// maskedTextBoxPassword
			// 
			this->maskedTextBoxPassword->Location = System::Drawing::Point(111, 160);
			this->maskedTextBoxPassword->Name = L"maskedTextBoxPassword";
			this->maskedTextBoxPassword->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxPassword->TabIndex = 8;
			this->maskedTextBoxPassword->Text = L"¬ведите пароль дл€ нового пользовател€";
			this->maskedTextBoxPassword->Click += gcnew System::EventHandler(this, &RegistrationForm::maskedTextBoxPassword_Click);
			// 
			// maskedTextBoxProzv
			// 
			this->maskedTextBoxProzv->Location = System::Drawing::Point(111, 96);
			this->maskedTextBoxProzv->Name = L"maskedTextBoxProzv";
			this->maskedTextBoxProzv->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxProzv->TabIndex = 4;
			this->maskedTextBoxProzv->Text = L"¬ведите ќтчество";
			this->maskedTextBoxProzv->Click += gcnew System::EventHandler(this, &RegistrationForm::maskedTextBoxProzv_Click);
			// 
			// buttonConfirmPassword
			// 
			this->buttonConfirmPassword->Location = System::Drawing::Point(6, 159);
			this->buttonConfirmPassword->Name = L"buttonConfirmPassword";
			this->buttonConfirmPassword->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmPassword->TabIndex = 9;
			this->buttonConfirmPassword->Text = L"ѕодтвердить";
			this->buttonConfirmPassword->UseVisualStyleBackColor = true;
			this->buttonConfirmPassword->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonConfirmPassword_Click);
			// 
			// buttonConfirmProzv
			// 
			this->buttonConfirmProzv->Location = System::Drawing::Point(6, 95);
			this->buttonConfirmProzv->Name = L"buttonConfirmProzv";
			this->buttonConfirmProzv->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmProzv->TabIndex = 5;
			this->buttonConfirmProzv->Text = L"ѕодтвердить";
			this->buttonConfirmProzv->UseVisualStyleBackColor = true;
			this->buttonConfirmProzv->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonConfirmProzv_Click);
			// 
			// buttonCreateUser
			// 
			this->buttonCreateUser->Location = System::Drawing::Point(21, 202);
			this->buttonCreateUser->Name = L"buttonCreateUser";
			this->buttonCreateUser->Size = System::Drawing::Size(334, 23);
			this->buttonCreateUser->TabIndex = 10;
			this->buttonCreateUser->Text = L"—оздать нового пользовател€";
			this->buttonCreateUser->UseVisualStyleBackColor = true;
			this->buttonCreateUser->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonCreateUser_Click);
			// 
			// maskedTextBoxName
			// 
			this->maskedTextBoxName->Location = System::Drawing::Point(111, 64);
			this->maskedTextBoxName->Name = L"maskedTextBoxName";
			this->maskedTextBoxName->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxName->TabIndex = 2;
			this->maskedTextBoxName->Text = L"¬ведите »м€";
			this->maskedTextBoxName->Click += gcnew System::EventHandler(this, &RegistrationForm::maskedTextBoxName_Click);
			// 
			// maskedTextBoxSurname
			// 
			this->maskedTextBoxSurname->Location = System::Drawing::Point(111, 32);
			this->maskedTextBoxSurname->Name = L"maskedTextBoxSurname";
			this->maskedTextBoxSurname->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxSurname->TabIndex = 0;
			this->maskedTextBoxSurname->Text = L"¬ведите ‘амилию";
			this->maskedTextBoxSurname->Click += gcnew System::EventHandler(this, &RegistrationForm::maskedTextBoxSurname_Click);
			// 
			// buttonConfirmName
			// 
			this->buttonConfirmName->Location = System::Drawing::Point(6, 63);
			this->buttonConfirmName->Name = L"buttonConfirmName";
			this->buttonConfirmName->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmName->TabIndex = 3;
			this->buttonConfirmName->Text = L"ѕодтвердить";
			this->buttonConfirmName->UseVisualStyleBackColor = true;
			this->buttonConfirmName->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonConfirmName_Click);
			// 
			// buttonConfirmSurname
			// 
			this->buttonConfirmSurname->Location = System::Drawing::Point(6, 31);
			this->buttonConfirmSurname->Name = L"buttonConfirmSurname";
			this->buttonConfirmSurname->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmSurname->TabIndex = 1;
			this->buttonConfirmSurname->Text = L"ѕодтвердить";
			this->buttonConfirmSurname->UseVisualStyleBackColor = true;
			this->buttonConfirmSurname->Click += gcnew System::EventHandler(this, &RegistrationForm::buttonConfirmSurname_Click);
			// 
			// RegistrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(403, 343);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(419, 382);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(419, 382);
			this->Name = L"RegistrationForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"–егистраци€";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &RegistrationForm::RegistrationForm_HelpButtonClicked);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RegistrationForm::RegistrationForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool toForm = false;
	private: bool surnameConfirmed = false;
	private: bool nameConfirmed = false;
	private: bool prozvConfirmed = false;
	private: bool birthdayConfirmed = false;
	private: bool passwordConfirmed = false;
	private: System::Void RegistrationForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void выйти¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выход»зѕрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmSurname_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmProzv_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmBirthday_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxSurname_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxProzv_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxPassword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCorrection_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonSaveUser_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCreateUser_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void оѕрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RegistrationForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
