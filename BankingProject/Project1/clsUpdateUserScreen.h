#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsValidate.h"
using namespace std;
class clsUpdateUserScreen : protected clsScreen
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
	    
		static void _ReadUserInfo(clsUser &User)
	    {
			cout << "\nEnter FirstName: ";
			User.FirstName = clsInputValidate::ReadString();
			cout << "\nEnter LastName :";
			User.LastName = clsInputValidate::ReadString();
			
			User.SetPermission(_ReadPermissionsToSet());
		}
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
		
public:

	static void ShowUpdateUser()
	{	
		_DrawScreenHeader("Update Screen");
		 cout << "Enter UserName that you want to update it " << endl;
		 string UserName = clsInputValidate::ReadString();
		 while (!clsUser::IsUserExist(UserName))
		 {
			 cout << "UserName not exist, try another one " << endl;
			 UserName = clsInputValidate::ReadString();
		 }
		 clsUser User = clsUser::Find(UserName);
		 
		 _ReadUserInfo(User);
		 cout << "NEW UPDATE IS : " << endl;
		 _PrintUser(User);
		 cout << " =================== " << endl;
		 cout << "Are you sure you want to save this update ? " << endl;
		 char ans = 'n';
		 cin >> ans;
		 if (ans == 'Y' || ans == 'y')
		 {
			 clsUser::enSaveResult SvRes = User.Save();
				switch (SvRes)
				{
						case clsUser::enSaveResult::svFaildEmptyMode:
						{
							cout << "Faild, because you don't add all information" << endl;
							break;
						}
						case clsUser::enSaveResult::svFaildUserExists:
						{
							cout << "fiald, because this information exist" << endl;
							break;
						}
						case clsUser::enSaveResult::svSucceeded:
						{
							cout << "Updated Successfully" << endl;
							break;
						}
				}
		 }
		 else cout << " Update was cancelled " << endl;
	}
};