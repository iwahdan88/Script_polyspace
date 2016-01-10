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
			System::Collections::Generic::List < Main_package::Snippit^ >^ Snippits;
			int Snippit_Count;
			void Refresh_File(void);
			void Replacer::FindMaxId();
			System::Data::DataSet^ SnippetDataSet;
			System::Xml::XmlDocument^ XmlFile;
			int MaximumID;
			System::String^ PathofXml;

		public:
			Replacer(System::String^ XMLPath);
			bool Load_XmlFile(System::String^ File_Path, double CurrVer);
			bool Load_XmlFile(System::String^ File_Path);
			void Create_Snippit(System::String^ snpt_original, System::String^ snpt_replacment, System::String^ Type, System::String^ FileName,
								System::String^ Snpt_BugRprt, System::String^ Justification, System::String^ Version, 
								System::String^ IsReuese, System::String^ IsReplace, System::String^ TRAQ);
			void Delete_Snippit(unsigned short Snpt_number);
			array<System::String^>^ Get_snippit(unsigned short Snpt_number);
			array<System::String^>^ Get_snippitByID(unsigned short Snpt_number);
			void Edit_Snippit(array<System::String^>^ snpt);
			int Get_Snpt_Count(void);
			int GetMaxID(void);
			void IncrementID(void);
			bool Contains(System::String^ pattern, array<System::String^>^ snpt);
			void Save_file(void);
			void Reload(void);
		};
}
