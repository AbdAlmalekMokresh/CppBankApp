#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsValidate.h"
#include"clsUser.h" // back-end
#include"Global.h"
#include"clsMainScreen.h"
#include<fstream>
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
	static void _SaveInLogFile(string UserName)
	{
		clsUser::_SaveInLogFile(UserName);
	}
	static void _ReadLoginInfo()
	{
		string UserName;
		string Password;
		

		bool loginFaild = false;
		int cnt = 0;
		do {
			cout << " UserName: ";
			UserName = clsInputValidate::ReadString();
			cout << " Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser.SetUserName("admin");
			CurrentUser.SetPassword("0000");


			CurrentUser  = clsUser::Find(UserName, Password);
			loginFaild = CurrentUser.IsEmpty();

			if (loginFaild) { cout << "Faild Login " << endl; times--; }
			if (times == 0)return; 

		} while (loginFaild);

		_SaveInLogFile(CurrentUser.GetUserName());
		clsMainScreen::ShowMainMenu();
		
		
	}
	
public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");

		_ReadLoginInfo();
		
	}
};