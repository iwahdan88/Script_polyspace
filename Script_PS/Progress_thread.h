#pragma once
using namespace System::Threading;
using namespace System::Windows::Forms;
namespace Main_package
{
	public ref class Progress
	{
	private:
		unsigned long step;
		ProgressBar^ prg;
	public:
		Progress(unsigned long step, ProgressBar^ prg);
		static void Run_Progress(void);
	};
}