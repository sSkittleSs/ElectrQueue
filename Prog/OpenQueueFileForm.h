#pragma once
#include <iostream>
#include <fstream>
#include "MainMenuForm.h"
//#include "Queue.h"
//#include "QueueData.h"
//#include "FunctionsConvert.h"

namespace Prog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ OpenQueueFileForm
	/// </summary>
	public ref class OpenQueueFileForm : public System::Windows::Forms::Form
	{
	public:
		OpenQueueFileForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		OpenQueueFileForm(System::Windows::Forms::Form^ mainMenu)
		{
			InitializeComponent();
			this->mainMenu = mainMenu;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~OpenQueueFileForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ mainMenu;
	private: System::Windows::Forms::Button^ buttonOpenFile1;
	private: System::Windows::Forms::PictureBox^ pictureBoxBrowse2;
	protected:


	protected:


	private: System::Windows::Forms::MenuStrip^ menuStrip1;




	private: System::Windows::Forms::ToolStripMenuItem^ оѕрограммеToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ выйти¬√лавноећенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выход»зѕрограммыToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBoxPath1;

	private: System::Windows::Forms::RadioButton^ radioButtonManualPath;



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButtonPath;
	private: System::Windows::Forms::TextBox^ textBoxPath2;
	private: System::Windows::Forms::Button^ buttonOpenFile2;



	private: System::Windows::Forms::GroupBox^ QueueBox;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::PictureBox^ pictureBoxBrowse1;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OpenQueueFileForm::typeid));
			this->buttonOpenFile1 = (gcnew System::Windows::Forms::Button());
			this->pictureBoxBrowse2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->оѕрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выйти¬√лавноећенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выход»зѕрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxPath1 = (gcnew System::Windows::Forms::TextBox());
			this->radioButtonManualPath = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxBrowse1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButtonPath = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxPath2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonOpenFile2 = (gcnew System::Windows::Forms::Button());
			this->QueueBox = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBrowse2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBrowse1))->BeginInit();
			this->QueueBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonOpenFile1
			// 
			this->buttonOpenFile1->Location = System::Drawing::Point(21, 42);
			this->buttonOpenFile1->Name = L"buttonOpenFile1";
			this->buttonOpenFile1->Size = System::Drawing::Size(100, 20);
			this->buttonOpenFile1->TabIndex = 0;
			this->buttonOpenFile1->Text = L"ќткрыть файл";
			this->buttonOpenFile1->UseVisualStyleBackColor = true;
			this->buttonOpenFile1->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::buttonOpenFile1_Click);
			// 
			// pictureBoxBrowse2
			// 
			this->pictureBoxBrowse2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxBrowse2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxBrowse2.BackgroundImage")));
			this->pictureBoxBrowse2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxBrowse2->Enabled = false;
			this->pictureBoxBrowse2->Location = System::Drawing::Point(334, 87);
			this->pictureBoxBrowse2->Name = L"pictureBoxBrowse2";
			this->pictureBoxBrowse2->Size = System::Drawing::Size(30, 30);
			this->pictureBoxBrowse2->TabIndex = 2;
			this->pictureBoxBrowse2->TabStop = false;
			this->pictureBoxBrowse2->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::pictureBoxBrowse2_Click);
			this->pictureBoxBrowse2->MouseEnter += gcnew System::EventHandler(this, &OpenQueueFileForm::pictureBoxBrowse2_MouseEnter);
			this->pictureBoxBrowse2->MouseLeave += gcnew System::EventHandler(this, &OpenQueueFileForm::pictureBoxBrowse2_MouseLeave);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->оѕрограммеToolStripMenuItem,
					this->выходToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(760, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// оѕрограммеToolStripMenuItem
			// 
			this->оѕрограммеToolStripMenuItem->Name = L"оѕрограммеToolStripMenuItem";
			this->оѕрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оѕрограммеToolStripMenuItem->Text = L"ќ программе";
			this->оѕрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::оѕрограммеToolStripMenuItem_Click);
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
			this->выйти¬√лавноећенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::выйти¬√лавноећенюToolStripMenuItem_Click);
			// 
			// выход»зѕрограммыToolStripMenuItem
			// 
			this->выход»зѕрограммыToolStripMenuItem->Name = L"выход»зѕрограммыToolStripMenuItem";
			this->выход»зѕрограммыToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->выход»зѕрограммыToolStripMenuItem->Text = L"¬ыход из программы";
			this->выход»зѕрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::выход»зѕрограммыToolStripMenuItem_Click);
			// 
			// textBoxPath1
			// 
			this->textBoxPath1->Location = System::Drawing::Point(127, 42);
			this->textBoxPath1->Name = L"textBoxPath1";
			this->textBoxPath1->Size = System::Drawing::Size(200, 20);
			this->textBoxPath1->TabIndex = 4;
			this->textBoxPath1->Text = L"”кажите путь к файлу";
			this->textBoxPath1->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::textBoxPath1_Click);
			// 
			// radioButtonManualPath
			// 
			this->radioButtonManualPath->AutoSize = true;
			this->radioButtonManualPath->Checked = true;
			this->radioButtonManualPath->Location = System::Drawing::Point(6, 19);
			this->radioButtonManualPath->Name = L"radioButtonManualPath";
			this->radioButtonManualPath->Size = System::Drawing::Size(168, 17);
			this->radioButtonManualPath->TabIndex = 5;
			this->radioButtonManualPath->TabStop = true;
			this->radioButtonManualPath->Text = L"¬ввод пути к файлу вручную";
			this->radioButtonManualPath->UseVisualStyleBackColor = true;
			this->radioButtonManualPath->CheckedChanged += gcnew System::EventHandler(this, &OpenQueueFileForm::radioButtonManualPath_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBoxBrowse1);
			this->groupBox1->Controls->Add(this->radioButtonPath);
			this->groupBox1->Controls->Add(this->textBoxPath2);
			this->groupBox1->Controls->Add(this->buttonOpenFile2);
			this->groupBox1->Controls->Add(this->radioButtonManualPath);
			this->groupBox1->Controls->Add(this->textBoxPath1);
			this->groupBox1->Controls->Add(this->pictureBoxBrowse2);
			this->groupBox1->Controls->Add(this->buttonOpenFile1);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(375, 132);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ќткрытие файла";
			// 
			// pictureBoxBrowse1
			// 
			this->pictureBoxBrowse1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBoxBrowse1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxBrowse1.BackgroundImage")));
			this->pictureBoxBrowse1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBoxBrowse1->Location = System::Drawing::Point(334, 36);
			this->pictureBoxBrowse1->Name = L"pictureBoxBrowse1";
			this->pictureBoxBrowse1->Size = System::Drawing::Size(30, 30);
			this->pictureBoxBrowse1->TabIndex = 10;
			this->pictureBoxBrowse1->TabStop = false;
			this->pictureBoxBrowse1->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::pictureBoxBrowse1_Click);
			this->pictureBoxBrowse1->MouseEnter += gcnew System::EventHandler(this, &OpenQueueFileForm::pictureBoxBrowse1_MouseEnter);
			this->pictureBoxBrowse1->MouseLeave += gcnew System::EventHandler(this, &OpenQueueFileForm::pictureBoxBrowse1_MouseLeave);
			// 
			// radioButtonPath
			// 
			this->radioButtonPath->AutoSize = true;
			this->radioButtonPath->Location = System::Drawing::Point(6, 69);
			this->radioButtonPath->Name = L"radioButtonPath";
			this->radioButtonPath->Size = System::Drawing::Size(200, 17);
			this->radioButtonPath->TabIndex = 9;
			this->radioButtonPath->Text = L"¬вод имени файла в папке queues";
			this->radioButtonPath->UseVisualStyleBackColor = true;
			this->radioButtonPath->CheckedChanged += gcnew System::EventHandler(this, &OpenQueueFileForm::radioButtonPath_CheckedChanged);
			// 
			// textBoxPath2
			// 
			this->textBoxPath2->Enabled = false;
			this->textBoxPath2->Location = System::Drawing::Point(127, 92);
			this->textBoxPath2->Name = L"textBoxPath2";
			this->textBoxPath2->Size = System::Drawing::Size(200, 20);
			this->textBoxPath2->TabIndex = 8;
			this->textBoxPath2->Text = L"”кажите полное им€ файла";
			this->textBoxPath2->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::textBoxPath2_Click);
			// 
			// buttonOpenFile2
			// 
			this->buttonOpenFile2->Enabled = false;
			this->buttonOpenFile2->Location = System::Drawing::Point(21, 92);
			this->buttonOpenFile2->Name = L"buttonOpenFile2";
			this->buttonOpenFile2->Size = System::Drawing::Size(100, 20);
			this->buttonOpenFile2->TabIndex = 7;
			this->buttonOpenFile2->TabStop = false;
			this->buttonOpenFile2->Text = L"ќткрыть файл";
			this->buttonOpenFile2->UseVisualStyleBackColor = true;
			this->buttonOpenFile2->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::buttonOpenFile2_Click);
			// 
			// QueueBox
			// 
			this->QueueBox->Controls->Add(this->dataGridView1);
			this->QueueBox->Location = System::Drawing::Point(404, 27);
			this->QueueBox->Name = L"QueueBox";
			this->QueueBox->Size = System::Drawing::Size(347, 282);
			this->QueueBox->TabIndex = 8;
			this->QueueBox->TabStop = false;
			this->QueueBox->Text = L"ѕредпросмотр очереди из файла ";
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
			this->dataGridView1->Size = System::Drawing::Size(335, 257);
			this->dataGridView1->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->buttonCancel);
			this->groupBox2->Controls->Add(this->buttonContinue);
			this->groupBox2->Location = System::Drawing::Point(12, 242);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(375, 67);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"ѕодтверждение выбора";
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(255, 23);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(100, 30);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"ќтмена";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::buttonCancel_Click);
			// 
			// buttonContinue
			// 
			this->buttonContinue->Enabled = false;
			this->buttonContinue->Location = System::Drawing::Point(21, 23);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(100, 30);
			this->buttonContinue->TabIndex = 0;
			this->buttonContinue->Text = L"ѕродолжить";
			this->buttonContinue->UseVisualStyleBackColor = true;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &OpenQueueFileForm::buttonContinue_Click);
			// 
			// OpenQueueFileForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 317);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->QueueBox);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(776, 356);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(776, 356);
			this->Name = L"OpenQueueFileForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ќткрытие очереди";
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &OpenQueueFileForm::OpenQueueFileForm_HelpButtonClicked);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &OpenQueueFileForm::OpenQueueFileForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBrowse2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBrowse1))->EndInit();
			this->QueueBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool toForm = false;
	private: System::Void pictureBoxBrowse1_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxBrowse1_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxBrowse2_MouseEnter(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxBrowse2_MouseLeave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выйти¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выход»зѕрограммыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void оѕрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pictureBoxBrowse1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxBrowse2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxPath1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBoxPath2_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void radioButtonManualPath_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButtonPath_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonOpenFile1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonOpenFile2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SetupDataGridView(std::string);
	private: System::Void buttonContinue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OpenQueueFileForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void OpenQueueFileForm_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
