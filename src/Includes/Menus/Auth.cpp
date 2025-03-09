#include <Menus/Auth.h>

void Auth::AuthMenu()
{
	console.SetColor(YELLOW);
	console.WriteLine("Auth Menu\n");
	int choice;
	console.WriteLine(L"Please select an option");
	console.Write(L"1. Register \n2. Login \n3. Exit\n");
	cin >> choice;

	switch (choice) {
	case 1:
		if (user.registerUser()) {
			console.SetColor(GREEN);
			console.WriteLine(L"User registered successfully");
		}
		else 
		{ 
			console.SetColor(RED);
			console.WriteLine(L"Failed to register the user"); 
		}
		break;
	case 2:
		if (user.login()) {
			console.SetColor(GREEN);
			console.WriteLine(("Welcome " + user.getCurrentUser().username).c_str());
		}
		else 
		{ 
			console.SetColor(RED);
			console.WriteLine(L"User not found or Invalid Password!"); 
		}
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
}

void Auth::Run()
{
	console.Clear();
	console.SetColor(WHITE);
	console.printHeader();
	console.SetColor(GREEN);
	console.WriteLine(L"Welcome to Library Management System\n");

	if (user.getIsLoggedIn()) {
		console.SetColor(RED);
		console.WriteLine(("Current User: " + user.getCurrentUser().username).c_str());
	}

	if(!user.getIsLoggedIn())
		Auth::AuthMenu();
	else {
		if (user.getCurrentUser().role == "admin")
			admin.AdminMenu();
		/*else if(user.getCurrentUser().role == "librarian")
			Librarian::LibrarianMenu();
		else if(user.getCurrentUser().role == "user")
			User::UserMenu()*/
	}
}
