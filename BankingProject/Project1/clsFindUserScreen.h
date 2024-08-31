#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsValidate.h"
#include"clsUser.h"
using namespace std;
class clsFindUserScreen : protected clsScreen
{
private:
	static void _PrintUserInfo(clsUser User)
	{
		cout << " ==================== " << endl;
		cout << "UserName : " << User.UserName << endl;
		cout << "Permission : " << User.Permission << endl;
		cout << "FULLNAME : " << User.FullName() << endl;
		cout << "Password : " << User.Password << endl;
		cout << " ==================== " << endl;
	} 

public:

	static void FindUser()
	{
		cout << "ENTER USERNAME " << endl;
		string UserName = clsInputValidate::ReadString();

		if (clsUser::IsUserExist(UserName))
		{
			clsUser User = clsUser::Find(UserName);
			_PrintUserInfo(User);
		}
		else {
			cout << "Not exist" << endl;
		}
	}
};

