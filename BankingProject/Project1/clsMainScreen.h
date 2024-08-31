#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsValidate.h"
#include"clsClientListScreen.h"
#include"clsAddListScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUserScreen.h"
#include"clsLoginScreen.h"
#include"Global.h"
#include"clsRegisterUser.h"
#include"clsShowTransferLogScreen.h"
#include"clsCurrencyScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
	static short _ReadMainMenuOption()
	{
		cout << "choose what do you want to do ? [1-11]" << endl;
		int choice = clsInputValidate::ReadIntNumberBetween(1, 11);
		return choice;
	}
	static void _GoBackToMainMenu()
	{
		system("pause>0");
		system("cls");
		ShowMainMenu();
	}

	static void _ShowAllClientScreen()
	{
		clsClientListScreen::ShowClientLIst();
	}
	static void _ShowAddNewClient()
	{
		clsAddListScreen::ShowAddClient();
	}
	static void _ShowDeleteClient()
	{
		clsDeleteClientScreen::DeleteClient();
	}
	static void _ShowManageUsersScreen()
	{
		clsManageUserScreen::ShowManageUser();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClient();
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}
	static void _ShowTransactionScreen()
	{
		clsTransactionScreen::ShowTransaction();
	}
	static void _ShowRegistersUser()
	{
		clsRegisterUser::ShowRegisterUser();
	}
	static void _ShowCurrencyScreen()
	{
		clsCurrencyScreen::ShowCurrency();
	}
	static void _ShowTransferLog()
	{
		clsShowTransferLogScreen::TransferLogFile();
	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}
	
	
	
	enum _MainMenuOption {
		eListClient = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,
		eShowTransactionMenu = 6, eManageUsers = 7, eRegisterUser = 8 ,eTransferLog = 9 ,eCurrency = 10,eExit = 11
	};
	static void _PerformMainMenuOption(_MainMenuOption choice)
	{
		switch (choice)
		{
				case _MainMenuOption::eListClient:
				{
					system("cls");
					_ShowAllClientScreen();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eAddNewClient:
				{
					system("cls");
					_ShowAddNewClient();
					_GoBackToMainMenu();
					break;
				} 
				case _MainMenuOption::eDeleteClient:
				{
					system("cls");
					_ShowDeleteClient();
					_GoBackToMainMenu();
					break;
				} 
				case _MainMenuOption::eManageUsers:
				{
					system("cls");
					_ShowManageUsersScreen();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eFindClient:
				{
					system("cls");
					_ShowFindClientScreen();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eUpdateClient:
				{
					system("cls");
					_ShowUpdateClientScreen();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eExit:
				{
					system("cls");
					_Logout();
					break;
				}
				case _MainMenuOption::eShowTransactionMenu:
				{
					system("cls");
					_ShowTransactionScreen();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eRegisterUser:
				{
					system("cls");
					_ShowRegistersUser();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eTransferLog:
				{
					system("cls");
					_ShowTransferLog();
					_GoBackToMainMenu();
					break;
				}
				case _MainMenuOption::eCurrency:
				{
					system("cls");
					_ShowCurrencyScreen();
					_GoBackToMainMenu();
					break;
				}
		}
	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << setw(20) << left << "===================" << endl;
		cout << setw(20) << left << "    Main MENU    " << endl;
		cout << setw(20) << left << "===================" << endl;
		cout << setw(20) << left << "[1] Show Client List" << endl;
		cout << setw(20) << left << "[2] Add New Client " << endl;
		cout << setw(20) << left << "[3] Delete Client " << endl;
		cout << setw(20) << left << "[4] Update Client  " << endl;
		cout << setw(20) << left << "[5] Find Client " << endl;
		cout << setw(20) << left << "[6] Transactions " << endl;
		cout << setw(20) << left << "[7] Manage Users " << endl;
		cout << setw(20) << left << "[8] RegisterUser " << endl;
		cout << setw(20) << left << "[9] Show Transfer " << endl;
		cout << setw(20) << left << "[10] Currency Exchange " << endl;
		cout << setw(20) << left << "[11] Logout " << endl;
		
		_PerformMainMenuOption(_MainMenuOption(_ReadMainMenuOption()));
	}
};
