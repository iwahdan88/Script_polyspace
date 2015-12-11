#include "stdafx.h"
#include "Keyword_Replacer.h"

using namespace Main_package;
using namespace System::Text::RegularExpressions;
using namespace System::IO;

	Keyword_Replacer::Keyword_Replacer(void)
	{
		Snippit_Count = 0;
		File_Path = "";
		Keywords = gcnew array<Main_package::Snippit^>(MAX_NB_KWD);
		Er = Valid_KW;
		Error_Line = -1;
		for(int i=0;i<MAX_NB_KWD;i++)
		{
			Keywords[i] = gcnew Main_package::Snippit();
		}
	}
	bool Keyword_Replacer::Load_File(System::String^ File_Path)
	{
		Keyword_Replacer::File_Path = File_Path;
		File_Array = System::IO::File::ReadAllLines(File_Path);
		if (File_Array->Length == 0)
		{
			return true;
		}
		bool Is_File_Valid = Keyword_Replacer::Validate_File();
		if(!Is_File_Valid)
		{
			return false;
		}
		array<System::String^>^ split;
		array<System::String^>^ delimstr = gcnew array<System::String^>{"<>"};
		Match^ FileName;
		System::String^ Filename;
		Regex^ pat = gcnew Regex ("\\=\\>\\s*(.[^\\.]*\\.[cC])");
		Regex^ pat2 = gcnew Regex ("\\=\\>\\s*.[^\\.]*\\.[cC]");
		for(int i = 0;i<File_Array->Length;i++)
		{
			if(File_Array[i]->Equals("Keywords:") || File_Array[i]->Equals("ENDKeywords") ||Regex::IsMatch(File_Array[i], "^[\\t\\s]*$"))
			{
				continue;
			}
			Snippit_Count++;
			FileName = pat->Match(File_Array[i]);
			Filename = FileName->Groups[1]->Value;
			Keywords[Snippit_Count - 1]->Set_File_Name(Filename);
			split = File_Array[i]->Split(delimstr,2,System::StringSplitOptions::None);
			Keywords[Snippit_Count - 1]->Set_Original(System::String::Concat(Keywords[Snippit_Count -1]->Get_Original(), split[0]));
			Keywords[Snippit_Count -1]->Set_Replacment(System::String::Concat(Keywords[Snippit_Count -1]->Get_Replacment(), split[1]));
			Keywords[Snippit_Count -1]->Set_Replacment((pat2->Replace(Keywords[Snippit_Count -1]->Get_Replacment(), "")));
		}
		return true;
	}
	void Keyword_Replacer::Create_Snippit(System::String^ snpt_original, System::String^ snpt_replacment, System::String^ FileName)
	{
		Snippit_Count++;
		Keywords[Snippit_Count - 1]->Set_Original(snpt_original);
		Keywords[Snippit_Count - 1]->Set_Replacment(snpt_replacment);
		Keywords[Snippit_Count - 1]->Set_File_Name(FileName);
		Keyword_Replacer::Refresh_File();
	}
	void Keyword_Replacer::Refresh_File()
	{
		System::String^ File = "Keywords:\n";
		for(int i=0;i < Snippit_Count;i++)
		{
			if(Keywords[i]->Get_Original() == nullptr)
			{
				break;
			}
			File = System::String::Concat(File,Keywords[i]->Get_Original() + "<>");
			File = System::String::Concat(File,Keywords[i]->Get_Replacment());
			File = File + " => " + Keywords[i]->Get_File_Name() + "\n";
			
		}
		File = System::String::Concat(File,"ENDKeywords");
		System::IO::File::WriteAllText(Keyword_Replacer::File_Path, File);
	}
	void Keyword_Replacer::Delete_Snippit(unsigned short Snpt_number)
	{
		Keywords[Snpt_number]->Set_Original("NULL");
		Keywords[Snpt_number]->Set_Replacment("NULL");
		Keywords[Snpt_number]->Set_File_Name("NULL");
		Sort_Data();
		Refresh_File();
	}
	array<System::String^>^ Keyword_Replacer::Get_snippit(unsigned short Snpt_number)
	{
		array<System::String^>^ Snippit = {Keywords[Snpt_number]->Get_Original(), Keywords[Snpt_number]->Get_Replacment(), Keywords[Snpt_number]->Get_File_Name()};
		return Snippit;
	}
	void Keyword_Replacer::Edit_Snippit(array<System::String^>^ snpt, unsigned short Snpt_number)
	{
		Keywords[Snpt_number]->Set_Original(snpt[0]);
		Keywords[Snpt_number]->Set_Replacment(snpt[1]);
		Keywords[Snpt_number]->Set_File_Name(snpt[2]);
		Refresh_File();
	}
	bool Keyword_Replacer::Contains(System::String^ pattern, array<System::String^>^ snpt)
	{
		Regex^ mypattern = gcnew Regex(pattern);
		if((mypattern->Match(snpt[0])) || (mypattern->Match(snpt[1])))
		{
			return true;
		}
		return false;
	}
	void Keyword_Replacer::Save_file(void)
	{
		Refresh_File();
	}
	void Keyword_Replacer::Delete_file(void)
	{
		System::IO::File::WriteAllText(Keyword_Replacer::File_Path, "");
	}
	int Keyword_Replacer::Get_Snpt_Count(void)
	{
		return Snippit_Count;
	}
	void Keyword_Replacer::Reload(void)
	{
		Snippit_Count = 0;
		for(int i=0;i < MAX_NB_KWD;i++)
		{
			if((Keywords[i]->Get_Original() == nullptr) && (Keywords[i]->Get_Replacment() == nullptr))
			{
				break;
			}
			else
			{
				Keywords[i]->Set_Original("NULL");
				Keywords[i]->Set_Replacment("NULL");
				Keywords[i]->Set_File_Name("NULL");
				Keywords[i]->ByPass(false);

			}
		}
	}
	void Keyword_Replacer::Sort_Data()
	{
		bool null = false;
		for(int i =0;i< Snippit_Count;i++)
		{
			if(Keywords[i]->Get_Original() == nullptr)
			{
				if(i == (Snippit_Count) - 1)
				{
					break;
				}
				null = true;
				Keywords[i]->Set_Original(Keywords[i+1]->Get_Original());
				Keywords[i]->Set_Replacment(Keywords[i+1]->Get_Replacment());
				Keywords[i]->Set_File_Name(Keywords[i+1]->Get_File_Name());
				continue;
			}
			else if (null)
			{
				if(i == (Snippit_Count) - 1)
				{
					Keywords[i]->Set_Original("NULL");
					Keywords[i]->Set_Replacment("NULL");
					Keywords[i]->Set_File_Name("NULL");
				}
				else
				{
					Keywords[i]->Set_Original(Keywords[i+1]->Get_Original());
					Keywords[i]->Set_Replacment(Keywords[i+1]->Get_Replacment());
					Keywords[i]->Set_File_Name(Keywords[i+1]->Get_File_Name());
				}
			}
			else
			{
				/* Continue */
			}
		}
		 Snippit_Count --;
	}
	bool Keyword_Replacer::Validate_File(void)
	{
		bool End = false;
		unsigned char delim = 0;
		Er = Valid_KW;
		int j =0;
		while(!File_Array[j]->Equals("Keywords:"))
		{
			if(j == File_Array->Length -1)
			{
				break;
			}
			else if(Regex::IsMatch(File_Array[j], "^[\\t\\s]*$"))
			{
				j++;
				continue;
			}
			else
			{
				Er = Line_Error_KW_End;
				return false;
			}
		}
		    
		for(int i = 0;i<File_Array->Length;i++)
		{
			if(File_Array[i]->Equals("Keywords:") || Regex::IsMatch(File_Array[i], "^[\\t\\s]*$"))
			{
				continue;
			}
			if(File_Array[i]->Equals("ENDKeywords"))
			{
				End = true;
				break;
			}
			if(!(Regex::IsMatch(File_Array[i], "\\s*\\=\\>\\s*.[^\\.]*\\.[cC]$")))
			{
				Er = Line_Error_KW_End;
				Error_Line = i + 1;
				return false;
			}
			else if(!(Regex::IsMatch(File_Array[i], "\\<\\>")))
			{
				delim++;
				if(delim > 0)
				{
					Er = Line_Error_KW_delim;
					Error_Line = i + 1;
					return false;
				}
				delim = 0;
			}
		}
		if(!End)
		{
			Er = Line_Error_KW_End;
		}
		Er = Valid_KW;
		return true;
	}
	File_Error_KW Keyword_Replacer::Get_Err(void)
	{
		return Er;
	}
	unsigned long Keyword_Replacer::Get_Err_Line(void)
	{
		return Error_Line;
	}
	unsigned long Keyword_Replacer::Get_File_Length(void)
	{
		return File_Array->Length;
	}