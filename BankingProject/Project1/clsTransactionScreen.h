#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
using namespace std;
class clsTransactionScreen : protected clsScreen
{
private:
	enum enTransactionMenu {
		eDeposit = 1 , eWithdraw = 2, eTotalBalance = 3 , eTransfer = 4 , eMainMenu = 5
	};
	static int _ReadTransactionMenu()
	{
		cout << "Choose what do you want to do ? " << endl;
		int choice = clsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;
	}

	static void _TransferMenu()
	{
		clsTransferScreen::Transfer();
	}
	static void DepositTransaction()
	{
		clsDepositScreen::DepositScreen();

	}
	static void WithdrawTransaction()
	{
		clsWithdrawScreen::WithdrawScreen();
	}
	static void TotalBalanceTransaction()
	{
		clsTotalBalanceScreen::ShowTotalBalance();
	}
	
	static void GoBackToTransactionScreen()
	{
		system("pause>0");
		system("cls");
		ShowTransaction();
	}
	static void _PerformTransactionMenu(enTransactionMenu eChoice)
	{
		switch(eChoice)
		{
				case enTransactionMenu::eDeposit:
				{
					system("cls");
					DepositTransaction();
					GoBackToTransactionScreen();
					break;
				}
				case enTransactionMenu::eWithdraw:
				{
					system("cls");
					WithdrawTransaction();
					GoBackToTransactionScreen();
					break;
				}
				case enTransactionMenu::eTotalBalance:
				{
					system("cls");
					TotalBalanceTransaction();
					GoBackToTransactionScreen();
					break;
				}
				case enTransactionMenu::eTransfer:
				{
					system("cls");
					_TransferMenu();
					GoBackToTransactionScreen();
					break;
				}
				case enTransactionMenu::eMainMenu:
				{
					/*
					system("cls");
					MainMenuTransaction();
					GoBackToTransactionScreen();
					*/
					break;
				}
		}
	}
public:
	static void ShowTransaction()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eTransaction))
			return;
		system("cls");
		_DrawScreenHeader("Transaction Header");

		cout << "======================" << endl;
		cout << "	[1] Deposit " << endl;
		cout << "	[2] Withdraw " << endl;
		cout << "	[3] Total Balance " << endl;
		cout << "	[4] Transfer " << endl;
		cout << "	[5] Main Menu" << endl;
		cout << "======================" << endl << endl;
		_PerformTransactionMenu(enTransactionMenu(_ReadTransactionMenu()));
	}
};

