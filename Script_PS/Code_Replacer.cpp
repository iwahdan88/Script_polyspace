#include "stdafx.h"
#include "Code_Replacer.h"

using namespace Main_package;
using namespace System::Text::RegularExpressions;
using namespace System::IO;

Replacer::Replacer(System::String^ FileNamesPath)
	{
		Snippit_Count = 0;
		File_Path = "";
		Snippits = gcnew array<Main_package::Snippit^>(MAX_NB_SNPT);
		File_Names = gcnew array<System::String^>(Max_NB_Files);
		Er = Valid;
		Error_Line = -1;
		Replacer::File_Names_Path = FileNamesPath;
		for(int i=0;i<MAX_NB_SNPT;i++)
		{
			Snippits[i] = gcnew Main_package::Snippit();
		}
	}
	bool Replacer::Load_File(System::String^ File_Path)
	{
		Replacer::File_Path = File_Path;
		File_Array = System::IO::File::ReadAllLines(File_Path);
		if (File_Array->Length == 0)
		{
			return true;
		}
		bool Is_File_Valid = Replacer::Validate_File();
		if(!Is_File_Valid)
		{
			return false;
		}
		Snippit_Count = 1;
		Regex^ Delimiter = gcnew Regex("<>");
		array<System::String^>^ split;
		char Delimiter_flag  = 0;
		System::String^ nline = "\n";
		bool delim;
		array<System::String^>^ delimstr = gcnew array<System::String^>{"<>"};
		Match^ FileName;
		System::String^ Filename;
		Regex^ pat = gcnew Regex ("\\=\\>\\s*(.[^\\.]*\\.[cC])");
		for(int i = 0;i<File_Array->Length;i++)
		{
			if(Regex::IsMatch(File_Array[i], "ENDERROR"))
			{
				Snippit_Count++;
				Delimiter_flag = 0;
				nline = "\n";
				FileName = pat->Match(File_Array[i]);
				Filename = FileName->Groups[1]->Value;
				Snippits[Snippit_Count - 2]->Set_File_Name(Filename);
			}
			else
			{
				delim = Regex::IsMatch(File_Array[i], "<>");
				if(delim)
				{
					split = File_Array[i]->Split(delimstr,2,System::StringSplitOptions::None);
					if(((i+1) < File_Array->Length) && (Regex::IsMatch(File_Array[i+1], "ENDERROR")))
					{
						nline = "";
					}
					Snippits[Snippit_Count - 1]->Set_Original(System::String::Concat(Snippits[Snippit_Count -1]->Get_Original(), split[0]));
					Snippits[Snippit_Count -1]->Set_Replacment(System::String::Concat(Snippits[Snippit_Count -1]->Get_Replacment(), split[1] + nline));
					Delimiter_flag = 1;
					delim = false;
					nline = "\n";
				}
				else if(!Delimiter_flag)
				{
					if(!(File_Array[i]->Equals("\n")))
					{
						Snippits[Snippit_Count -1]->Set_Original(System::String::Concat(Snippits[Snippit_Count - 1]->Get_Original(), File_Array[i] + "\n"));
					}
				}
				else
				{
					if(!(File_Array[i]->Equals("\n")))
					{
						if(((i+1) < File_Array->Length) && (Regex::IsMatch(File_Array[i+1], "ENDERROR")))
						{
							nline = "";
						}
						Snippits[Snippit_Count - 1]->Set_Replacment(System::String::Concat(Snippits[Snippit_Count - 1]->Get_Replacment(), File_Array[i] + nline));
					}
				}
			}
		}
		Snippit_Count -= 1;
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
		Load_File_Names();
		Write_File_Names();
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
		array<System::String^>^ Snippit = {Snippits[Snpt_number]->Get_Original(), Snippits[Snpt_number]->Get_Replacment(), Snippits[Snpt_number]->Get_File_Name()};
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
	bool Replacer::Validate_File(void)
	{
		unsigned char Balance = 0;
		unsigned long tail =0;
		Er = Valid;
		for(int i = 0;i<File_Array->Length;i++)
		{
			if(Regex::IsMatch(File_Array[i], "\\<\\>"))
			{
				if(Balance > 0)
				{
					Er = Line_Error_delim;
					Error_Line = i - tail;
					return false;
				}
				Balance ++;
				tail =0;
			}
			else if(Regex::IsMatch(File_Array[i], "ENDERROR\\s+\\=\\s*\\>"))
			{
				if(Balance < 1)
				{
					Er = Line_Error_End;
					Error_Line = i + 1;
					return false;
				}
				Balance --;
				tail = 0;
			}
			else
			{
				tail++;
			}
		}
		if(tail > 0)
		{
			Er = Unresolved_lines;
			return false;
		}
		Er = Valid;
		return true;
	}
	File_Error Replacer::Get_Err(void)
	{
		return Er;
	}
	unsigned long Replacer::Get_Err_Line(void)
	{
		return Error_Line;
	}
	unsigned long Replacer::Get_File_Length(void)
	{
		return File_Array->Length;
	}
	void Replacer::Write_File_Names(void)
	{
		System::String^ file = "FILENAMES:";
		for(int i =0; i < File_Names->Length ; i++)
		{
			if(File_Names[i] == nullptr)
			{
				break;
			}
			else if(!Regex::IsMatch(File_Names[i], "\\.[cC]\\s*$"))
			{
				continue;
			}
			file = file + "\n" + File_Names[i];
		}
		file = file + "\nENDFILES";
		System::IO::File::WriteAllText(Replacer::File_Names_Path, file);
	}
	void Replacer::Load_File_Names(void)
	{
		for(int i =0;i< Snippit_Count;i++)
		{
			if(Snippits[i]->Get_File_Name() == nullptr)
			{
				break;
			}
			else
			{
				File_Names[i] = Snippits[i]->Get_File_Name();
			}
		}
	}