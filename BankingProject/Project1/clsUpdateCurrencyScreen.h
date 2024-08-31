#pragma once
#include<iostream>
#include"clsCurrency.h" // back-end
#include"clsScreen.h"
#include"clsValidate.h"
using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
{
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
public:
	static void UpdateCurrency()
	{
		cout << "enter the name of CountryCurrency that you want to update it" << endl;
		string code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(code);
		if (Currency.IsEmpty()) cout << " NOT EXIST " << endl;
		else {
			_PrintCurrency(Currency);
			cout << "enter the rate ? " << endl;
			float amount; cin >> amount;
			Currency.UpdateRate(amount);
			cout << "SUCCESSFUL" << endl;
			cout << endl;
			_PrintCurrency(Currency);
		}
	}
	
};

