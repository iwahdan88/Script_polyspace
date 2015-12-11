#pragma once

#include "Code_Replacer.h"
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
		Snippet_Config(System::String^ Path, System::String^ Path_files)
		{
			Snpt_Replacer = gcnew Main_package::Replacer(Path_files);
			InitializeComponent();
			if(!this->Snpt_Replacer->Load_File(Path))
			{
				System::String^ error = "";
				if(this->Snpt_Replacer->Get_Err() == Line_Error_delim)
				{
					error = "there Must be an \"ENDERROR=>FileName.c\"\nKeyword after Code separated in Line " + this->Snpt_Replacer->Get_Err_Line();
					System::Windows::Forms::MessageBox::Show("File \"red_errors.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					delete this;
					return;
				}
				else if(this->Snpt_Replacer->Get_Err() == Unresolved_lines)
				{
					error = "Some Lines at the end of \"red_errors.pm\" file are Wrongly Formatted";
					System::Windows::Forms::MessageBox::Show(error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					delete this;
					return;
				}
				else if(this->Snpt_Replacer->Get_Err() == Line_Error_End)
				{
					error = "there Must be a Delimiter \"<>\"\nBefore \"ENDERROR=>FileName.c\" Keyword in Line " + this->Snpt_Replacer->Get_Err_Line();
					System::Windows::Forms::MessageBox::Show("File \"red_errors.pm\" is Corrupted" + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					delete this;
					return;
				}
			}
			else if(this->Snpt_Replacer->Get_File_Length() == 0)
			{
				this->Path = Path;
				this->Enable_Add = false;
				this->Is_File_Name_Entered = false;
				this->pat_num = gcnew Regex ("([0-9]+)");
				return;
			}
			this->Path = Path;
			this->Enable_Add = false;
			this->Is_File_Name_Entered = false;
			this->pat_num = gcnew Regex ("([0-9]+)");
			this->Fill_Tree();
			this->Load_File_Names();
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
	protected: 





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label4;
	private: Main_package::Replacer^ Snpt_Replacer;
	private: Regex^ pat_num;
	private: System::Windows::Forms::Button^  Refresh;

	private: System::String^ Path;
	private: System::Windows::Forms::Button^  New_snpt;
	private: array<System::Windows::Forms::TreeNode^>^ Snpts;
	private: TreeNode^ Global;
	private: bool Enable_Add;
	private: bool Is_File_Name_Entered;
	private: ScintillaNET::Scintilla^  richTextBox1;
	private: ScintillaNET::Scintilla^  richTextBox2;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  SnippitTypeCombo;
	private: System::Windows::Forms::Label^  SnippiyTypeLabel;
	private: System::Windows::Forms::TextBox^  BugReportTxt;

	private: System::Windows::Forms::Label^  BugReportNumLbl;





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
			this->richTextBox1->Size = System::Drawing::Size(600, 500);
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
			this->richTextBox2->Size = System::Drawing::Size(600, 500);
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
			this->statusStrip1->Size = System::Drawing::Size(1368, 22);
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
			this->BugReportTxt->Location = System::Drawing::Point(919, 14);
			this->BugReportTxt->Name = L"BugReportTxt";
			this->BugReportTxt->Size = System::Drawing::Size(50, 20);
			this->BugReportTxt->TabIndex = 20;
			// 
			// BugReportNumLbl
			// 
			this->BugReportNumLbl->AutoSize = true;
			this->BugReportNumLbl->Location = System::Drawing::Point(833, 17);
			this->BugReportNumLbl->Name = L"BugReportNumLbl";
			this->BugReportNumLbl->Size = System::Drawing::Size(80, 13);
			this->BugReportNumLbl->TabIndex = 21;
			this->BugReportNumLbl->Text = L"BugReportNum";
			// 
			// Snippet_Config
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1368, 687);
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
			this->MaximizeBox = false;
			this->Name = L"Snippet_Config";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Snippet_Config";
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
				if(this->Snpt_Replacer->Get_snippit(i)[2]->Equals("") || this->comboBox1->Items->Contains(this->Snpt_Replacer->Get_snippit(i)[2]))
				{
					continue;
				}
				else
				{
					this->comboBox1->Items->Add(this->Snpt_Replacer->Get_snippit(i)[2]);
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
				Snpts[i] = gcnew TreeNode("Snippit " + i);
			}
			Global = gcnew TreeNode("Code", Snpts);
			this->treeView1->Nodes->Add(Global);
		}
		void Refresh_Tree(void)
		{
			int index = this->Snpt_Replacer->Get_Snpt_Count();
			this->Snpts = gcnew array<System::Windows::Forms::TreeNode^>(index);
			for(int i=0;i<index;i++)
			{
				Snpts[i] = gcnew TreeNode("Snippit " + i);
			}
			Global = gcnew TreeNode("Code", Snpts);
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
				 array<System::String^>^ Snpt =  this->Snpt_Replacer->Get_snippit(Num);
				 this->richTextBox1->Text = Snpt[0];
				 this->richTextBox2->Text = Snpt[1];
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
			this->Snpt_Replacer->Reload();
			if(!this->Snpt_Replacer->Load_File(Path))
			{
				System::String^ error = "";
				if(this->Snpt_Replacer->Get_Err() == Line_Error_delim)
				{
					error = "there Must be an \"ENDERROR=>FileName.c\"\nKeyword after Code separated in Line " + this->Snpt_Replacer->Get_Err_Line();
					System::Windows::Forms::MessageBox::Show("File \"red_errors.pm\" is Corrupted, " + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					return;
				}
				else if(this->Snpt_Replacer->Get_Err() == Unresolved_lines)
				{
					error = "Some Lines at the end of \"red_errors.pm\" file are Wrongly Formatted";
					System::Windows::Forms::MessageBox::Show(error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					return;
				}
				else if(this->Snpt_Replacer->Get_Err() == Line_Error_End)
				{
					error = "there Must be a Delimiter \"<>\"\nBefore \"ENDERROR=>FileName.c\" Keyword in Line " + this->Snpt_Replacer->Get_Err_Line();
					System::Windows::Forms::MessageBox::Show("File \"red_errors.pm\" is Corrupted" + error,"Error",
					System::Windows::Forms::MessageBoxButtons::OK, 
					System::Windows::Forms::MessageBoxIcon::Error);
					return;
				}
			}
			else if(this->Snpt_Replacer->Get_File_Length() == 0)
			{
				this-> Enable_Add = false;
				this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
				this->toolStripStatusLabel1->Text = "Ready";
				this->richTextBox1->Text = "";
				this->richTextBox2->Text = "";
				this->Refresh_Tree();
				return;
			}
			this-> Enable_Add = false;
			this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
			this->toolStripStatusLabel1->Text = "Ready";
			this->richTextBox1->Text = "";
			this->richTextBox2->Text = "";
			this->Refresh_Tree();
		 }
private: System::Void New_snpt_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->richTextBox1->Text = "";
			 this->richTextBox2->Text = "";
			 this->comboBox1->Text = "";
			 this->treeView1->Refresh();
			 this-> Enable_Add = true;
			 this->toolStripStatusLabel1->Text = "Ready to Add Snippit";
			 this->Add_button->BackColor = System::Drawing::Color::Green;
		 }
private: System::Void Add_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			/*if(this->richTextBox1->LineCount != this->richTextBox2->LineCount)
			{
				System::Windows::Forms::MessageBox::Show("There is a Difference between number of lines in Original vs replacment code !","Warning",System::Windows::Forms::MessageBoxButtons::OK, 
					 System::Windows::Forms::MessageBoxIcon::Warning);
			}*/
			 if(this->richTextBox1->Text->Equals("") || this->richTextBox2->Text->Equals(""))
			 {
				 System::Windows::Forms::MessageBox::Show("Cannot Take Empty String as input","Error",System::Windows::Forms::MessageBoxButtons::OK, 
					 System::Windows::Forms::MessageBoxIcon::Error);
				 return;
			 }
			 if(this->Enable_Add && Check_File_Name(this->comboBox1->Text))
			 {
				this->Snpt_Replacer->Create_Snippit(this->richTextBox1->Text,this->richTextBox2->Text, this->comboBox1->Text);
				this->Refresh_Tree();
				this-> Enable_Add = false;
				this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
				this->toolStripStatusLabel1->Text = "New Snippit Added";
				this->Add_File_ToCombo(this->comboBox1->Text);
			 }
			 else
			 {
				 if(!Check_File_Name(this->comboBox1->Text))
				 {
					 System::Windows::Forms::MessageBox::Show("Please Enter Correct File Name","Error",System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
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
				}
				else
				{
				 /* Do Nothing*/
				}
				this->Refresh_Tree();
				this->toolStripStatusLabel1->Text = "Snippit Deleted";
			}
			this-> Enable_Add = false;
			this->Add_button->BackColor = System::Drawing::Color::Gainsboro;
		 }
private: System::Void Edit_button_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 try{if(this->treeView1->SelectedNode == nullptr){throw 1;}}catch(int x){return;}
			 array<System::String^>^ loc_data = gcnew array<System::String^>{this->richTextBox1->Text, this->richTextBox2->Text, this->comboBox1->Text};
			 System::String^ loc_Text = this->treeView1->SelectedNode->Text;
			 Match^ Num_match = this->pat_num->Match(loc_Text);
			 System::String^ Number = Num_match->Groups[1]->Value;
			 if(!(Number->Equals("")))
			 {
				 if(System::Windows::Forms::MessageBox::Show("Are you sure you Want to Edit this Snippit","Important",System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				 {
					unsigned short Num = int::Parse(Number);
					this->Snpt_Replacer->Edit_Snippit(loc_data,Num);
					this->Add_File_ToCombo(this->comboBox1->Text);
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
};
}
