#include "stdafx.h"
#include "Script.h"

using namespace Main_package;

Script::Script(void)
	{
		Script::Script_Path = "";
		Script::Snippit_Xml_Path = "";
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
		SetXmlFilePath();
		return true;
	}
	System::String^ Script::getScript_path(void)
	{
		return Script::Script_Path;
	}
	System::String^ Script::GetXmlFilePath(void)
	{
		return Script::Snippit_Xml_Path;
	}
	void Script::SetXmlFilePath(void)
	{
		System::String^ str_path = Script::Script_Path;
		Regex^ pattern = gcnew Regex(".[^\\\\]*\\.pl");
		Script::Snippit_Xml_Path = pattern->Replace(str_path, "\\TemplateXML.xml");
	}
	bool Script::Check_Script_Config(void)
	{
		System::String^ lineString = System::IO::File::ReadAllText(Script::Script_Path);
		Regex^ pat1 = gcnew Regex(Script::Snippit_Xml_Path);
		if(pat1->Match(lineString))
		{
			return true;
		}
		return false;
	}