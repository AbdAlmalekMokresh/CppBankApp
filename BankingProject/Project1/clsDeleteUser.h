#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsValidate.h"
#include"clsScreen.h"
class clsDeleteUser : protected clsScreen
{ 
private:
	static void _PrintUser(clsUser User)
	{
		cout << " ==================== " << endl;
		cout << "UserName : " << User.UserName << endl;
		cout << "Permission : " << User.Permission << endl;
		cout << "FULLNAME : " << User.FullName() << endl;
		cout << "Password : " << User.Password << endl;
		cout << " ==================== " << endl;
	}   
	
public:

	static void ShowDeleteUser()
	{
		_DrawScreenHeader("Delete User");

		cout << "Enter UserName" << endl;
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "UserName not found, try another one .. " << endl;
			UserName = clsInputValidate::ReadString();
		}
		clsUser DelUser = clsUser::Find(UserName);
		_PrintUser(DelUser);
		cout << endl;
		cout << "are you sure you want to delete this user ? " << endl;
		char ans = 'n';
		cin >> ans;
		if (ans == 'Y' || ans == 'y')
		{
			if (DelUser.Delete())
			{
				cout << "User Deleted Succesfully" << endl;
			}
			else cout << "Faild, try another one " << endl;
		}
	}
};

