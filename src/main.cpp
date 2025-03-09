#include <Globals.h>




int APIENTRY WinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prev_instance, _In_ LPSTR cmd_line, _In_ int cmd_show) 
{
	console.CreateConsole(ConsoleSettings::title, ConsoleSettings::width, ConsoleSettings::height);

	
	while (!ConsoleSettings::exit) {
		Auth::Run();
		Sleep(1000);
	}

	console.WriteLine(L"Press any to exit the program");
	cin.get();
}