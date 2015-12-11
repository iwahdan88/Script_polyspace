#pragma once
typedef enum
{
	PolySpace_1,
	PolySpace_2,
	Bug_Report,
	UnknownType
}SnippitType;

namespace Main_package
{
	public ref class Snippit
	{
	private: System::String^ Original;
			 System::String^ Replacment;
			 System::String^ File_Name;
			 SnippitType Type;
			 int BugReportNum;
			 bool bypass;
	public: void Set_Original(System::String^ s);
			void Set_Replacment(System::String^ s);
			void Set_File_Name(System::String^ s);
			System::String^ Get_Original(void);
			System::String^ Get_Replacment(void);
			System::String^ Get_File_Name(void);
			Snippit(void);
			void ByPass(bool bypass);
			bool Is_ByPassed (void);
	};
}