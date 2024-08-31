#pragma once
#include<iostream>
#include"clsCurrency.h"  // back-end
#include"clsScreen.h"
#include"clsValidate.h"
using namespace std;

class clsCalculatorScreen : protected clsScreen
{
public:
	static void CalculatorCurrency()
	{
		cout << "code1 FROM ? " << endl;
		string code1 = clsInputValidate::ReadString();
		clsCurrency Cur1 = clsCurrency::FindByCode(code1);
		while (Cur1.IsEmpty())
		{
			cout << "NOT FOUND" << endl;
			code1 = clsInputValidate::ReadString();
			Cur1 = clsCurrency::FindByCode(code1);
		}
		cout << endl;
		cout << "code2 TO ? " << endl;
		string code2 = clsInputValidate::ReadString();
		clsCurrency cur2 = clsCurrency::FindByCode(code2);
		while (cur2.IsEmpty())
		{
			cout << "NOT FOUND" << endl;
			code2 = clsInputValidate::ReadString();
			cur2= clsCurrency::FindByCode(code2);
		}
		cout << " enter the amount ? " << endl;
		float amount;
		cin >> amount;
		float answer = Cur1.ConvertToAnotherCurrency(amount, cur2);
		cout << answer << endl;
	}
	
};

