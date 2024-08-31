#pragma once
#include<iostream>
#include"clsValidate.h"
#include<string>
#include"clsScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsListCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCalculatorScreen.h"
using namespace std;
class clsCurrencyScreen : protected clsScreen
{
private:
	static short _ReadInput()
	{
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;
	}
	static void _GoBackToCurrencyMenu() {
		system("pause>0");
		ShowCurrency();
	}

	static void _ShowListCurrency() {
		clsListCurrencyScreen::ListScreen();
	}
	static void _ShowCalculatorCurrency() {
		clsCalculatorScreen::CalculatorCurrency();
	}
	static void _ShowFindCurrency() {
		clsFindCurrencyScreen::FindCurrency();
	}
	static void _ShowUpdateCurrency(){
		clsUpdateCurrencyScreen::UpdateCurrency();
	}


	enum eCurrencyScreen{elist = 1 , efind = 2 , eUpdate = 3 , eCalculator = 4 , eMainMenu= 5};
	static void _PerformCurrencyMenu(eCurrencyScreen eChoice)
	{
		switch (eChoice)
		{
			case eCurrencyScreen::elist:
			{
				system("cls");
				_ShowListCurrency();
				_GoBackToCurrencyMenu();
				break;
			}
			case eCurrencyScreen::eCalculator:
			{
				system("cls");
				_ShowCalculatorCurrency();
				_GoBackToCurrencyMenu();
				break;
			}
			case eCurrencyScreen::efind:
			{
				system("cls");
				_ShowFindCurrency();
				_GoBackToCurrencyMenu();
				break;
			}
			case eCurrencyScreen::eMainMenu:
			{
				break;
			}
			case eCurrencyScreen::eUpdate:
			{
				system("cls");
				_ShowUpdateCurrency();
				_GoBackToCurrencyMenu();
				break;
			}
		}
	}
public:

	static void ShowCurrency()
	{
		system("cls");
		_DrawScreenHeader("#####  CURRENCY SCREEN  #####");
		cout << "[1] List Currency " << endl;
		cout << "[2] Find Currency " << endl;
		cout << "[3] Update Rate " << endl;
		cout << "[4] Currency Calculator" << endl;
		cout << "[5] Main Menu " << endl;

		_PerformCurrencyMenu(eCurrencyScreen(_ReadInput()));

	}
};