#include "Snippit.h"
#define MAX_NB_SNPT 1000
#define Max_NB_Files 1000

using namespace System::Xml;

typedef enum File_Error
{
	Line_Error_delim,
	Line_Error_End,
	Unresolved_lines,
	Valid
}File_Error;
namespace Main_package
{
	public ref class Replacer
		{
		private:
			array<Main_package::Snippit^>^ Snippits;
			array<System::String^>^ File_Names;
			int Snippit_Count;
			System::String^ File_Path;
			void Refresh_File(void);
			void Sort_Data(void);
			array<System::String^>^ File_Array;
			File_Error Er;
			signed long Error_Line;
			void Load_File_Names(void);
			System::String^ File_Names_Path;
		public:
			Replacer(System::String^ FileNamesPath);
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
			File_Error Get_Err(void);
			unsigned long Get_Err_Line(void);
			unsigned long Get_File_Length(void);
			void Write_File_Names(void);
		};
}
