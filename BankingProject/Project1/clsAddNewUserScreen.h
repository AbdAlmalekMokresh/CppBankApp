#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsValidate.h"
using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
private:
	static int _ReadPermissionsToSet()
	{
		cout << "do you want to give all Access ? " << endl;
		char ans = 'n'; cin >> ans;
		if (ans == 'Y' || ans == 'y')
		{
			return -1;
		}
		else {
			int permission = 0;
			cout << "Do you want to give access for ListClient ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eListClients;

			cout << "Do you want to give access for Add new client ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eAddNewClient;

			cout << "Do you want to give access for Delete Client ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eDeleteClient;

			cout << "Do you want to give access for Update ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eUpdateClients;

			cout << "Do you want to give access for Manage Users ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eManageUsers;

			cout << "Do you want to give access for Transaction ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eTransaction;

			cout << "Do you want to give access for Find Client  ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eFindClient;

			cout << "Registration ? " << endl;
			cin >> ans;
			if (ans == 'Y' || ans == 'y')
				permission += clsUser::enPermissions::eRegisterUser;

			return permission;
		}
	}
	static clsUser _ReadNewUserInfo()
	{
		clsUser NewUser = clsUser::AddNewUser();
		int Permission;
		cout << "\nEnter FirstName : "; NewUser.FirstName = clsInputValidate::ReadString();
		cout << "\nENter LastName : "; NewUser.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Email : "; NewUser.Email = clsInputValidate::ReadString();
		cout << "\n Enter Phone number : "; NewUser.Phone = clsInputValidate::ReadString();
		cout << "\n Enter UserName : "; NewUser.UserName = clsInputValidate::ReadString();
		cout << "\n Enter Password : "; NewUser.Password = clsInputValidate::ReadString();
		NewUser.SetPermission(_ReadPermissionsToSet());
		return NewUser;
	}
	
public:

	static void ShowAddNewUser()
	{
		_DrawScreenHeader("### Add New User ###");	
		clsUser User = _ReadNewUserInfo();
		clsUser::enSaveResult returnType = User.Save();
		switch (returnType)
		{
				case clsUser::enSaveResult::svFaildEmptyMode:
				{
					cout << " Faild, this User doesn't have all information :( " << endl;
					break;
				}
				case clsUser::enSaveResult::svFaildUserExists:
				{
					cout << "Faild, this user is already exist .. " << endl;
					break;
				}
				case clsUser::enSaveResult::svSucceeded:
				{
					cout << "User Added Successfully ... " << endl;
					break;
				}
		}
	}


};