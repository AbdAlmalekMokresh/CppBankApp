#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"Global.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string SubTitle = "Main Screen")
	{
		cout << "__________________________" << endl;
		cout << left << setw(25) << SubTitle << left << setw(25) << endl;
		cout << "__________________________" << endl;
		
		// cout << " Date: " << clsDate::GetDate() << endl;
		cout << "User: " << CurrentUser.GetUserName() << endl;
	}	
public:
	static bool CheckAccessRights(clsUser::enPermissions Perm)
	{
		if (!CurrentUser.CheckPermission(Perm))
		{
			cout << "Access Denied" << endl;
			return false;
		}
		else return true;
	}

};