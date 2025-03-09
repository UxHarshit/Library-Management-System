#include "Admin.h"

void Admin::AdminMenu()
{
	console.SetColor(YELLOW);

	console.WriteLine(L"Library Management System - Admin Menu");
	console.WriteLine(L"Please select an option");
	console.Write(L"1. Add Book \n2. Remove Book \n3. List Books \n4. Add User \n5. Remove User \n6. List Users \n7. Manage Publishers \n8. Logout \n9. Exit\n");

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 8:
		user.logout();
		break;
	case 9:
		ConsoleSettings::exit = true;
		break;
	default:
		console.WriteLine(L"Invalid Option");
		break;
	}

}
