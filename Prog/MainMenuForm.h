#pragma once
#include <Windows.h>
#include <fstream>
#include "FunctionsConvert.h" // Ïîäêëş÷àåì çàãîëîâî÷íûé ôàéë ñ ôóíêöèÿìè êîíâåğòàöèè (std::string, System::String, char*).

/******Ïîäêëş÷åíèå îñòàëüíûõ ôîğì*******/
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
	/// Ñâîäêà äëÿ MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MainMenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//

			DateTime tod = DateTime::Today;
			if (tod.DayOfWeek == DayOfWeek::Monday)
				remove(ConvertStringToChar(Application::StartupPath + "\\users\\cancelLog.txt"));

			checkQueues();
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
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




	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem1;
	private: System::Windows::Forms::Button^ buttonOpenQueueFile;
	private: System::Windows::Forms::Button^ buttonCreateNewQueue;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonExit;





	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::Timer^ timerCheck;

	private: System::Windows::Forms::ToolStripMenuItem^ àâòîğèçàöèÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğåãèñòğàöèÿToolStripMenuItem;
	private: System::Windows::Forms::Label^ labelCurrentUser;


	private: System::Windows::Forms::ToolStripMenuItem^ âûéòèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ëè÷íûéÊàáèíåòToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âõîäToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ âõîäToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->àâòîğèçàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåãèñòğàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûéòèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ëè÷íûéÊàáèíåòToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âõîäToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âõîäToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->àâòîğèçàöèÿToolStripMenuItem,
					this->îÏğîãğàììåToolStripMenuItem, this->âõîäToolStripMenuItem1, this->âûõîäToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(300, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// àâòîğèçàöèÿToolStripMenuItem
			// 
			this->àâòîğèçàöèÿToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->âõîäToolStripMenuItem,
					this->ğåãèñòğàöèÿToolStripMenuItem, this->âûéòèToolStripMenuItem, this->ëè÷íûéÊàáèíåòToolStripMenuItem
			});
			this->àâòîğèçàöèÿToolStripMenuItem->Name = L"àâòîğèçàöèÿToolStripMenuItem";
			this->àâòîğèçàöèÿToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->àâòîğèçàöèÿToolStripMenuItem->Text = L"Àâòîğèçàöèÿ";
			// 
			// âõîäToolStripMenuItem
			// 
			this->âõîäToolStripMenuItem->Name = L"âõîäToolStripMenuItem";
			this->âõîäToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->âõîäToolStripMenuItem->Text = L"Âõîä";
			this->âõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::âõîäToolStripMenuItem_Click);
			// 
			// ğåãèñòğàöèÿToolStripMenuItem
			// 
			this->ğåãèñòğàöèÿToolStripMenuItem->Name = L"ğåãèñòğàöèÿToolStripMenuItem";
			this->ğåãèñòğàöèÿToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->ğåãèñòğàöèÿToolStripMenuItem->Text = L"Ğåãèñòğàöèÿ";
			this->ğåãèñòğàöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::ğåãèñòğàöèÿToolStripMenuItem_Click);
			// 
			// âûéòèToolStripMenuItem
			// 
			this->âûéòèToolStripMenuItem->Name = L"âûéòèToolStripMenuItem";
			this->âûéòèToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->âûéòèToolStripMenuItem->Text = L"Âûéòè";
			this->âûéòèToolStripMenuItem->Visible = false;
			this->âûéòèToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::âûéòèToolStripMenuItem_Click);
			// 
			// ëè÷íûéÊàáèíåòToolStripMenuItem
			// 
			this->ëè÷íûéÊàáèíåòToolStripMenuItem->Name = L"ëè÷íûéÊàáèíåòToolStripMenuItem";
			this->ëè÷íûéÊàáèíåòToolStripMenuItem->Size = System::Drawing::Size(166, 22);
			this->ëè÷íûéÊàáèíåòToolStripMenuItem->Text = L"Ëè÷íûé êàáèíåò";
			this->ëè÷íûéÊàáèíåòToolStripMenuItem->Visible = false;
			this->ëè÷íûéÊàáèíåòToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::ëè÷íûéÊàáèíåòToolStripMenuItem_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::îÏğîãğàììåToolStripMenuItem_Click);
			// 
			// âõîäToolStripMenuItem1
			// 
			this->âõîäToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âõîäToolStripMenuItem2,
					this->âûõîäToolStripMenuItem
			});
			this->âõîäToolStripMenuItem1->Name = L"âõîäToolStripMenuItem1";
			this->âõîäToolStripMenuItem1->Size = System::Drawing::Size(56, 20);
			this->âõîäToolStripMenuItem1->Text = L"Àäìèí";
			// 
			// âõîäToolStripMenuItem2
			// 
			this->âõîäToolStripMenuItem2->Name = L"âõîäToolStripMenuItem2";
			this->âõîäToolStripMenuItem2->Size = System::Drawing::Size(109, 22);
			this->âõîäToolStripMenuItem2->Text = L"Âõîä";
			this->âõîäToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainMenuForm::âõîäToolStripMenuItem2_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenuForm::âûõîäToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem1
			// 
			this->âûõîäToolStripMenuItem1->Name = L"âûõîäToolStripMenuItem1";
			this->âûõîäToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem1->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainMenuForm::âûõîäToolStripMenuItem1_Click);
			// 
			// buttonOpenQueueFile
			// 
			this->buttonOpenQueueFile->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOpenQueueFile->Location = System::Drawing::Point(13, 67);
			this->buttonOpenQueueFile->Name = L"buttonOpenQueueFile";
			this->buttonOpenQueueFile->Size = System::Drawing::Size(208, 39);
			this->buttonOpenQueueFile->TabIndex = 2;
			this->buttonOpenQueueFile->Text = L"Îòêğûòü ôàéë";
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
			this->buttonCreateNewQueue->Text = L"Ñîçäàòü íîâóş î÷åğåäü";
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
			this->groupBox1->Text = L"Ãëàâíîå ìåíş";
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
			this->buttonContinue->Text = L"Ïğîäîëæèòü ğàáîòó";
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
			this->buttonExit->Text = L"Âûõîä èç ïğîãğàììû";
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
			this->labelCurrentUser->Text = L"Òåêóùèé ïîëüçîâàòåëü: ";
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
			this->Text = L"Ãëàâíîå ìåíş";
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
	private: System::Void âûõîäToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonOpenQueueFile_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonContinue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCreateNewQueue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void preset(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void timerCheck_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_Activated(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_Deactivate(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ğåãèñòğàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûéòèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ëè÷íûéÊàáèíåòToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkQueues();
	private: System::Void âõîäToolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainMenuForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
