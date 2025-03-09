#include <Console/Console.h>


void Console::printHeader()
{
	console.SetColor(YELLOW);
	console.WriteLine(L" _     __  __ ____  ");
	console.WriteLine(L"| |   |  \\/  / ___| ");
	console.WriteLine(L"| |   | |\\/| \\___ \\ ");
	console.WriteLine(L"| |___| |  | |___) |");
	console.WriteLine(L"|_____|_|  |_|____/ ");
	console.WriteLine(L"\n\n");
}

void Console::CreateConsole(const wchar_t* title, int width, int height)
{
	if (AllocConsole())
	{
		SetConsoleTitle(title);
		FILE* file;
		freopen_s(&file, "CONOUT$", "w", stdout);
		freopen_s(&file, "CONIN$", "r", stdin);

		HWND consoleWindow = GetConsoleWindow();
		if (consoleWindow)
		{
			RECT rect;
			GetWindowRect(consoleWindow, &rect);
			MoveWindow(consoleWindow, rect.left, rect.top, width, height, TRUE);
		}
	}
	else
	{
		MessageBox(NULL, L"Failed to create console", L"Error", MB_OK | MB_ICONERROR);
	}
}

void Console::SetColor(WORD color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

void Console::SetCursorPosition(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::Clear()
{
	COORD topLeft = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO screen;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &screen);
	DWORD written;
	FillConsoleOutputCharacter(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}

void Console::Write(const wchar_t* text)
{
	wcout << text;
}
void Console::Write(const char* text)
{
	cout << text;
}

void Console::WriteLine(const wchar_t* text)
{
	wcout << text << endl;
}

void Console::WriteLine(const char* text) {
	cout << text << endl;
}

void Console::Read(wchar_t* buffer, int length)
{
	wcin.read(buffer, length);
}

void Console::ReadLine(wchar_t* buffer, int length)
{
	wcin.getline(buffer, length);
}
