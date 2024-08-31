#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsValidate.h"
using namespace std;
class clsFindCurrencyScreen : protected clsScreen 
{
private:
	static short _ReadInput()
	{
		short choice = clsInputValidate::ReadIntNumberBetween(1, 2);
		return choice;
	}
	enum _FindCurrency { Country = 1 , code = 2 };
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}
	static void _FindByCode()
	{
		cout << "Enter the Code ? " << endl;
		string code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(code);
		if (Currency.IsEmpty()) cout << "not exist " << endl;
		else {
			_PrintCurrency(Currency);
		}
	}
	static void _FindByCountry()
	{
		cout << "Enter the name of the country ? " << endl;
		string Country = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(Country);
		if (Currency.IsEmpty()) cout << "not exist " << endl;
		else {
			_PrintCurrency(Currency);
		}
	}

	static void _PerformCurrencyOption(_FindCurrency eChoice)
	{
		switch (eChoice)
		{
			case _FindCurrency::code:
			{
				_FindByCode();
				break;
			}
			case _FindCurrency::Country:
			{
				_FindByCountry();
				break;
			}
		}
	}
public:

	static void FindCurrency()
	{
		system("cls");
		_DrawScreenHeader("Find Currency");

		cout << "Do you find by [1] Country  or [2] code ? ";
		_PerformCurrencyOption(_FindCurrency(_ReadInput()));
		
	}
};

