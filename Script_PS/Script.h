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
		System::String^ Snippit_Path;
		System::String^ Keyword_Path;
		System::String^ File_Names_Path;
		void Update_Secondary_Paths(void);
	public:
		bool Set_Script_Path(System::String^ path);
		bool Update_Path_in_script(void);
		bool Check_Script_Config(void);
		System::String^ getScript_path(void);
		array<System::String^>^ Get_Secondary_Paths(void);
	};
}