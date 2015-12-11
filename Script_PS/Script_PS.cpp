// Script_PS.cpp : main project file.

#include "stdafx.h"
#include "Script_GUI.h"
#include <iostream>
using namespace Script_PS;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Script_GUI());
	return 0;
}
