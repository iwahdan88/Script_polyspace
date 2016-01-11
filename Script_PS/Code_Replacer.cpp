#include "stdafx.h"
#include "Code_Replacer.h"

using namespace Main_package;
using namespace System::Text::RegularExpressions;
using namespace System::IO;
using namespace System::Xml;
using namespace System::Text;

Replacer::Replacer(System::String^ XMLPath)
	{
		Snippit_Count = 0;
		MaximumID = 0;
		PathofXml = XMLPath;
		Snippits = gcnew System::Collections::Generic::List < Main_package::Snippit^ >();
		SnippetDataSet = gcnew System::Data::DataSet("SnippetList");
		System::Data::DataTable^ Table = gcnew System::Data::DataTable("Snippet");
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
		SnippetDataSet->Tables[0]->Columns->Add(gcnew System::Data::DataColumn("Include"));

		this->XmlFile = gcnew System::Xml::XmlDocument();
	}
bool Replacer::Load_XmlFile(System::String^ File_Path, double CurrVer)
{
	this->XmlFile->Load(File_Path);
	XmlNodeList^ elemList;
	XmlElement^ root = XmlFile->DocumentElement;
	System::String^ IsSnippetReuesed;
	double LoadedVer = 0;
	bool Include;

	try
	{
		elemList = root->GetElementsByTagName("Snippet");
		/*Clear Data*/
		this->Reload();
		Snippit_Count = elemList->Count;
		for (int i = 0; i < Snippit_Count; i++)
		{
			try
			{
				LoadedVer = double::Parse((elemList->Item(i)->ChildNodes->Item(8)->InnerText));
			}
			catch (System::Exception^ e)
			{
				LoadedVer = 0;
			}
			if (LoadedVer < CurrVer)
			{
				IsSnippetReuesed = "1";
			}
			else
			{
				IsSnippetReuesed = "0";
			}
			SnippetDataSet->Tables[0]->Rows->Add(gcnew array < System::String^ > {(elemList->Item(i)->ChildNodes->Item(0)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(1)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(2)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(3)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(4)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(5)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(6)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(7)->InnerText),
				IsSnippetReuesed,
				(elemList->Item(i)->ChildNodes->Item(9)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(10)->InnerText)});

				if ((elemList->Item(i)->ChildNodes->Item(11)->InnerText)->Equals("YES"))
				{
					Include = true;
				}
				else
				{
					Include = false;
				}

			Snippits->Add(gcnew Snippit(SnippetDataSet->Tables[0]->Rows[i]->ItemArray[0]->ToString(), this->SnippetDataSet->Tables[0]->Rows[i]->ItemArray[1]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[2]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[3]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[4]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[5]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[6]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[7]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[8]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[9]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[10]->ToString(), Include));

		}

		FindMaxId();
	}
	catch (System::Exception^ exeption)
	{
		return false;
	}
	return true;
}
bool Replacer::Load_XmlFile(System::String^ File_Path)
{
	this->XmlFile->Load(File_Path);
	XmlNodeList^ elemList;
	XmlElement^ root = XmlFile->DocumentElement;
	bool Include;

	try
	{
		elemList = root->GetElementsByTagName("Snippet");
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
				(elemList->Item(i)->ChildNodes->Item(10)->InnerText),
				(elemList->Item(i)->ChildNodes->Item(11)->InnerText)});

			if ((elemList->Item(i)->ChildNodes->Item(11)->InnerText)->Equals("YES"))
			{
				Include = true;
			}
			else
			{
				Include = false;
			}

			Snippits->Add(gcnew Snippit(SnippetDataSet->Tables[0]->Rows[i]->ItemArray[0]->ToString(), this->SnippetDataSet->Tables[0]->Rows[i]->ItemArray[1]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[2]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[3]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[4]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[5]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[6]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[7]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[8]->ToString(), SnippetDataSet->Tables[0]->Rows[i]->ItemArray[9]->ToString(),
				SnippetDataSet->Tables[0]->Rows[i]->ItemArray[10]->ToString(), Include));

		}

		FindMaxId();
	}
	catch (System::Exception^ exeption)
	{
		return false;
	}
	return true;
}
void Replacer::Create_Snippit(System::String^ snpt_original, System::String^ snpt_replacment, System::String^ Type, System::String^ FileName,
							  System::String^ Snpt_BugRprt, System::String^ Justification, System::String^ Version,
							  System::String^ IsReuese, System::String^ IsReplace, System::String^ TRAQ)
	{
		Snippit_Count++;
		Snippits->Add(gcnew Snippit(snpt_original, snpt_replacment, Type, FileName, this->MaximumID.ToString(), Snpt_BugRprt, Justification, Version, IsReuese, IsReplace, TRAQ, true));
	}
	void Replacer::Refresh_File()
	{
		System::String^ snptype;
		System::String^ IsReues = "0";
		System::String^ IsReplaced = "0";
		System::String^ BugNum;
		/*Clear DataSet*/
		SnippetDataSet->Clear();
		System::String^ Include;

		System::String^ File = "";
		for(int i=0;i < Snippit_Count;i++)
		{
			/*Rule Out any Corrupted Snippets*/
			if(Snippits[i]->Get_Original() == nullptr)
			{
				break;
			}

			BugNum = Snippits[i]->GetBugReportNum().ToString();

			if (Snippits[i]->IsSnippetReplaced())
			{
				IsReplaced = "1";
			}
			if (Snippits[i]->IsSnippetReused())
			{
				IsReues = "1";
			}
			switch (Snippits[i]->GetSnippetType())
			{
			case SnippitType::PolySpace_1:
				snptype = "PolySpace_1";
				break;
			case SnippitType::PolySpace_2:
				snptype = "PolySpace_2";
				break;
			case SnippitType::Bug_Report:
				snptype = "Bug_Report";
				break;
			default:
				snptype = "Unknown Type";
				break;
			}
			if (Snippits[i]->GetInclude())
			{
				Include = "YES";
			}
			else
			{
				Include = "NO";
			}
			/*Fill to DataSet*/
			SnippetDataSet->Tables[0]->Rows->Add(Snippits[i]->Get_Original(), Snippits[i]->Get_Replacment(), snptype, Snippits[i]->Get_File_Name(),
				Snippits[i]->GetID(), BugNum, Snippits[i]->Get_Snippet_Justification(), Snippits[i]->GetSW_Version(), IsReues, IsReplaced, Snippits[i]->GetBugTRAQ(), Include);
			
		}
		// Create the FileStream to write with.
		System::IO::FileStream^ stream = gcnew System::IO::FileStream
			(PathofXml, System::IO::FileMode::Create, System::IO::FileAccess::Write, System::IO::FileShare::None, 4096, false);
		SnippetDataSet->WriteXml(stream, System::Data::XmlWriteMode::IgnoreSchema);
		stream->Close();
	}
	void Replacer::Delete_Snippit(unsigned short Snpt_number)
	{
		int Index = 0;
		bool Found = false;
		/*Find Index of tSnippit with passed ID*/
		{
			for (int i = 0; i < Snippit_Count; i++)
			{
				if (int::Parse(Snippits[i]->GetID()) == Snpt_number)
				{
					Index = i;
					Found = true;
				}
			}
		}
		if (Found)
		{
			Snippits->RemoveAt(Index);
			Snippit_Count--;
			FindMaxId();
		}
	}
	array<System::String^>^ Replacer::Get_snippitByID(unsigned short Snpt_number)
	{
		System::String^ snptype;
		System::String^ IsReues = "NO";
		System::String^ IsReplaced = "NO";
		int i;
		System::String^ Include;
		//Get Index of Snippet in List
		for (i = 0; i < Get_Snpt_Count(); i++)
		{
			if (Snippits[i]->GetID()->Equals(Snpt_number.ToString()))
			{
				break;
			}
		}
		if (i < Get_Snpt_Count())
		{
			System::String^ BugNum = Snippits[i]->GetBugReportNum().ToString();
			if (Snippits[i]->IsSnippetReplaced())
			{
				IsReplaced = "YES";
			}
			if (Snippits[i]->IsSnippetReused())
			{
				IsReues = "YES";
			}
			if (Snippits[i]->GetInclude())
			{
				Include = "YES";
			}
			else
			{
				Include = "NO";
			}
			switch (Snippits[i]->GetSnippetType())
			{
			case SnippitType::PolySpace_1:
				snptype = "PolySpace_1";
				break;
			case SnippitType::PolySpace_2:
				snptype = "PolySpace_2";
				break;
			case SnippitType::Bug_Report:
				snptype = "Bug_Report";
				break;
			default:
				snptype = "Unknown Type";
				break;
			}
			array<System::String^>^Snippit = { Snippits[i]->Get_Original(), Snippits[i]->Get_Replacment(), Snippits[i]->Get_File_Name(), snptype,
				Snippits[i]->Get_Snippet_Justification(), Snippits[i]->GetSW_Version(), IsReues, IsReplaced, Snippits[i]->GetBugTRAQ(), Snippits[i]->GetID(),
				BugNum, Include };
			return Snippit;
		}
		return nullptr;
	}
	array<System::String^>^ Replacer::Get_snippit(unsigned short Snpt_number)
	{
		System::String^ snptype;
		System::String^ IsReues = "NO";
		System::String^ IsReplaced = "NO";
		System::String^ Include ;

		System::String^ BugNum = Snippits[Snpt_number]->GetBugReportNum().ToString();
		if (Snippits[Snpt_number]->IsSnippetReplaced())
		{
			IsReplaced = "YES";
		}
		if (Snippits[Snpt_number]->IsSnippetReused())
		{
			IsReues = "YES";
		}
		if (Snippits[Snpt_number]->GetInclude())
		{
			Include = "YES";
		}
		else
		{
			Include = "NO";
		}
		switch (Snippits[Snpt_number]->GetSnippetType())
		{
		case SnippitType::PolySpace_1:
			snptype = "PolySpace_1";
			break;
		case SnippitType::PolySpace_2:
			snptype = "PolySpace_2";
			break;
		case SnippitType::Bug_Report:
			snptype = "Bug_Report";
			break;
		default:
			snptype = "Unknown Type";
			break;
		}
		array<System::String^>^Snippit = { Snippits[Snpt_number]->Get_Original(), Snippits[Snpt_number]->Get_Replacment(), Snippits[Snpt_number]->Get_File_Name(), snptype,
			Snippits[Snpt_number]->Get_Snippet_Justification(), Snippits[Snpt_number]->GetSW_Version(), IsReues, IsReplaced, Snippits[Snpt_number]->GetBugTRAQ(), Snippits[Snpt_number]->GetID(),
			BugNum, Include };
		return Snippit;
	}
	void Replacer::Edit_Snippit(array<System::String^>^ snpt)
	{
		int index = 0;
		SnippitType Type;
		bool Include;
		if (snpt[2]->Equals("PolySpace_1"))
		{
			Type = SnippitType::PolySpace_1;
		}
		else if (snpt[2]->Equals("PolySpace_2"))
		{
			Type = SnippitType::PolySpace_2;
		}
		else if (snpt[2]->Equals("Bug_Report"))
		{
			Type = SnippitType::Bug_Report;
		}
		else
		{
			Type = SnippitType::UnknownType;
		}
		if (snpt[8]->Equals("YES"))
		{
			Include = true;
		}
		else
		{
			Include = false;
		}
		/*Find Index of Snippet*/
		for (index = 0; index < Snippit_Count; index++)
		{
			if (Snippits[index]->GetID()->Equals(snpt[4]))
			{
				Snippits[index]->Set_Original(snpt[0]);
				Snippits[index]->Set_Replacment(snpt[1]);
				Snippits[index]->SetSnippetType(Type);
				Snippits[index]->Set_File_Name(snpt[3]);
				if (!(snpt[5]->Equals("")))
				{
					Snippits[index]->SetBugReportNum(int::Parse(snpt[5]));
					Snippits[index]->Set_BugTRAQ(snpt[7]);
				}
				Snippits[index]->Set_Snippet_Justification(snpt[6]);
				Snippits[index]->SetInclude(Include);
				break;
			}
		}
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
	int Replacer::GetMaxID(void)
	{
		return this->Replacer::MaximumID;
	}
	void Replacer::Save_file(void)
	{
		Refresh_File();
	}
	int Replacer::Get_Snpt_Count(void)
	{
		return Snippit_Count;
	}
	void Replacer::Reload(void)
	{
		Snippit_Count = 0;
		/*Clear Snippits List*/
		Snippits->Clear();
		SnippetDataSet->Clear();
	}
	void Replacer::FindMaxId()
	{
		int MaxId = 0;
		for (int i = 0; i < Snippit_Count; i++)
		{
			if (int::Parse(Snippits[i]->GetID()) > MaxId)
			{
				MaxId = int::Parse(Snippits[i]->GetID());
			}

			MaximumID = MaxId;
		}
	}
	void Replacer::IncrementID(void)
	{
		this->MaximumID++;
	}