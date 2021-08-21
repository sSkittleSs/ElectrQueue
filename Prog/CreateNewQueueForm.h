#pragma once
#include "MainMenuForm.h"
#include "queueData.h"
//MyQueue<queueData> queueCreate;

namespace Prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Ñâîäêà äëÿ CreateNewQueueForm
	/// </summary>
	public ref class CreateNewQueueForm : public System::Windows::Forms::Form
	{
	public:
		CreateNewQueueForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}
		CreateNewQueueForm(System::Windows::Forms::Form^ mainMenu)
		{
			InitializeComponent();
			this->mainMenu = mainMenu;
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~CreateNewQueueForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ mainMenu;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îòêğûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ âûéòèÂÃëàâíîåÌåíşToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäÈçÏğîãğàììûToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ QueueBox;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonConfirmTime;

	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxFileName;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxTitle;
	private: System::Windows::Forms::Button^ buttonConfirmFileName;
	private: System::Windows::Forms::Button^ buttonConfirmTitle;


	private: System::Windows::Forms::Button^ buttonCreateQueue;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownMinutesEnd;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownHoursEnd;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownMinutesStart;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownHoursStart;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBoxPassword;
	private: System::Windows::Forms::Button^ buttonConfirmPassword;
	private: System::Windows::Forms::Button^ buttonConfirmDate;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerDate;




	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûéòèÂÃëàâíîåÌåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->QueueBox = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonConfirmDate = (gcnew System::Windows::Forms::Button());
			this->dateTimePickerDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->maskedTextBoxPassword = (gcnew System::Windows::Forms::MaskedTextBox());
			this->buttonConfirmPassword = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownMinutesEnd = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownHoursEnd = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownMinutesStart = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownHoursStart = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonCreateQueue = (gcnew System::Windows::Forms::Button());
			this->buttonConfirmTime = (gcnew System::Windows::Forms::Button());
			this->maskedTextBoxFileName = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBoxTitle = (gcnew System::Windows::Forms::MaskedTextBox());
			this->buttonConfirmFileName = (gcnew System::Windows::Forms::Button());
			this->buttonConfirmTitle = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->QueueBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMinutesEnd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHoursEnd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMinutesStart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHoursStart))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->âûõîäToolStripMenuItem,
					this->îÏğîãğàììåToolStripMenuItem, this->âûõîäToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(780, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->îòêğûòüToolStripMenuItem });
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->âûõîäToolStripMenuItem->Text = L"Ôàéë";
			// 
			// îòêğûòüToolStripMenuItem
			// 
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(164, 22);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::îòêğûòüToolStripMenuItem_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::îÏğîãğàììåToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem1
			// 
			this->âûõîäToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->âûéòèÂÃëàâíîåÌåíşToolStripMenuItem,
					this->âûõîäÈçÏğîãğàììûToolStripMenuItem
			});
			this->âûõîäToolStripMenuItem1->Name = L"âûõîäToolStripMenuItem1";
			this->âûõîäToolStripMenuItem1->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem1->Text = L"Âûõîä";
			// 
			// âûéòèÂÃëàâíîåÌåíşToolStripMenuItem
			// 
			this->âûéòèÂÃëàâíîåÌåíşToolStripMenuItem->Name = L"âûéòèÂÃëàâíîåÌåíşToolStripMenuItem";
			this->âûéòèÂÃëàâíîåÌåíşToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->âûéòèÂÃëàâíîåÌåíşToolStripMenuItem->Text = L"Âûéòè â ãëàâíîå ìåíş";
			this->âûéòèÂÃëàâíîåÌåíşToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::âûéòèÂÃëàâíîåÌåíşToolStripMenuItem_Click);
			// 
			// âûõîäÈçÏğîãğàììûToolStripMenuItem
			// 
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Name = L"âûõîäÈçÏğîãğàììûToolStripMenuItem";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Text = L"Âûõîä èç ïğîãğàììû";
			this->âûõîäÈçÏğîãğàììûToolStripMenuItem->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::âûõîäÈçÏğîãğàììûToolStripMenuItem_Click);
			// 
			// QueueBox
			// 
			this->QueueBox->Controls->Add(this->dataGridView1);
			this->QueueBox->Location = System::Drawing::Point(413, 27);
			this->QueueBox->Name = L"QueueBox";
			this->QueueBox->Size = System::Drawing::Size(347, 307);
			this->QueueBox->TabIndex = 9;
			this->QueueBox->TabStop = false;
			this->QueueBox->Text = L"Ïğåäïğîñìîòğ î÷åğåäè";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 18);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(335, 283);
			this->dataGridView1->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->buttonCancel);
			this->groupBox2->Controls->Add(this->buttonContinue);
			this->groupBox2->Location = System::Drawing::Point(12, 267);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(375, 67);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ïîäòâåğæäåíèå ââåäåííûõ íàñòğîåê";
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(255, 23);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(100, 30);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Êîğğåêöèÿ";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonCancel_Click);
			// 
			// buttonContinue
			// 
			this->buttonContinue->Enabled = false;
			this->buttonContinue->Location = System::Drawing::Point(21, 23);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(100, 30);
			this->buttonContinue->TabIndex = 0;
			this->buttonContinue->Text = L"Ïğîäîëæèòü";
			this->buttonContinue->UseVisualStyleBackColor = true;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonContinue_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonConfirmDate);
			this->groupBox1->Controls->Add(this->dateTimePickerDate);
			this->groupBox1->Controls->Add(this->maskedTextBoxPassword);
			this->groupBox1->Controls->Add(this->buttonConfirmPassword);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->numericUpDownMinutesEnd);
			this->groupBox1->Controls->Add(this->numericUpDownHoursEnd);
			this->groupBox1->Controls->Add(this->numericUpDownMinutesStart);
			this->groupBox1->Controls->Add(this->numericUpDownHoursStart);
			this->groupBox1->Controls->Add(this->buttonCreateQueue);
			this->groupBox1->Controls->Add(this->buttonConfirmTime);
			this->groupBox1->Controls->Add(this->maskedTextBoxFileName);
			this->groupBox1->Controls->Add(this->maskedTextBoxTitle);
			this->groupBox1->Controls->Add(this->buttonConfirmFileName);
			this->groupBox1->Controls->Add(this->buttonConfirmTitle);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(375, 234);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Íàñòğîéêè íîâîé î÷åğåäè";
			// 
			// buttonConfirmDate
			// 
			this->buttonConfirmDate->Location = System::Drawing::Point(6, 177);
			this->buttonConfirmDate->Name = L"buttonConfirmDate";
			this->buttonConfirmDate->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmDate->TabIndex = 18;
			this->buttonConfirmDate->Text = L"Ïîäòâåğäèòü";
			this->buttonConfirmDate->UseVisualStyleBackColor = true;
			this->buttonConfirmDate->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonConfirmDate_Click);
			// 
			// dateTimePickerDate
			// 
			this->dateTimePickerDate->Location = System::Drawing::Point(111, 179);
			this->dateTimePickerDate->Name = L"dateTimePickerDate";
			this->dateTimePickerDate->Size = System::Drawing::Size(224, 20);
			this->dateTimePickerDate->TabIndex = 17;
			// 
			// maskedTextBoxPassword
			// 
			this->maskedTextBoxPassword->Location = System::Drawing::Point(111, 149);
			this->maskedTextBoxPassword->Name = L"maskedTextBoxPassword";
			this->maskedTextBoxPassword->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxPassword->TabIndex = 16;
			this->maskedTextBoxPassword->Text = L"Ââåäèòå ïàğîëü àäìèíèñòğàòîğà î÷åğåäè";
			this->maskedTextBoxPassword->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::maskedTextBoxPassword_Click);
			// 
			// buttonConfirmPassword
			// 
			this->buttonConfirmPassword->Location = System::Drawing::Point(6, 148);
			this->buttonConfirmPassword->Name = L"buttonConfirmPassword";
			this->buttonConfirmPassword->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmPassword->TabIndex = 15;
			this->buttonConfirmPassword->Text = L"Ïîäòâåğäèòü";
			this->buttonConfirmPassword->UseVisualStyleBackColor = true;
			this->buttonConfirmPassword->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonConfirmPassword_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(211, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Âğåìÿ êîíöà ğàáîòû";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(211, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Âğåìÿ íà÷àëà ğàáîòû";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(130, 136);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 9);
			this->label1->TabIndex = 12;
			this->label1->Text = L"××                 ÌÌ";
			// 
			// numericUpDownMinutesEnd
			// 
			this->numericUpDownMinutesEnd->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownMinutesEnd->Location = System::Drawing::Point(167, 113);
			this->numericUpDownMinutesEnd->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownMinutesEnd->Name = L"numericUpDownMinutesEnd";
			this->numericUpDownMinutesEnd->Size = System::Drawing::Size(39, 20);
			this->numericUpDownMinutesEnd->TabIndex = 11;
			// 
			// numericUpDownHoursEnd
			// 
			this->numericUpDownHoursEnd->Location = System::Drawing::Point(122, 113);
			this->numericUpDownHoursEnd->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDownHoursEnd->Name = L"numericUpDownHoursEnd";
			this->numericUpDownHoursEnd->Size = System::Drawing::Size(39, 20);
			this->numericUpDownHoursEnd->TabIndex = 10;
			// 
			// numericUpDownMinutesStart
			// 
			this->numericUpDownMinutesStart->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownMinutesStart->Location = System::Drawing::Point(167, 87);
			this->numericUpDownMinutesStart->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownMinutesStart->Name = L"numericUpDownMinutesStart";
			this->numericUpDownMinutesStart->Size = System::Drawing::Size(39, 20);
			this->numericUpDownMinutesStart->TabIndex = 9;
			// 
			// numericUpDownHoursStart
			// 
			this->numericUpDownHoursStart->Location = System::Drawing::Point(122, 87);
			this->numericUpDownHoursStart->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 23, 0, 0, 0 });
			this->numericUpDownHoursStart->Name = L"numericUpDownHoursStart";
			this->numericUpDownHoursStart->Size = System::Drawing::Size(39, 20);
			this->numericUpDownHoursStart->TabIndex = 8;
			// 
			// buttonCreateQueue
			// 
			this->buttonCreateQueue->Location = System::Drawing::Point(21, 206);
			this->buttonCreateQueue->Name = L"buttonCreateQueue";
			this->buttonCreateQueue->Size = System::Drawing::Size(334, 23);
			this->buttonCreateQueue->TabIndex = 7;
			this->buttonCreateQueue->Text = L"Ñîçäàòü î÷åğåäü";
			this->buttonCreateQueue->UseVisualStyleBackColor = true;
			this->buttonCreateQueue->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonCreateQueue_Click);
			// 
			// buttonConfirmTime
			// 
			this->buttonConfirmTime->Location = System::Drawing::Point(6, 103);
			this->buttonConfirmTime->Name = L"buttonConfirmTime";
			this->buttonConfirmTime->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmTime->TabIndex = 4;
			this->buttonConfirmTime->Text = L"Ïîäòâåğäèòü";
			this->buttonConfirmTime->UseVisualStyleBackColor = true;
			this->buttonConfirmTime->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonConfirmTime_Click);
			// 
			// maskedTextBoxFileName
			// 
			this->maskedTextBoxFileName->Location = System::Drawing::Point(111, 61);
			this->maskedTextBoxFileName->Name = L"maskedTextBoxFileName";
			this->maskedTextBoxFileName->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxFileName->TabIndex = 3;
			this->maskedTextBoxFileName->Text = L"Ââåäèòå èìÿ ôàéëà (áåç ğàñøèğåíèÿ)";
			this->maskedTextBoxFileName->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::maskedTextBoxFileName_Click);
			// 
			// maskedTextBoxTitle
			// 
			this->maskedTextBoxTitle->Location = System::Drawing::Point(111, 32);
			this->maskedTextBoxTitle->Name = L"maskedTextBoxTitle";
			this->maskedTextBoxTitle->Size = System::Drawing::Size(224, 20);
			this->maskedTextBoxTitle->TabIndex = 2;
			this->maskedTextBoxTitle->Text = L"Ââåäèòå íàçâàíèå î÷åğåäè (Âğà÷)";
			this->maskedTextBoxTitle->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::maskedTextBoxTitle_Click);
			// 
			// buttonConfirmFileName
			// 
			this->buttonConfirmFileName->Location = System::Drawing::Point(6, 60);
			this->buttonConfirmFileName->Name = L"buttonConfirmFileName";
			this->buttonConfirmFileName->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmFileName->TabIndex = 1;
			this->buttonConfirmFileName->Text = L"Ïîäòâåğäèòü";
			this->buttonConfirmFileName->UseVisualStyleBackColor = true;
			this->buttonConfirmFileName->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonConfirmFileName_Click);
			// 
			// buttonConfirmTitle
			// 
			this->buttonConfirmTitle->Location = System::Drawing::Point(6, 31);
			this->buttonConfirmTitle->Name = L"buttonConfirmTitle";
			this->buttonConfirmTitle->Size = System::Drawing::Size(89, 23);
			this->buttonConfirmTitle->TabIndex = 0;
			this->buttonConfirmTitle->Text = L"Ïîäòâåğäèòü";
			this->buttonConfirmTitle->UseVisualStyleBackColor = true;
			this->buttonConfirmTitle->Click += gcnew System::EventHandler(this, &CreateNewQueueForm::buttonConfirmTitle_Click);
			// 
			// CreateNewQueueForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 346);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->QueueBox);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(796, 385);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(796, 385);
			this->Name = L"CreateNewQueueForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ñîçäàíèå î÷åğåäè";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &CreateNewQueueForm::CreateNewQueueForm_HelpButtonClicked);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CreateNewQueueForm::CreateNewQueueForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->QueueBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMinutesEnd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHoursEnd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownMinutesStart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownHoursStart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool toForm = false;
	private: bool titleConfirmed = false;
	private: bool fileNameConfirmed = false;
	private: bool timeConfirmed = false;
	private: bool passwordConfirmed = false;
	private: bool dateConfirmed = false;
	private: String^ file;
	private: System::Void CreateNewQueueForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void âûéòèÂÃëàâíîåÌåíşToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäÈçÏğîãğàììûToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxTitle_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxFileName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBoxPassword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmTitle_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmFileName_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmTime_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmPassword_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonConfirmDate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCreateQueue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SetupDataGridView(std::string);
	private: System::Void buttonContinue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CreateNewQueueForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
