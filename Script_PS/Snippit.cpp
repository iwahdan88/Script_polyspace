#include "stdafx.h"
#include "Snippit.h"

using namespace Main_package;

Snippit::Snippit(void)
			{
				Snippit::Original = nullptr;
				Snippit::Replacment = nullptr;
				Snippit::File_Name = nullptr;
				Snippit::SW_Version = nullptr;
				Snippit::IsReused = false;
				Snippit::IsReplaced = false;
				Snippit::BugTRAQ = nullptr;
				Snippit::ID = nullptr;
				Snippit::Justification = nullptr;
				Snippit::SnptType = UnknownType;
				Snippit::BugReportNum = 0;
				Snippit::bypass = false;
			}
Snippit::Snippit(System::String^ Original, System::String^ Replacment, System::String^ Type, System::String^ File, System::String^ SnippitID, 
				 System::String^ BugReportNum, System::String^ WorkAroundJustification, System::String^ SW_Version, 
				 System::String^ IsReused, System::String^ IsReplaced, System::String^ BugTRAQ)
			{
				Snippit::Original = Original;
				Snippit::Replacment = Replacment;
				Snippit::File_Name = File;
				Snippit::SW_Version = SW_Version;
				if (IsReused->Equals("1"))
				{
					Snippit::IsReused = true;
				}
				else
				{
					Snippit::IsReused = false;
				}
				if (IsReplaced->Equals("1"))
				{
					Snippit::IsReplaced = true;
				}
				else
				{
					Snippit::IsReplaced = false;
				}
				Snippit::BugTRAQ = BugTRAQ;
				Snippit::ID = SnippitID;
				Snippit::Justification = WorkAroundJustification;
				if (Type->Equals("PolySpace_1"))
				{
					Snippit::SnptType = PolySpace_1;
				}
				else if (Type->Equals("PolySpace_2"))
				{
					Snippit::SnptType = PolySpace_2;
				}
				else if (Type->Equals("Bug_Report"))
				{
					Snippit::SnptType = Bug_Report;
				}
				else
				{
					Snippit::SnptType = UnknownType;
				}
				Snippit::BugReportNum = int::Parse(BugReportNum);
				Snippit::bypass = false;
			}
			void Snippit::Set_Original(System::String^ s)
			{
				if(s->Equals("NULL"))
				{
					Original = nullptr;
				}
				else
				{
					Original = s;
				}
			}
			void Snippit::Set_Replacment(System::String^ s)
			{
				if(s->Equals("NULL"))
				{
					Replacment = nullptr;
				}
				else
				{
					Replacment = s;
				}
			}
			void Snippit::Set_File_Name(System::String^ s)
			{
				if(s->Equals("NULL"))
				{
					File_Name = nullptr;
				}
				else
				{
					File_Name = s;
				}
			}
			void Snippit::Set_Snippet_Justification(System::String^ Just)
			{
				if (Just->Equals("NULL"))
				{
					File_Name = nullptr;
				}
				else
				{
					File_Name = Just;
				}
			}
			void Snippit::Set_SW_Version(System::String^ Ver)
			{
				if (Ver->Equals("NULL"))
				{
					Snippit::SW_Version = nullptr;
				}
				else
				{
					Snippit::SW_Version = Ver;
				}
			}
			void Snippit::SetReuse(bool reuse)
			{
				IsReused = reuse;
			}
			void Snippit::SetReplacement(bool Rep)
			{
				IsReplaced = Rep;
			}
			void Snippit::Set_BugTRAQ(System::String^ BugTrq)
			{
				if (BugTrq->Equals("NULL"))
				{
					Snippit::BugTRAQ = nullptr;
				}
				else
				{
					Snippit::BugTRAQ = BugTrq;
				}
			}
			void Snippit::Set_ID(System::String^ id)
			{
				if (id->Equals("NULL"))
				{
					Snippit::ID = nullptr;
				}
				else
				{
					Snippit::ID = id;
				}
			}
			void Snippit::SetSnippetType(SnippitType Type)
			{
				SnptType = Type;
			}
			void Snippit::SetBugReportNum(int Num)
			{
				BugReportNum = Num;
			}
			System::String^ Snippit::Get_Original(void)
			{
				return Snippit::Original;
			}
			System::String^ Snippit::Get_Replacment(void)
			{
				return Snippit::Replacment;
			}
			System::String^ Snippit::Get_File_Name(void)
			{
				return Snippit::File_Name;
			}
			System::String^ Snippit::Get_Snippet_Justification(void)
			{
				return Snippit::Justification;
			}
			System::String^ Snippit::GetSW_Version(void)
			{
				return SW_Version;
			}
			bool Snippit::IsSnippetReused(void)
			{
				return IsReused;
			}
			bool Snippit::IsSnippetReplaced(void)
			{
				return IsReplaced;
			}
			System::String^ Snippit::GetBugTRAQ(void)
			{
				return BugTRAQ;
			}
			System::String^ Snippit::GetID(void)
			{
				return ID;
			}
			SnippitType Snippit::GetSnippetType(void)
			{
				return SnptType;
			}
			int Snippit::GetBugReportNum(void)
			{
				return BugReportNum;
			}
			void Snippit::ByPass(bool bypass)
			{
				Snippit::bypass = bypass;
			}
			bool Snippit::Is_ByPassed (void)
			{
				return Snippit::bypass;
			}