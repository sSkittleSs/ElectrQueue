#pragma once
#include "MainMenuForm.h"
#include "Users.h"

namespace Prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CheckPassForm
	/// </summary>
	public ref class CheckPassForm : public System::Windows::Forms::Form
	{
	public:
		CheckPassForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		CheckPassForm(System::Windows::Forms::Form^ owner, bool* flag, Users* user)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->owner = owner;
			correctPassword = gcnew System::String(user->password.c_str());
			correct = flag;
			this->labelText->Text = "Введите пароль от аккаунта " + gcnew System::String(user->surnameNP.c_str());
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CheckPassForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ owner;
	private: System::Windows::Forms::Label^ labelText;
	protected:

	private: System::Windows::Forms::TextBox^ textBoxPassword;
	private: System::Windows::Forms::PictureBox^ pictureBoxEye;


	private: System::Windows::Forms::Button^ buttonConfirmPassword;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CheckPassForm::typeid));
			this->labelText = (gcnew System::Windows::Forms::Label());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxEye = (gcnew System::Windows::Forms::PictureBox());
			this->buttonConfirmPassword = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxEye))->BeginInit();
			this->SuspendLayout();
			// 
			// labelText
			// 
			this->labelText->AutoSize = true;
			this->labelText->Location = System::Drawing::Point(41, 9);
			this->labelText->Name = L"labelText";
			this->labelText->Size = System::Drawing::Size(154, 13);
			this->labelText->TabIndex = 0;
			this->labelText->Text = L"Введите пароль от аккаунта ";
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(12, 34);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = System::Drawing::Size(292, 20);
			this->textBoxPassword->TabIndex = 1;
			this->textBoxPassword->Text = L"Введите пароль";
			this->textBoxPassword->Click += gcnew System::EventHandler(this, &CheckPassForm::textBoxPassword_Click);
			// 
			// pictureBoxEye
			// 
			this->pictureBoxEye->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxEye.BackgroundImage")));
			this->pictureBoxEye->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxEye->Location = System::Drawing::Point(304, 26);
			this->pictureBoxEye->Name = L"pictureBoxEye";
			this->pictureBoxEye->Size = System::Drawing::Size(36, 36);
			this->pictureBoxEye->TabIndex = 2;
			this->pictureBoxEye->TabStop = false;
			this->pictureBoxEye->Click += gcnew System::EventHandler(this, &CheckPassForm::pictureBoxEye_Click);
			this->pictureBoxEye->MouseEnter += gcnew System::EventHandler(this, &CheckPassForm::pictureBoxEye_MouseEnter);
			this->pictureBoxEye->MouseLeave += gcnew System::EventHandler(this, &CheckPassForm::pictureBoxEye_MouseLeave);
			// 
			// buttonConfirmPassword
			// 
			this->buttonConfirmPassword->Location = System::Drawing::Point(57, 60);
			this->buttonConfirmPassword->Name = L"buttonConfirmPassword";
			this->buttonConfirmPassword->Size = System::Drawing::Size(217, 24);
			this->buttonConfirmPassword->TabIndex = 3;
			this->buttonConfirmPassword->Text = L"Подтвердить";
			this->buttonConfirmPassword->UseVisualStyleBackColor = true;
			this->buttonConfirmPassword->Click += gcnew System::EventHandler(this, &CheckPassForm::buttonConfirmPassword_Click);
			// 
			// CheckPassForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(350, 93);
			this->Controls->Add(this->buttonConfirmPassword);
			this->Controls->Add(this->pictureBoxEye);
			this->Controls->Add(this->textBoxPassword);
			this->Controls->Add(this->labelText);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(366, 132);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(366, 132);
			this->Name = L"CheckPassForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Проверка пароля";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxEye))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool eye = true;
	private: bool* correct = false;
	private: String^ correctPassword = "";
	private: System::Void textBoxPassword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxEye_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxEye_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxEye_MouseLeave(System::Object^ sender, System::EventArgs^ e);
};
}
