#pragma once
#include "Snippit.h"
#define MAX_NB_KWD 1000

typedef enum File_Error_KW
{
	Line_Error_KW_delim,
	Line_Error_KW_End,
	Unresolved_KW_lines,
	Valid_KW
}File_Error_KW;
namespace Main_package
{
	public ref class Keyword_Replacer
		{
		private:
			array<Main_package::Snippit^>^ Keywords;
			int Snippit_Count;
			System::String^ File_Path;
			void Refresh_File(void);
			void Sort_Data(void);
			array<System::String^>^ File_Array;
			File_Error_KW Er;
			signed long Error_Line;
		public:
			Keyword_Replacer(void);
			bool Load_File(System::String^ File_Path);
			void Create_Snippit(System::String^ snpt_original, System::String^ snpt_replacment, System::String^ FileName);
			void Delete_Snippit(unsigned short Snpt_number);
			array<System::String^>^ Get_snippit(unsigned short Snpt_number);
			void Edit_Snippit(array<System::String^>^ snpt, unsigned short Snpt_number);
			int Get_Snpt_Count(void);
			bool Contains(System::String^ pattern, array<System::String^>^ snpt);
			void Save_file(void);
			void Delete_file(void);
			bool Validate_File(void);
			void Reload(void);
			File_Error_KW Get_Err(void);
			unsigned long Get_Err_Line(void);
			unsigned long Get_File_Length(void);
		};
}
