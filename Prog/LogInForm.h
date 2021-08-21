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
	/// —водка дл€ LogInForm
	/// </summary>
	public ref class LogInForm : public System::Windows::Forms::Form
	{
	public:
		LogInForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		LogInForm(System::Windows::Forms::Form^ mainMenu)
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
		~LogInForm()
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
	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonConfirmBirthday;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerBirthday;
	private: System::Windows::Forms::Button^ buttonLogIn;

	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxSurname;
	private: System::Windows::Forms::Button^ buttonConfirmSurname;
	private: System::Windows::Forms::Label^ labelStatus;
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
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonConfirmBirthday = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->buttonLogIn = (gcnew System::Windows::Forms::Button());
			this->maskedTextBoxSurname = (gcnew System::Windows::Forms::MaskedTextBox());
			this->buttonConfirmSurname = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
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
			this->menuStrip1->Size = System::Drawing::Size(401, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// оѕрограммеToolStripMenuItem
			// 
			this->оѕрограммеToolStripMenuItem->Name = L"оѕрограммеToolStripMenuItem";
			this->оѕрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оѕрограммеToolStripMenuItem->Text = L"ќ программе";
			this->оѕрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogInForm::оѕрограммеToolStripMenuItem_Click);
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
			this->выйти¬√лавноећенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogInForm::выйти¬√лавноећенюToolStripMenuItem_Click);
			// 
			// выход»зѕрограммыToolStripMenuItem
			// 
			this->выход»зѕрограммыToolStripMenuItem->Name = L"выход»зѕрограммыToolStripMenuItem";
			this->выход»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->выход»зѕрограммыToolStripMenuItem->Text = L"¬ыход из программы";
			this->выход»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &LogInForm::выход»зѕрограммыToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->buttonCorrection);
			this->groupBox2->Controls->Add(this->buttonContinue);
			this->groupBox2->Location = System::Drawing::Point(12, 184);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(375, 67);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L" оррекци€/продолжение работы";
			// 
			// buttonCorrection
			// 
			this->buttonCorrection->Location = System::Drawing::Point(255, 23);
			this->buttonCorrection->Name = L"buttonCorrection";
			this->buttonCorrection->Size = System::Drawing::Size(100, 30);
			this->buttonCorrection->TabIndex = 6;
			this->buttonCorrection->Text = L" оррекци€";
			this->buttonCorrection->UseVisualStyleBackColor = true;
			this->buttonCorrection->Click += gcnew System::EventHandler(this, &LogInForm::buttonCorrection_Click);
			// 
			// buttonContinue
			// 
			this->buttonContinue->Enabled = false;
			this->buttonContinue->Location = System::Drawing::Point(21, 23);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(100, 30);
			this->buttonContinue->TabIndex = 5;
			this->buttonContinue->Text = L"ѕродолжить";
			this->buttonContinue->UseVisualStyleBackColor = true;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &LogInForm::buttonContinue_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->buttonConfirmBirthday);
			this->groupBox1->Controls->Add(this->dateTimePickerBirthday);
			this->groupBox1->Controls->Add(this->buttonLogIn);
			this->groupBox1->Controls->Add(this->maskedTextBoxSurname);
			this->groupBox1->Controls->Add(this->buttonConfirmSurname);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(375, 132);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ƒанные пользовател€";
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(184, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 12);
			this->label2->TabIndex = 15;
			this->label2->Text = L"ƒата рождени€";
			// 
			// buttonConfirmBirthday
			// 
			this->buttonConfirmBirthday->Location = System::Drawing::Point(6, 62);
			this->buttonConfirmBirthday->Name = L"buttonConfirmBirthday";
			this->buttonConfirmBirthday->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmBirthday->TabIndex = 3;
			this->buttonConfirmBirthday->Text = L"ѕодтвердить";
			this->buttonConfirmBirthday->UseVisualStyleBackColor = true;
			this->buttonConfirmBirthday->Click += gcnew System::EventHandler(this, &LogInForm::buttonConfirmBirthday_Click);
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(111, 64);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(224, 20);
			this->dateTimePickerBirthday->TabIndex = 2;
			// 
			// buttonLogIn
			// 
			this->buttonLogIn->Location = System::Drawing::Point(21, 99);
			this->buttonLogIn->Name = L"buttonLogIn";
			this->buttonLogIn->Size = System::Drawing::Size(334, 23);
			this->buttonLogIn->TabIndex = 4;
			this->buttonLogIn->Text = L"јвторизаци€";
			this->buttonLogIn->UseVisualStyleBackColor = true;
			this->buttonLogIn->Click += gcnew System::EventHandler(this, &LogInForm::buttonLogIn_Click);
			// 
			// maskedTextBoxSurname
			// 
			this->maskedTextBoxSurname->Location = System::Drawing::Point(111, 32);
			this->maskedTextBoxSurname->Name = L"maskedTextBoxSurname";
			this->maskedTextBoxSurname->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxSurname->TabIndex = 0;
			this->maskedTextBoxSurname->Text = L"¬ведите ‘амилию";
			this->maskedTextBoxSurname->Click += gcnew System::EventHandler(this, &LogInForm::maskedTextBoxSurname_Click);
			// 
			// buttonConfirmSurname
			// 
			this->buttonConfirmSurname->Location = System::Drawing::Point(6, 31);
			this->buttonConfirmSurname->Name = L"buttonConfirmSurname";
			this->buttonConfirmSurname->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmSurname->TabIndex = 1;
			this->buttonConfirmSurname->Text = L"ѕодтвердить";
			this->buttonConfirmSurname->UseVisualStyleBackColor = true;
			this->buttonConfirmSurname->Click += gcnew System::EventHandler(this, &LogInForm::buttonConfirmSurname_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->ForeColor = System::Drawing::Color::Lime;
			this->labelStatus->Location = System::Drawing::Point(103, 162);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(0, 13);
			this->labelStatus->TabIndex = 22;
			// 
			// LogInForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 263);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(417, 302);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(417, 302);
			this->Name = L"LogInForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"јвторизаци€";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &LogInForm::LogInForm_HelpButtonClicked);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LogInForm::LogInForm_FormClosing);
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
	private: bool birthdayConfirmed = false;
	private: bool passwordConfirmed = false;
	private: System::Void LogInForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void выйти¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выход»зѕрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmSurname_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmBirthday_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonLogIn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCorrection_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonContinue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxSurname_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void оѕрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void LogInForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
