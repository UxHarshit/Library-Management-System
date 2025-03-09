#include <Globals.h>


static void printHeader() {
	console.WriteLine(L" _     __  __ ____  ");
	console.WriteLine(L"| |   |  \\/  / ___| ");
	console.WriteLine(L"| |   | |\\/| \\___ \\ ");
	console.WriteLine(L"| |___| |  | |___) |");
	console.WriteLine(L"|_____|_|  |_|____/ ");
	console.WriteLine(L"\n\n");
}

int APIENTRY WinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prev_instance, _In_ LPSTR cmd_line, _In_ int cmd_show) 
{
	console.CreateConsole(ConsoleSettings::title, ConsoleSettings::width, ConsoleSettings::height);
	

	int choice;
	
	while (!ConsoleSettings::exit) {
		console.Clear();
		printHeader();
		console.WriteLine(L"Welcome to Library Management System\n");

		if (user.getIsLoggedIn()) {
			console.WriteLine(("Current User: " + user.getCurrentUser().username).c_str());
		}

		console.WriteLine(L"Please select an option");
		console.Write(L"1. Register \n2. Login \n3. Exit\n");
		if (user.getIsLoggedIn()) console.WriteLine("4. Logout");

		cin >> choice;

		switch (choice) {
		case 1:
			if (user.registerUser()) {
				console.WriteLine(L"User registered successfully");
			}
			else console.WriteLine(L"Failed to register the user");
			break;
		case 2:
			if (user.login()) {
				console.WriteLine(("Welcome " + user.getCurrentUser().username).c_str());
			} else console.WriteLine(L"User not found or Invalid Password!");
			break;
		case 3:
			ConsoleSettings::exit = true;
			break;
		case 4:
			user.logout();
			break;
		default:
			console.WriteLine("Invalid Option");
			break;
		}

		Sleep(1000);
	}

	console.WriteLine(L"Press any to exit the program");
	cin.get();
}