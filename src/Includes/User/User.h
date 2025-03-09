#pragma once
#include <Globals.h>

using namespace std;

struct UserDetails {
	string username;
	string password;
	string role;
	string contact;
	string email;
};

class User
{
private:
	map<string, UserDetails> users;
	UserDetails currentUser;
	const string filename = "users.txt";
	bool loggedIn = false;


public:
	User() {
		loadUsers();
	}

	void loadUsers();
	void save();
	bool registerUser();
	bool getIsLoggedIn() const {
		return this->loggedIn;
	}
	bool login();
	void logout();

	UserDetails getCurrentUser();
	

};

inline User user;