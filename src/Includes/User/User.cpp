#include <User/User.h>

void User::loadUsers()
{
	ifstream infile(filename);
	if (!infile) {
		return;
	}
	UserDetails details;
	while (infile >> details.username >> details.password >> details.role >> details.contact >> details.email) {
		users[details.username] = details;
	}
	infile.close();
}

void User::save()
{
	ofstream outfile(filename);
	if (!outfile) {
		console.WriteLine(L"Error saving users");
		cin.get();
		return;
	}
	for (auto& [username, details] : users) {
		outfile << details.username << " " << details.password
			<< " " << details.role << " " << details.contact << " "
			<< details.email << endl;
	}
	outfile.close();

}

bool User::registerUser()
{
	UserDetails details;
	console.WriteLine(L"Enter user details");
	console.Write(L"Enter username: ");
	cin >> details.username;
	console.Write(L"Enter password: ");
	cin >> details.password;
	console.Write(L"Enter role (admin, user, librarian): ");
	cin >> details.role;
	if (details.role != "admin" && details.role != "user" && details.role != "librarian") {
		console.WriteLine(L"Invalid role");
		cin.get();
		return false;
	}
	console.Write(L"Enter contact: ");
	cin >> details.contact;
	console.Write(L"Enter email: ");
	cin >> details.email;
	console.WriteLine(L"");

	if (users.find(details.username) != users.end()) {
		console.WriteLine(L"User already exists");
		cin.get();
		return false;
	}
	users[details.username] = details;
	save();
	return true;
}

bool User::login()
{
	string username, password;
	console.Write(L"Enter username: ");
	cin >> username;
	console.Write(L"Enter password: ");
	cin >> password;
	if (users.find(username) == users.end()) {
		return false;
	}
	if (users[username].password != password) {
		return false;
	}
	currentUser = users[username];
	this->loggedIn = true;
	return true;
}

void User::logout()
{
	this->loggedIn = false;
}

UserDetails User::getCurrentUser()
{
	if (this->loggedIn) {
		return currentUser;
	}
	else nullptr;
}