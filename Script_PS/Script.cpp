#include "stdafx.h"
#include "Script.h"

using namespace Main_package;

Script::Script(void)
	{
		Script::Script_Path = "";
		Script::Snippit_Path = "";
		Script::Keyword_Path = "";
		Script::File_Names_Path = "";
	}
	bool Script::Set_Script_Path(System::String^ path)
	{
		Script::Script_Path = path;
		int length = Script::Script_Path->Length;
		wchar_t lastchar = Script::Script_Path[length-1];
		wchar_t lastchar2 = Script::Script_Path[length - 2];
		if(Script::Script_Path == "" || (lastchar != 'l') || (lastchar2  != 'p'))
		{
			return false;
		}
		Update_Secondary_Paths();
		return true;
	}
	bool Script::Update_Path_in_script(void)
	{
		System::String^ str_path = Script::Script_Path;
		Regex^ pat1 = gcnew Regex("open\\s*\\(\\s*FILE2.*");
		Regex^ pat2 = gcnew Regex("open\\s*\\(\\s*FILE_NAMES.*");
		Regex^ pat3 = gcnew Regex("open\\s*\\(\\s*KEYWORDS.*");
		System::String^ loc_snpt_path = "open (FILE2, \'" + Snippit_Path + "\')";
		System::String^ loc_filenames_path = "open (FILE_NAMES, \'" + File_Names_Path + "\')";
		System::String^ loc_keywords_path = "open (KEYWORDS, \'" + Keyword_Path + "\')";
		System::String^ lineString = System::IO::File::ReadAllText(str_path);
		System::String^ lineString_prev = lineString;
		lineString = pat1->Replace(lineString,loc_snpt_path);
		lineString = pat2->Replace(lineString,loc_filenames_path);
		lineString = pat3->Replace(lineString,loc_keywords_path);
		if (lineString_prev->Equals(lineString))
		{
			return false;
		}
		System::IO::File::WriteAllText(str_path, lineString);
		return true;
	}
	System::String^ Script::getScript_path(void)
	{
		return Script::Script_Path;
	}
	void Script::Update_Secondary_Paths(void)
	{
		System::String^ str_path = Script::Script_Path;
		System::String^ filename = System::IO::Path::GetFileNameWithoutExtension(str_path) + "\\.pl";
		Regex^ pattern = gcnew Regex(filename);
		Script::Snippit_Path = pattern->Replace(str_path,"red_errors.pm");
		Script::File_Names_Path = pattern->Replace(str_path,"File_names.pm");
		Script::Keyword_Path = pattern->Replace(str_path,"Keywords.pm");
	}
	array<System::String^>^ Script::Get_Secondary_Paths(void)
	{
		array<System::String^>^ Paths = {Script::Snippit_Path, Script::File_Names_Path, Script::Keyword_Path};
		return Paths;
	}
	bool Script::Check_Script_Config(void)
	{
		System::String^ lineString = System::IO::File::ReadAllText(Script::Script_Path);
		Regex^ pat1 = gcnew Regex(Script::Snippit_Path);
		Regex^ pat2 = gcnew Regex(Script::File_Names_Path);
		Regex^ pat3 = gcnew Regex(Script::Keyword_Path);
		if(pat1->Match(lineString) && pat2->Match(lineString) && pat3->Match(lineString))
		{
			return true;
		}
		return false;
	}