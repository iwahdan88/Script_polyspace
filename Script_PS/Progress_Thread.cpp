#include "stdafx.h"
#include "Progress_thread.h"
using namespace Main_package;
Progress::Progress(unsigned long step, ProgressBar^ prg)
{
	Progress::prg = gcnew ProgressBar();
	Progress::step = step;
	Progress::prg = prg;
	Progress::prg->Step = Progress::step;
	//Run_Progress();
}
void Progress::Run_Progress(void)
{
//	Progress::prg->PerformStep();
}