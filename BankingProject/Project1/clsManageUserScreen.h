#pragma once
#include<iostream>
#include"clsValidate.h"
#include"clsScreen.h"
#include"clsListUserScreen.h"
#include"clsDeleteUser.h"
#include"clsAddNewUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;
class clsManageUserScreen : protected clsScreen
{
	enum enManageUser {
		eListUser = 1 , eAddNewUser = 2 , eDeleteUser = 3 , eUpdateUser = 4 , eFindUser = 5 , eMainMenu = 6
	};
	static int ReadManageUser()
	{
		cout << "Enter your choice [1-6]" << endl;
		int choice = clsInputValidate::ReadIntNumberBetween(1,6);
		return choice;
	}
	static void _ShowAddUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUser();
	}
	static void _ShowDeleteUser()
	{
		clsDeleteUser::ShowDeleteUser();
	}
	static void _ShowFindUser()
	{
		clsFindUserScreen::FindUser();
	}
	static void _ShowListUser()
	{
		clsListUserScreen::ShowUserList();
	}
	static void _ShowUpdateUser()
	{
	clsUpdateUserScreen::ShowUpdateUser();
	}


	static void GoBackToManageUserScreen()
	{
		system("pause>0");
		system("cls");
		ShowManageUser();
	}
	static void PerformManageUser(enManageUser echoice)
	{
		switch (echoice)
		{
				case enManageUser::eAddNewUser:
				{
					system("cls");
					_ShowAddUserScreen();
					GoBackToManageUserScreen();
					break;
				}
				case enManageUser::eDeleteUser:
				{
					system("cls");
					_ShowDeleteUser();
					GoBackToManageUserScreen();
					break;
				}
				case enManageUser::eFindUser:
				{
					system("cls");
					_ShowFindUser();
					GoBackToManageUserScreen();
					break;
				}
				case enManageUser::eListUser:
				{
					system("cls");
					_ShowListUser();
					GoBackToManageUserScreen();
					break;
				}
				case enManageUser::eMainMenu:
				{
					system("cls");
					break;
				}
				case enManageUser::eUpdateUser:
				{
					 system("cls");
					_ShowUpdateUser();
					GoBackToManageUserScreen();
					break;
				}
		}
	}
public:

	static void ShowManageUser()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eManageUsers))
			return;

		_DrawScreenHeader("Manage User Screen");

		cout << "[1] List Users " << endl;
		cout << "[2] Add New User " << endl;
		cout << "[3] Delete User " << endl;
		cout << "[4] Update User " << endl;
		cout << "[5] Find User " << endl;
		cout << "[6] Main Menu " << endl;

		PerformManageUser(enManageUser(ReadManageUser()));
	}
	
};

