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
			 System::String^ Justification;
			 System::String^ SW_Version;
			 bool IsReused;
			 bool IsReplaced;
			 bool IncludeSnpt;
			 System::String^ BugTRAQ;
			 System::String^ ID;
			 SnippitType SnptType;
			 int BugReportNum;
			 bool bypass;
	public: void Set_Original(System::String^ s);
			void Set_Replacment(System::String^ s);
			void Set_File_Name(System::String^ s);
			void Set_Snippet_Justification(System::String^ Just);
			void Snippit::Set_SW_Version(System::String^ Ver);
			void Snippit::SetReuse(bool reuse);
			void Snippit::SetReplacement(bool Rep);
			void Snippit::Set_BugTRAQ(System::String^ BugTrq);
			void Snippit::Set_ID(System::String^ id);
			void Snippit::SetSnippetType(SnippitType Type);
			void Snippit::SetBugReportNum(int Num);
			void Snippit::SetInclude(bool Inc);
			System::String^ GetSW_Version(void);
			bool IsSnippetReused(void);
			bool IsSnippetReplaced(void);
			System::String^ GetBugTRAQ(void);
			System::String^ GetID(void);
			SnippitType GetSnippetType(void);
			int GetBugReportNum(void);
			System::String^ Get_Original(void);
			System::String^ Get_Replacment(void);
			System::String^ Get_File_Name(void);
			System::String^ Get_Snippet_Justification(void);
			bool Snippit::GetInclude(void);

			Snippit(void);
			Snippit::Snippit(System::String^ Original, System::String^ Replacment, System::String^ Type, System::String^ File, System::String^ SnippitID,
				System::String^ BugReportNum, System::String^ WorkAroundJustification, System::String^ SW_Version,
				System::String^ IsReused, System::String^ IsReplaced, System::String^ BugTRAQ, bool Inc);
			void ByPass(bool bypass);
			bool Is_ByPassed (void);
	};
}