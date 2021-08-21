#pragma once
#include <Windows.h>
#include <fstream>
#include "FunctionsConvert.h" // ���������� ������������ ���� � ��������� ����������� (std::string, System::String, char*).

/******����������� ��������� ����*******/
#include "AdminMainForm.h"
#include "CreateNewQueueForm.h"
#include "MainForm.h"
#include "OpenQueueFileForm.h"
#include "CheckPassForm.h"
#include "LogInForm.h"
#include "RegistrationForm.h"
#include "HelpForm.h"
#include "PersonalCabinetForm.h"
/***************************************/

#include "Queue.h"
#include "QueueData.h"
#include "FunctionsConvert.h"

namespace Prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/*Users* currUser;*/
	/// <summary>
	/// ������ ��� MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MainMenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//

			DateTime tod = DateTime::Today;
			if (tod.DayOfWeek == DayOfWeek::Monday)
				remove(ConvertStringToChar(Application::StartupPath + "\\users\\cancelLog.txt"));

			checkQueues();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	//private: Users* currentUser; //////////////////////////////////////////////////////////////////!!!!!!
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:




	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem1;
	private: System::Windows::Forms::Button^ buttonOpenQueueFile;
	private: System::Windows::Forms::Button^ buttonCreateNewQueue;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonExit;





	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::Timer^ timerCheck;

	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ labelCurrentUser;


	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonOpenQueueFile = (gcnew System::Windows::Forms::Button());
			this->buttonCreateNewQueue = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->timerCheck = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelCurrentUser = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->�����������ToolStripMenuItem,
					this->����������ToolStripMenuItem, this->����ToolStripMenuItem1, this->�����ToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(300, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->����ToolStripMenuItem,
					this->�����������ToolStripMenuItem, this->�����ToolStripMenuItem, this->�������������ToolStripMenuItem
			});
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->�����������ToolStripMenuItem->Text = L"�����������";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::����ToolStripMenuItem_Click);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->�����������ToolStripMenuItem->Text = L"�����������";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::�����������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Visible = false;
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::�����ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->�������������ToolStripMenuItem->Text = L"������ �������";
			this->�������������ToolStripMenuItem->Visible = false;
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::�������������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::����������ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem1
			// 
			this->����ToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem2,
					this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem1->Name = L"����ToolStripMenuItem1";
			this->����ToolStripMenuItem1->Size = System::Drawing::Size(56, 20);
			this->����ToolStripMenuItem1->Text = L"�����";
			// 
			// ����ToolStripMenuItem2
			// 
			this->����ToolStripMenuItem2->Name = L"����ToolStripMenuItem2";
			this->����ToolStripMenuItem2->Size = System::Drawing::Size(109, 22);
			this->����ToolStripMenuItem2->Text = L"����";
			this->����ToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainMenuForm::����ToolStripMenuItem2_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::�����ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem1
			// 
			this->�����ToolStripMenuItem1->Name = L"�����ToolStripMenuItem1";
			this->�����ToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem1->Text = L"�����";
			this->�����ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainMenuForm::�����ToolStripMenuItem1_Click);
			// 
			// buttonOpenQueueFile
			// 
			this->buttonOpenQueueFile->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOpenQueueFile->Location = System::Drawing::Point(13, 67);
			this->buttonOpenQueueFile->Name = L"buttonOpenQueueFile";
			this->buttonOpenQueueFile->Size = System::Drawing::Size(208, 39);
			this->buttonOpenQueueFile->TabIndex = 2;
			this->buttonOpenQueueFile->Text = L"������� ����";
			this->buttonOpenQueueFile->UseVisualStyleBackColor = true;
			this->buttonOpenQueueFile->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonOpenQueueFile_Click);
			// 
			// buttonCreateNewQueue
			// 
			this->buttonCreateNewQueue->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic));
			this->buttonCreateNewQueue->Location = System::Drawing::Point(13, 112);
			this->buttonCreateNewQueue->Name = L"buttonCreateNewQueue";
			this->buttonCreateNewQueue->Size = System::Drawing::Size(208, 39);
			this->buttonCreateNewQueue->TabIndex = 3;
			this->buttonCreateNewQueue->Text = L"������� ����� �������";
			this->buttonCreateNewQueue->UseVisualStyleBackColor = true;
			this->buttonCreateNewQueue->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonCreateNewQueue_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonContinue);
			this->groupBox1->Controls->Add(this->buttonExit);
			this->groupBox1->Controls->Add(this->buttonOpenQueueFile);
			this->groupBox1->Controls->Add(this->buttonCreateNewQueue);
			this->groupBox1->Location = System::Drawing::Point(32, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(234, 209);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"������� ����";
			// 
			// buttonContinue
			// 
			this->buttonContinue->Enabled = false;
			this->buttonContinue->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonContinue->Location = System::Drawing::Point(13, 22);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(208, 39);
			this->buttonContinue->TabIndex = 5;
			this->buttonContinue->Text = L"���������� ������";
			this->buttonContinue->UseVisualStyleBackColor = true;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonContinue_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic));
			this->buttonExit->Location = System::Drawing::Point(13, 157);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(208, 39);
			this->buttonExit->TabIndex = 4;
			this->buttonExit->Text = L"����� �� ���������";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonExit_Click);
			// 
			// timerCheck
			// 
			this->timerCheck->Tick += gcnew System::EventHandler(this, &MainMenuForm::timerCheck_Tick);
			// 
			// labelCurrentUser
			// 
			this->labelCurrentUser->AutoSize = true;
			this->labelCurrentUser->Location = System::Drawing::Point(-1, 241);
			this->labelCurrentUser->Name = L"labelCurrentUser";
			this->labelCurrentUser->Size = System::Drawing::Size(132, 13);
			this->labelCurrentUser->TabIndex = 5;
			this->labelCurrentUser->Text = L"������� ������������: ";
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 256);
			this->Controls->Add(this->labelCurrentUser);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(316, 295);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(316, 295);
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������� ����";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &MainMenuForm::MainMenuForm_HelpButtonClicked);
			this->Activated += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &MainMenuForm::MainMenuForm_Deactivate);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainMenuForm::MainMenuForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &MainMenuForm::preset);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: String^ currUser = "NONE";
	private: bool admin = false;
	private: System::Void �����ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonOpenQueueFile_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonContinue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCreateNewQueue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void preset(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void timerCheck_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_Activated(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_Deactivate(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkQueues();
	private: System::Void ����ToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
