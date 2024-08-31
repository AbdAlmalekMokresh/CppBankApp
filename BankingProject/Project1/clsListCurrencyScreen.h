#pragma once
#include<iostream>
#include"clsCurrency.h"
#include<vector>
#include<string>
#include<iomanip>
#include"clsScreen.h"
using namespace std;
class clsListCurrencyScreen : protected clsScreen
{
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout<< setw(40) << left << Currency.CurrencyName() << "  |  " 
			<< setw(20) << left << Currency.CurrencyCode() << "   |   " 
			<< setw(20) << left << Currency.Rate() << endl;
	}
public:

	static void ListScreen()
	{
		_DrawScreenHeader("LIST SCREEN CURRENCY");
		cout << endl;
		vector<clsCurrency> Currency = clsCurrency::GetCurrenciesList();
		if (Currency.size() == 0) cout << "NO CURRENCY EXIST " << endl;

		for (int i = 0;i < Currency.size();i++)
		{
			_PrintCurrencyRecord(Currency[i]);
		}
	}
};

