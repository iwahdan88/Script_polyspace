#include "stdafx.h"
#include <regex>
#include <string>

using namespace System::Text::RegularExpressions;
using namespace System::IO;

namespace Main_package
{
	public ref class Script
	{
	public:Script(void);
	private:
		System::String^ Script_Path;
		System::String^ Snippit_Xml_Path;
		void SetXmlFilePath(void);
	public:
		bool Set_Script_Path(System::String^ path);
		bool Check_Script_Config(void);
		System::String^ getScript_path(void);
		System::String^ GetXmlFilePath(void);
	};
}