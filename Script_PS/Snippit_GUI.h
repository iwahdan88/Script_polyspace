#pragma once

#include "Code_Replacer.h"
#include "Snippit.h"
namespace Script_PS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for Snippet_Config
	/// </summary>
	public ref class Snippet_Config : public System::Windows::Forms::Form 
	{
	public:
		Snippet_Config(System::String^ XmlPath, double ver)
		{
			System::String^ Err = "";
			IsSaveRequired = true;
			this->SWVersion = ver;
			Snpt_Replacer = gcnew Main_package::Replacer(XmlPath);
			InitializeComponent();
			SnippitTypeCombo->Items->Add("PolySpace_1");
			SnippitTypeCombo->Items->Add("PolySpace_2");
			SnippitTypeCombo->Items->Add("Bug_Report");
			if (!this->Snpt_Replacer->Load_XmlFile(XmlPath))
			{
				throw (gcnew System::Exception("Failed to load Xml"));
			}
			else
			{
				this->Path = XmlPath;
				this->Enable_Add = false;
				this->pat_num = gcnew Regex("([0-9]+)");
				this->Fill_Tree();
				this->Load_File_Names();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Snippet_Config()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::Button^  Add_button;
	private: System::Windows::Forms::Button^  Delete_button;
	private: System::Windows::Forms::Button^  Edit_button;
	private: System::String^ ErrMssg;
	protected: 





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label4;
	private: Main_package::Replacer^ Snpt_Replacer;
	private: bool IsSaveRequired;
	private: double SWVersion;
	private: Regex^ pat_num;
	private: System::Windows::Forms::Button^  Refresh;

	private: System::String^ Path;
	private: System::Windows::Forms::Button^  New_snpt;
	private: array<System::Windows::Forms::TreeNode^>^ Snpts;
	private: TreeNode^ Global;
	private: bool Enable_Add;
	private: ScintillaNET::Scintilla^  richTextBox1;
	private: ScintillaNET::Scintilla^  richTextBox2;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  SnippitTypeCombo;
	private: System::Windows::Forms::Label^  SnippiyTypeLabel;
	private: System::Windows::Forms::TextBox^  BugReportTxt;

	private: System::Windows::Forms::Label^  BugReportNumLbl;
	private: System::Windows::Forms::CheckBox^  IsReplaceCheck;
	private: System::Windows::Forms::CheckBox^  IsReusedCheck;

	private: System::Windows::Forms::Label^  SWLabel;
	private: System::Windows::Forms::Label^  TRQLabel;
	private: System::Windows::Forms::TextBox^  TRAQBox;
	private: System::Windows::Forms::RichTextBox^  JustificationBox;
	private: System::Windows::Forms::Label^  JustLabel;
	private: System::Windows::Forms::Button^  SaveBtn;
	private: System::Windows::Forms::Button^  LoadSnptBtn;
	private: System::Windows::Forms::OpenFileDialog^  XML_FileDialog;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->Add_button = (gcnew System::Windows::Forms::Button());
			this->Delete_button = (gcnew System::Windows::Forms::Button());
			this->Edit_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Refresh = (gcnew System::Windows::Forms::Button());
			this->New_snpt = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew ScintillaNET::Scintilla());
			this->richTextBox2 = (gcnew ScintillaNET::Scintilla());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SnippitTypeCombo = (gcnew System::Windows::Forms::ComboBox());
			this->SnippiyTypeLabel = (gcnew System::Windows::Forms::Label());
			this->BugReportTxt = (gcnew System::Windows::Forms::TextBox());
			this->BugReportNumLbl = (gcnew System::Windows::Forms::Label());
			this->IsReplaceCheck = (gcnew System::Windows::Forms::CheckBox());
			this->IsReusedCheck = (gcnew System::Windows::Forms::CheckBox());
			this->SWLabel = (gcnew System::Windows::Forms::Label());
			this->TRQLabel = (gcnew System::Windows::Forms::Label());
			this->TRAQBox = (gcnew System::Windows::Forms::TextBox());
			this->JustificationBox = (gcnew System::Windows::Forms::RichTextBox());
			this->JustLabel = (gcnew System::Windows::Forms::Label());
			this->SaveBtn = (gcnew System::Windows::Forms::Button());
			this->LoadSnptBtn = (gcnew System::Windows::Forms::Button());
			this->XML_FileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->richTextBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->richTextBox2))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// treeView1
			// 
			this->treeView1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->treeView1->Location = System::Drawing::Point(12, 84);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(130, 559);
			this->treeView1->TabIndex = 0;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Snippet_Config::treeView1_AfterSelect);
			// 
			// Add_button
			// 
			this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			this->Add_button->Location = System::Drawing::Point(286, 617);
			this->Add_button->Name = L"Add_button";
			this->Add_button->Size = System::Drawing::Size(102, 26);
			this->Add_button->TabIndex = 3;
			this->Add_button->Text = L"Add";
			this->Add_button->UseVisualStyleBackColor = false;
			this->Add_button->Click += gcnew System::EventHandler(this, &Snippet_Config::Add_button_Click);
			// 
			// Delete_button
			// 
			this->Delete_button->Location = System::Drawing::Point(1033, 617);
			this->Delete_button->Name = L"Delete_button";
			this->Delete_button->Size = System::Drawing::Size(102, 26);
			this->Delete_button->TabIndex = 4;
			this->Delete_button->Text = L"Delete";
			this->Delete_button->UseVisualStyleBackColor = true;
			this->Delete_button->Click += gcnew System::EventHandler(this, &Snippet_Config::Delete_button_Click);
			// 
			// Edit_button
			// 
			this->Edit_button->Location = System::Drawing::Point(1155, 617);
			this->Edit_button->Name = L"Edit_button";
			this->Edit_button->Size = System::Drawing::Size(102, 26);
			this->Edit_button->TabIndex = 5;
			this->Edit_button->Text = L"Edit";
			this->Edit_button->UseVisualStyleBackColor = true;
			this->Edit_button->Click += gcnew System::EventHandler(this, &Snippet_Config::Edit_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"List of Code Snippets :";
			this->label1->Click += gcnew System::EventHandler(this, &Snippet_Config::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(160, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Original Code";
			this->label2->Click += gcnew System::EventHandler(this, &Snippet_Config::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(815, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Replacment";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(230, 17);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Choose File Name :";
			this->label4->Click += gcnew System::EventHandler(this, &Snippet_Config::label4_Click);
			// 
			// Refresh
			// 
			this->Refresh->Location = System::Drawing::Point(1095, 17);
			this->Refresh->Name = L"Refresh";
			this->Refresh->Size = System::Drawing::Size(94, 22);
			this->Refresh->TabIndex = 11;
			this->Refresh->Text = L"Refresh";
			this->Refresh->UseVisualStyleBackColor = true;
			this->Refresh->Click += gcnew System::EventHandler(this, &Snippet_Config::Refresh_Click);
			// 
			// New_snpt
			// 
			this->New_snpt->Location = System::Drawing::Point(163, 617);
			this->New_snpt->Name = L"New_snpt";
			this->New_snpt->Size = System::Drawing::Size(102, 26);
			this->New_snpt->TabIndex = 13;
			this->New_snpt->Text = L"New Snippit";
			this->New_snpt->UseVisualStyleBackColor = true;
			this->New_snpt->Click += gcnew System::EventHandler(this, &Snippet_Config::New_snpt_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->ConfigurationManager->Language = L"cs";
			this->richTextBox1->Indentation->TabWidth = 4;
			this->richTextBox1->Location = System::Drawing::Point(163, 84);
			this->richTextBox1->Margins->Margin0->Width = 20;
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(600, 403);
			this->richTextBox1->Styles->BraceBad->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->BraceLight->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->CallTip->FontName = L"Segoe UI\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->ControlChar->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->Default->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox1->Styles->Default->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->IndentGuide->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->LastPredefined->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->LineNumber->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->Styles->Max->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox1->TabIndex = 14;
			// 
			// richTextBox2
			// 
			this->richTextBox2->ConfigurationManager->Language = L"cs";
			this->richTextBox2->Indentation->TabWidth = 4;
			this->richTextBox2->Location = System::Drawing::Point(818, 84);
			this->richTextBox2->Margins->Margin0->Width = 25;
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(600, 403);
			this->richTextBox2->Styles->BraceBad->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->BraceLight->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->CallTip->FontName = L"Segoe UI\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->ControlChar->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->Default->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox2->Styles->Default->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->IndentGuide->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->LastPredefined->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->LineNumber->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->Styles->Max->FontName = L"Verdana\0\0\0\0\0\0\0\0\0\0\0\0\0";
			this->richTextBox2->TabIndex = 15;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 665);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1448, 22);
			this->statusStrip1->TabIndex = 16;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(39, 17);
			this->toolStripStatusLabel1->Text = L"Ready";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(335, 14);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(178, 21);
			this->comboBox1->TabIndex = 17;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Snippet_Config::comboBox1_SelectedIndexChanged);
			// 
			// SnippitTypeCombo
			// 
			this->SnippitTypeCombo->FormattingEnabled = true;
			this->SnippitTypeCombo->Location = System::Drawing::Point(613, 14);
			this->SnippitTypeCombo->Name = L"SnippitTypeCombo";
			this->SnippitTypeCombo->Size = System::Drawing::Size(177, 21);
			this->SnippitTypeCombo->TabIndex = 18;
			this->SnippitTypeCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Snippet_Config::SnippitTypeCombo_SelectedIndexChanged);
			// 
			// SnippiyTypeLabel
			// 
			this->SnippiyTypeLabel->AutoSize = true;
			this->SnippiyTypeLabel->Location = System::Drawing::Point(534, 17);
			this->SnippiyTypeLabel->Name = L"SnippiyTypeLabel";
			this->SnippiyTypeLabel->Size = System::Drawing::Size(66, 13);
			this->SnippiyTypeLabel->TabIndex = 19;
			this->SnippiyTypeLabel->Text = L"Snippit Type";
			// 
			// BugReportTxt
			// 
			this->BugReportTxt->Enabled = false;
			this->BugReportTxt->Location = System::Drawing::Point(418, 50);
			this->BugReportTxt->Name = L"BugReportTxt";
			this->BugReportTxt->Size = System::Drawing::Size(50, 20);
			this->BugReportTxt->TabIndex = 20;
			// 
			// BugReportNumLbl
			// 
			this->BugReportNumLbl->AutoSize = true;
			this->BugReportNumLbl->Location = System::Drawing::Point(332, 53);
			this->BugReportNumLbl->Name = L"BugReportNumLbl";
			this->BugReportNumLbl->Size = System::Drawing::Size(80, 13);
			this->BugReportNumLbl->TabIndex = 21;
			this->BugReportNumLbl->Text = L"BugReportNum";
			// 
			// IsReplaceCheck
			// 
			this->IsReplaceCheck->AutoSize = true;
			this->IsReplaceCheck->Enabled = false;
			this->IsReplaceCheck->Location = System::Drawing::Point(1222, 21);
			this->IsReplaceCheck->Name = L"IsReplaceCheck";
			this->IsReplaceCheck->Size = System::Drawing::Size(100, 17);
			this->IsReplaceCheck->TabIndex = 22;
			this->IsReplaceCheck->Text = L"Snippet Verified";
			this->IsReplaceCheck->UseVisualStyleBackColor = true;
			// 
			// IsReusedCheck
			// 
			this->IsReusedCheck->AutoSize = true;
			this->IsReusedCheck->Enabled = false;
			this->IsReusedCheck->Location = System::Drawing::Point(1222, 44);
			this->IsReusedCheck->Name = L"IsReusedCheck";
			this->IsReusedCheck->Size = System::Drawing::Size(194, 17);
			this->IsReusedCheck->TabIndex = 23;
			this->IsReusedCheck->Text = L"Snippet Reused From previous Run";
			this->IsReusedCheck->UseVisualStyleBackColor = true;
			// 
			// SWLabel
			// 
			this->SWLabel->AutoSize = true;
			this->SWLabel->Location = System::Drawing::Point(888, 17);
			this->SWLabel->Name = L"SWLabel";
			this->SWLabel->Size = System::Drawing::Size(66, 13);
			this->SWLabel->TabIndex = 25;
			this->SWLabel->Text = L"SW Version:";
			this->SWLabel->Click += gcnew System::EventHandler(this, &Snippet_Config::SWLabel_Click);
			// 
			// TRQLabel
			// 
			this->TRQLabel->AutoSize = true;
			this->TRQLabel->Location = System::Drawing::Point(506, 53);
			this->TRQLabel->Name = L"TRQLabel";
			this->TRQLabel->Size = System::Drawing::Size(40, 13);
			this->TRQLabel->TabIndex = 27;
			this->TRQLabel->Text = L"TRAQ:";
			// 
			// TRAQBox
			// 
			this->TRAQBox->Enabled = false;
			this->TRAQBox->Location = System::Drawing::Point(552, 50);
			this->TRAQBox->Name = L"TRAQBox";
			this->TRAQBox->Size = System::Drawing::Size(190, 20);
			this->TRAQBox->TabIndex = 28;
			// 
			// JustificationBox
			// 
			this->JustificationBox->Location = System::Drawing::Point(537, 506);
			this->JustificationBox->Name = L"JustificationBox";
			this->JustificationBox->Size = System::Drawing::Size(476, 56);
			this->JustificationBox->TabIndex = 29;
			this->JustificationBox->Text = L"";
			// 
			// JustLabel
			// 
			this->JustLabel->AutoSize = true;
			this->JustLabel->Location = System::Drawing::Point(437, 528);
			this->JustLabel->Name = L"JustLabel";
			this->JustLabel->Size = System::Drawing::Size(62, 13);
			this->JustLabel->TabIndex = 30;
			this->JustLabel->Text = L"Justification";
			// 
			// SaveBtn
			// 
			this->SaveBtn->Location = System::Drawing::Point(12, 10);
			this->SaveBtn->Name = L"SaveBtn";
			this->SaveBtn->Size = System::Drawing::Size(59, 24);
			this->SaveBtn->TabIndex = 31;
			this->SaveBtn->Text = L"Save";
			this->SaveBtn->UseVisualStyleBackColor = true;
			this->SaveBtn->Click += gcnew System::EventHandler(this, &Snippet_Config::SaveBtn_Click);
			// 
			// LoadSnptBtn
			// 
			this->LoadSnptBtn->Location = System::Drawing::Point(654, 617);
			this->LoadSnptBtn->Name = L"LoadSnptBtn";
			this->LoadSnptBtn->Size = System::Drawing::Size(109, 25);
			this->LoadSnptBtn->TabIndex = 32;
			this->LoadSnptBtn->Text = L"Load Snippets";
			this->LoadSnptBtn->UseVisualStyleBackColor = true;
			this->LoadSnptBtn->Click += gcnew System::EventHandler(this, &Snippet_Config::LoadSnptBtn_Click);
			// 
			// XML_FileDialog
			// 
			this->XML_FileDialog->FileName = L"openFileDialog1";
			// 
			// Snippet_Config
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(1448, 687);
			this->Controls->Add(this->LoadSnptBtn);
			this->Controls->Add(this->SaveBtn);
			this->Controls->Add(this->JustLabel);
			this->Controls->Add(this->JustificationBox);
			this->Controls->Add(this->TRAQBox);
			this->Controls->Add(this->TRQLabel);
			this->Controls->Add(this->SWLabel);
			this->Controls->Add(this->IsReusedCheck);
			this->Controls->Add(this->IsReplaceCheck);
			this->Controls->Add(this->BugReportNumLbl);
			this->Controls->Add(this->BugReportTxt);
			this->Controls->Add(this->SnippiyTypeLabel);
			this->Controls->Add(this->SnippitTypeCombo);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->New_snpt);
			this->Controls->Add(this->Refresh);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Edit_button);
			this->Controls->Add(this->Delete_button);
			this->Controls->Add(this->Add_button);
			this->Controls->Add(this->treeView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Snippet_Config";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Snippet_Config";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Snippet_Config::Snippet_Config_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Snippet_Config::Snippet_Config_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->richTextBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->richTextBox2))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void Load_File_Names (void)
		{
			for(int i = 0; i< this->Snpt_Replacer->Get_Snpt_Count(); i++)
			{
				if(this->Snpt_Replacer->Get_snippit(i)[2]->Equals(""))
				{
					continue;
				}
				else
				{
					Add_File_ToCombo(this->Snpt_Replacer->Get_snippit(i)[2]);
				}
			}
		}
		void Add_File_ToCombo(System::String^ s)
		{
			if(this->comboBox1->Items->Contains(s))
			{
				return;
			}
			else
			{
				this->comboBox1->Items->Add(s);
				return;
			}
		}
		bool Check_File_Name(System::String^ s)
		{
			return (Regex::IsMatch(s, "\\.[cC]$"));
		}
		void Fill_Tree(void)
		{
			int index = this->Snpt_Replacer->Get_Snpt_Count();
			this->Snpts = gcnew array<System::Windows::Forms::TreeNode^>(index);
			for(int i=0;i<index;i++)
			{
				Snpts[i] = gcnew TreeNode("Snippit # " +(this->Snpt_Replacer->Get_snippit(i))[9]);
			}
			Global = gcnew TreeNode("All Snippets", Snpts);
			this->treeView1->Nodes->Add(Global);
		}
		void RefillTree(void)
		{
			int index = this->Snpt_Replacer->Get_Snpt_Count();
			this->Snpts = gcnew array<System::Windows::Forms::TreeNode^>(index);
			for (int i = 0; i<index; i++)
			{
				Snpts[i] = gcnew TreeNode("Snippit # " + (this->Snpt_Replacer->Get_snippit(i))[9]);
			}
			Global->Nodes->Clear();
			this->treeView1->Nodes->Clear();
			Global = gcnew TreeNode("All Snippets", Snpts);
			this->treeView1->Nodes->Add(Global);
		}
		void Refresh_Tree(void)
		{
			int index = this->Snpt_Replacer->Get_Snpt_Count();
			this->Snpts = gcnew array<System::Windows::Forms::TreeNode^>(index);
			for(int i=0;i<index;i++)
			{
				Snpts[i] = gcnew TreeNode("Snippit # " + (this->Snpt_Replacer->Get_snippit(i))[9]);
			}
			Global = gcnew TreeNode("All Snippets", Snpts);
			this->treeView1->BeginUpdate();
			this->treeView1->Nodes->Clear();
			this->treeView1->Nodes->Add(Global);
			this->treeView1->EndUpdate();
			this->treeView1->ExpandAll();
		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Snippet_Config_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Snippet_Config_Closing( Object^ sender, System::ComponentModel::CancelEventArgs^ e )
		{
		}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
		 {
			 System::String^ loc_Text = e->Node->Text;
			 Match^ Num_match = this->pat_num->Match(loc_Text);
			 System::String^ Number = Num_match->Groups[1]->Value;
			 if(!(Number->Equals("")))
			 {
				 unsigned short Num = int::Parse(Number);
				 array<System::String^>^ Snpt =  this->Snpt_Replacer->Get_snippitByID(Num);
				 this->richTextBox1->Text = Snpt[0];
				 this->richTextBox2->Text = Snpt[1];
				 this->SnippitTypeCombo->Text = Snpt[3];
				 if (Snpt[3]->Equals("Bug_Report"))
				 {
					 this->BugReportTxt->Enabled = true;
					 this->TRAQBox->Enabled = true;
					 this->BugReportTxt->Text = Snpt[10];
					 this->TRAQBox->Text = Snpt[8];
				 }
				 else
				 {
					 this->BugReportTxt->Enabled = false;
					 this->TRAQBox->Enabled = false;
				 }
				 if (Snpt[6]->Equals("YES"))
				 {
					 this->IsReusedCheck->Checked = true;
				 }
				 else
				 {
					 this->IsReusedCheck->Checked = false;
				 }
				 if (Snpt[7]->Equals("YES"))
				 {
					 this->IsReplaceCheck->Checked = true;
				 }
				 else
				 {
					 this->IsReplaceCheck->Checked = false;
				 }
				 this->JustificationBox->Text = Snpt[4];
				 this->SWLabel->Text = "SW Version: "+Snpt[5];
				 this->comboBox1->Text = Snpt[2];
			 }
			 else
			 {
				 this->richTextBox1->Text = "";
				 this->richTextBox2->Text = "";
				 this->comboBox1->Text = "";
			 }
			 this-> Enable_Add = false;
			 this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			 this->toolStripStatusLabel1->Text = "Ready";
		 }
private: System::Void Refresh_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			System::String^ Err = "";
			this->Snpt_Replacer->Reload();
			if (!this->Snpt_Replacer->Load_XmlFile(Path))
			{
				System::Windows::Forms::MessageBox::Show("Error Reading XML", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			}
			else
			{
				this->Enable_Add = false;
				this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
				this->toolStripStatusLabel1->Text = "Ready";
				this->richTextBox1->Text = "";
				this->richTextBox2->Text = "";
				this->Refresh_Tree();
			}
		 }
private: System::Void New_snpt_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->richTextBox1->Text = "";
			 this->richTextBox2->Text = "";
			 this->BugReportTxt->Text = "";
			 this->SnippitTypeCombo->Text = "";
			 this->TRAQBox->Text = "";
			 this->JustificationBox->Text = "";
			 this->SWLabel->Text = "SW Version: ";
			 this->IsReplaceCheck->Checked = false;
			 this->IsReusedCheck->Checked = false;
			 this->comboBox1->Text = "";
			 this->treeView1->Refresh();
			 this-> Enable_Add = true;
			 this->toolStripStatusLabel1->Text = "Ready to Add Snippit";
			 this->Add_button->BackColor = System::Drawing::Color::Green;
		 }
private: System::Void Add_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 System::String^ BugNum;
			 System::String^ TRQ;
			 if(this->richTextBox1->Text->Equals("") || this->richTextBox2->Text->Equals(""))
			 {
				 System::Windows::Forms::MessageBox::Show("Cannot Take Empty String as input","Error",System::Windows::Forms::MessageBoxButtons::OK, 
					 System::Windows::Forms::MessageBoxIcon::Error);
				 return;
			 }
			 if (CheckSnptValidity() && this->Enable_Add)
			 {
				 if (!this->SnippitTypeCombo->Text->Equals("Bug_Report"))
				 {
					 BugNum = "NA";
					 TRQ = "NA";
				 }
				 else
				 {
					 BugNum = this->BugReportTxt->Text;
					 TRQ = this->TRAQBox->Text;
				 }
				 this->Snpt_Replacer->IncrementID();
				 this->Snpt_Replacer->Create_Snippit(this->richTextBox1->Text, this->richTextBox2->Text, this->SnippitTypeCombo->Text, this->comboBox1->Text, BugNum, this->JustificationBox->Text,
					 SWVersion.ToString(), "0", "0", TRQ);
				this->Refresh_Tree();
				this-> Enable_Add = false;
				this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
				this->toolStripStatusLabel1->Text = "New Snippit Added";
				this->Add_File_ToCombo(this->comboBox1->Text);
				IsSaveRequired = true;
			 }
			 else
			 {
				 if (!CheckSnptValidity())
				 {
					 System::Windows::Forms::MessageBox::Show("Please Complete all Snippet attributes","Error",System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				 }
				 else
				 {
					 System::Windows::Forms::MessageBox::Show("Please Create New Snippit First","Error",System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				 }
			 }
		 }
private: System::Void Delete_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			try{if(this->treeView1->SelectedNode == nullptr){throw 1;}}catch(int x){return;}
			System::String^ loc_Text = this->treeView1->SelectedNode->Text;
			Match^ Num_match = this->pat_num->Match(loc_Text);
			System::String^ Number = Num_match->Groups[1]->Value;
			if(System::Windows::Forms::MessageBox::Show("Are you sure you Want to Delete this Snippit","Important",System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
			{
				if(!(Number->Equals("")))
				{
				 unsigned short Num = int::Parse(Number);
				 this->Snpt_Replacer->Delete_Snippit(Num);
				 this->richTextBox1->Text = "";
				 this->richTextBox2->Text = "";
				 this->BugReportTxt->Text = "";
				 this->SnippitTypeCombo->Text = "";
				 this->TRAQBox->Text = "";
				 this->JustificationBox->Text = "";
				 this->IsReplaceCheck->Checked = false;
				 this->IsReusedCheck->Checked = false;
				 this->SWLabel->Text = "SW Version: ";
				}
				else
				{
				 /* Do Nothing*/
				}
				this->Refresh_Tree();
				this->toolStripStatusLabel1->Text = "Snippit Deleted";
				IsSaveRequired = true;
			}
			this-> Enable_Add = false;
			this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
		 }
private: System::Void Edit_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 try{if(this->treeView1->SelectedNode == nullptr){throw 1;}}catch(int x){return;}
			 System::String^ loc_Text = this->treeView1->SelectedNode->Text;
			 Match^ Num_match = this->pat_num->Match(loc_Text);
			 System::String^ Number = Num_match->Groups[1]->Value;

			 array<System::String^>^ loc_data = gcnew array<System::String^>{this->richTextBox1->Text, this->richTextBox2->Text, this->SnippitTypeCombo->Text, this->comboBox1->Text, Number, BugReportTxt->Text, 
				 JustificationBox->Text, TRAQBox->Text};

			 if(!(Number->Equals("")))
			 {
				 if(System::Windows::Forms::MessageBox::Show("Are you sure you Want to Edit this Snippit","Important",System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				 {
					unsigned short Num = int::Parse(Number);
					this->Snpt_Replacer->Edit_Snippit(loc_data);
					this->Add_File_ToCombo(this->comboBox1->Text);
					IsSaveRequired = true;
				 }
				 else
				 {
					 return;
				 }
			 }
			 else
			 {
				 /* Do Nothing*/
			 }
			 this->Refresh_Tree();
			 this-> Enable_Add = false;
			 this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			 this->toolStripStatusLabel1->Text = "Snippit Edited";
		 }
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
				 {

				 }
		private: System::Void SWLabel_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void SaveBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->Snpt_Replacer->Save_file();
			IsSaveRequired = false;
		}
		private: bool CheckSnptValidity()
		{
			bool IsValid = true;
			System::String^ typ = SnippitTypeCombo->Text;
			if (SnippitTypeCombo->Text->Equals("PolySpace_1") || SnippitTypeCombo->Text->Equals("PolySpace_2"))
			{
				if (!Check_File_Name(this->comboBox1->Text))
				{
					IsValid = false;
				}
				else if (this->JustificationBox->Text->Length == 0)
				{
					IsValid = false;
				}
				else
				{
					// Nothing
				}
			}
			else if (SnippitTypeCombo->Text->Equals("Bug_Report"))
			{
				if (!Check_File_Name(this->comboBox1->Text))
				{
					IsValid = false;
				}
				else if (this->JustificationBox->Text->Length == 0)
				{
					IsValid = false;
				}
				else if (this->BugReportTxt->Text->Length == 0)
				{
					IsValid = false;
				}
				else if (this->TRAQBox->Text->Length == 0)
				{
					IsValid = false;
				}
				else
				{
					// Nothing
				}
			}
			else{}

			return IsValid;
		}
	private: System::Void SnippitTypeCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (this->SnippitTypeCombo->SelectedIndex != 2)
		{
			this->BugReportTxt->Text = "";
			this->BugReportTxt->Enabled = false;
			this->TRAQBox->Text = "";
			this->TRAQBox->Enabled = false;
		}
		else
		{
			this->BugReportTxt->Enabled = true;
			this->TRAQBox->Enabled = true;
		}
	}
private: System::Void Snippet_Config_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
{
	if (IsSaveRequired)
	{
		if (System::Windows::Forms::MessageBox::Show("Do You Want to Save your Changes?", "Save Required", System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			this->Snpt_Replacer->Save_file();
			IsSaveRequired = false;
		}
	}
}
	private: System::Void LoadSnptBtn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->XML_FileDialog->ShowDialog();
		if (this->XML_FileDialog->FileName->EndsWith(".xml"))
		{
			if (!(this->Snpt_Replacer->Load_XmlFile(this->XML_FileDialog->FileName, SWVersion)))
			{
				System::Windows::Forms::MessageBox::Show("Invalid XML file Format", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				return;
			}
			else
			{
				this->RefillTree();
				this->Load_File_Names();
				this->toolStripStatusLabel1->Text = "XML Loaded Succesfully";
			}
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("Please Choose a Snippets XML file", "Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}
	}
};
}
