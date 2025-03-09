#pragma once
#include <iostream>

#include <Windows.h>
#include <string>
#include <map>
#include <fstream>

#include <Console/Console.h>
#include <User/User.h>
#include <Menus/Auth.h>
#include <Menus/Admin.h>
#include <Library/Library.h>


using namespace std;


namespace ConsoleSettings {
	inline wchar_t title[26] = L"Library Management System";
	inline int width = 800;
	inline int height = 600;
	inline bool exit = false;
}