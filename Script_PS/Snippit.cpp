#include "stdafx.h"
#include "Snippit.h"

using namespace Main_package;

Snippit::Snippit(void)
			{
				Snippit::Original = nullptr;
				Snippit::Replacment = nullptr;
				Snippit::File_Name = nullptr;
				Snippit::Type = UnknownType;
				Snippit::BugReportNum = 0;
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
			void Snippit::ByPass(bool bypass)
			{
				Snippit::bypass = bypass;
			}
			bool Snippit::Is_ByPassed (void)
			{
				return Snippit::bypass;
			}