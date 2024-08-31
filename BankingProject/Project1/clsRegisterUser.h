#pragma once
#include<iostream>
#include"clsUser.h" // back end 
#include"clsScreen.h"
using namespace std;

class clsRegisterUser : protected clsScreen
{
private:
	static void _ShowUsersInLogFiles()
	{
		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::eRegisterUser))
		{
			return;
		}
		vector<string> vUserInLogFiles = clsUser::GetLogFile();
		if (vUserInLogFiles.size() == 0)cout << "NO REGISTER USRE EXIST " << endl;
		else {
			cout << "USER-NAME" << endl;
			for (auto C : vUserInLogFiles)
			{
				cout << C << endl;
			}
		}
	}
public:

	static void ShowRegisterUser()
	{
		_DrawScreenHeader("Registers User");
		_ShowUsersInLogFiles();
	}
};

