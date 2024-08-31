#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsValidate.h"
using namespace std;
class clsWithdrawScreen: clsScreen
{
	static string ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
public:
	static void WithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");

		string AccountNumber = ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "NOt exist, try another one " << endl;
			AccountNumber = ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		Client.Print();
		cout << endl;
		float amount; 
		cout << " Enter the amount that you want to withdraw ? " << endl;
		cin >> amount;

		cout << "are you sure you want to withdraw this money ? [y/n] " << endl;
		char ans = 'n';
		cin >> ans;
		if (ans == 'Y' || ans == 'y')
		{
			if (!Client.Withdraw(amount)) cout << " Denied " << endl;
			else {

				cout << " SUCCESSFULLY " << endl;
				cout << "Your balance is :  " << Client.GetAccountBalance() << endl;

			}
		}
	}

};

