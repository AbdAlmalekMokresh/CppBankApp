#pragma once
#include<iostream>
#include"clsScreen.h"
#include<string>
#include"clsUser.h"
using namespace std;

class clsListUserScreen : clsScreen
{
	static void _PrintUserScreen(vector<clsUser> Users)
	{
		for (auto C : Users)
		{
			cout << "User-Name: " << C.GetUserName() << "   PERMISSION:   " << C.GetPermission() << endl;
		}
	}
public:

	static void ShowUserList()
	{
		_DrawScreenHeader("USER LIST");

		vector<clsUser> vUsers = clsUser::GetUsersList();
		_PrintUserScreen(vUsers);

	}
};

