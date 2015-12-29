#include "stdafx.h"
#include "Code_Replacer.h"

using namespace Main_package;
using namespace System::Text::RegularExpressions;
using namespace System::IO;
using namespace System::Xml;

Replacer::Replacer(void)
	{
		Snippit_Count = 0;
		File_Path = "";
		File_Names = gcnew array<System::String^>(Max_NB_Files);
		Snippits = gcnew System::Collections::Generic::List < Main_package::Snippit^ >();
		SnippetDataSet = gcnew System::Data::DataSet();
		System::Data::DataTable^ Table = gcnew System::Data::DataTable("SnippetList");
		SnippetDataSet->Tables->Add(Table);
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("Original"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("Replacment"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("Type"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("File"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("SnippitID"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("BugReportNum"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("WorkAroundJustification"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("SW_Version"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("IsReused"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("IsReplaced"));
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("BugTRAQ"));

		this->XmlFile = gcnew System::Xml::XmlDocument();
	}
bool Replacer::Load_XmlFile(System::String^ File_Path)
{
	this->XmlFile->Load(File_Path);
	XmlNodeList^ elemList;
	XmlElement^ root = XmlFile->DocumentElement;
	try
	{
		elemList = root->GetElementsByTagName("Snippit");
		Snippit_Count = elemList->Count;
		for (int i = 0; i < Snippit_Count; i++)
		{
			SnippetDataSet->Tables[0]->Rows->Add(gcnew array < System::String^ > {(elemList->Item(i)->ChildNodes->Item(0)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(1)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(2)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(3)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(4)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(5)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(6)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(7)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(8)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(9)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(10)->InnerText)});

			Snippits->Add(gcnew Snippit(SnippetDataSet->Tables[0]->Rows[i]->ItemArray[0]->ToString(), this->SnippetDataSet->Tables[0]->Rows[i]->ItemArray[1]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[2]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[3]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[4]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[5]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[6]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[7]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[8]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[9]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[10]->ToString()));

		}
	}
	catch (System::Exception^ exeption)
	{
		return false;
	}
	return true;
}
	void Replacer::Create_Snippit(System::String^ snpt_original, System::String^ snpt_replacment, System::String^ FileName)
	{
		Snippit_Count++;
		Snippits[Snippit_Count - 1]->Set_Original(snpt_original);
		Snippits[Snippit_Count - 1]->Set_Replacment(snpt_replacment);
		Snippits[Snippit_Count - 1]->Set_File_Name(FileName);
		Replacer::Refresh_File();
	}
	void Replacer::Refresh_File()
	{
		System::String^ File = "";
		for(int i=0;i < Snippit_Count;i++)
		{
			if(Snippits[i]->Get_Original() == nullptr)
			{
				break;
			}
			File = System::String::Concat(File,Snippits[i]->Get_Original() + "<>");
			//File = File + "\n";
			File = System::String::Concat(File,Snippits[i]->Get_Replacment());
			if(((i+1) < MAX_NB_SNPT) && (Snippits[i+1]->Get_Original() == nullptr))
			{
				File = File + "\nENDERROR => " + Snippits[i]->Get_File_Name();
			}
			else
			{
				File = File + "\nENDERROR => " + Snippits[i]->Get_File_Name() + "\n";
			}
			
		}
		System::IO::File::WriteAllText(Replacer::File_Path, File);
	}
	void Replacer::Delete_Snippit(unsigned short Snpt_number)
	{
		Snippits[Snpt_number]->Set_Original("NULL");
		Snippits[Snpt_number]->Set_Replacment("NULL");
		Snippits[Snpt_number]->Set_File_Name("NULL");
		//Snippits[Snpt_number]->ByPass(true);
		Sort_Data();
		Refresh_File();
	}
	array<System::String^>^ Replacer::Get_snippit(unsigned short Snpt_number)
	{
		System::String^ snptype;
		System::String^ IsReues = "NO";
		System::String^ IsReplaced = "NO";
		System::String^ BugNum = Snippits[Snpt_number]->GetBugReportNum().ToString();
		if (Snippits[Snpt_number]->IsSnippetReplaced())
		{
			IsReplaced = "YES";
		}
		if (Snippits[Snpt_number]->IsSnippetReused())
		{
			IsReues = "YES";
		}
		switch (Snippits[Snpt_number]->GetSnippetType())
		{
			case SnippitType::PolySpace_1:
				snptype = "Polyspace_1";
				break;
			case SnippitType::PolySpace_2:
				snptype = "Polyspace_2";
				break;
			case SnippitType::Bug_Report:
				snptype = "Bug_Report";
				break;
			default:
				snptype = "Unknown Type";
				break;
		}
		array<System::String^>^ Snippit = { Snippits[Snpt_number]->Get_Original(), Snippits[Snpt_number]->Get_Replacment(), Snippits[Snpt_number]->Get_File_Name(), snptype, 
			Snippits[Snpt_number]->Get_Snippet_Justification(), Snippits[Snpt_number]->GetSW_Version(), IsReues, IsReplaced, Snippits[Snpt_number]->GetBugTRAQ(), Snippits[Snpt_number]->GetID(),
			BugNum };
		return Snippit;
	}
	void Replacer::Edit_Snippit(array<System::String^>^ snpt, unsigned short Snpt_number)
	{
		Snippits[Snpt_number]->Set_Original(snpt[0]);
		Snippits[Snpt_number]->Set_Replacment(snpt[1]);
		Snippits[Snpt_number]->Set_File_Name(snpt[2]);
		Refresh_File();
	}
	bool Replacer::Contains(System::String^ pattern, array<System::String^>^ snpt)
	{
		Regex^ mypattern = gcnew Regex(pattern);
		if((mypattern->Match(snpt[0])) || (mypattern->Match(snpt[1])))
		{
			return true;
		}
		return false;
	}
	void Replacer::Save_file(void)
	{
		Refresh_File();
	}
	void Replacer::Delete_file(void)
	{
		System::IO::File::WriteAllText(Replacer::File_Path, "");
	}
	int Replacer::Get_Snpt_Count(void)
	{
		return Snippit_Count;
	}
	void Replacer::Reload(void)
	{
		Snippit_Count = 0;
		for(int i=0;i < MAX_NB_SNPT;i++)
		{
			if((Snippits[i]->Get_Original() == nullptr) && (Snippits[i]->Get_Replacment() == nullptr))
			{
				break;
			}
			else
			{
				Snippits[i]->Set_Original("NULL");
				Snippits[i]->Set_Replacment("NULL");
				Snippits[i]->Set_File_Name("NULL");
				Snippits[i]->ByPass(false);

			}
		}
	}
	void Replacer::Sort_Data()
	{
		bool null = false;
		for(int i =0;i< Snippit_Count;i++)
		{
			if(Snippits[i]->Get_Original() == nullptr)
			{
				if(i == (Snippit_Count) - 1)
				{
					break;
				}
				null = true;
				Snippits[i]->Set_Original(Snippits[i+1]->Get_Original());
				Snippits[i]->Set_Replacment(Snippits[i+1]->Get_Replacment());
				Snippits[i]->Set_File_Name(Snippits[i+1]->Get_File_Name());
				continue;
			}
			else if (null)
			{
				if(i == (Snippit_Count) - 1)
				{
					Snippits[i]->Set_Original("NULL");
					Snippits[i]->Set_Replacment("NULL");
					Snippits[i]->Set_File_Name("NULL");
				}
				else
				{
					Snippits[i]->Set_Original(Snippits[i+1]->Get_Original());
					Snippits[i]->Set_Replacment(Snippits[i+1]->Get_Replacment());
					Snippits[i]->Set_File_Name(Snippits[i+1]->Get_File_Name());
				}
			}
			else
			{
				/* Continue */
			}
		}
		 Snippit_Count --;
	}