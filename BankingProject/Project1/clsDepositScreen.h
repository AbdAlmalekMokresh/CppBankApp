#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsValidate.h"
#include"clsBankClient.h"

using namespace std;
class clsDepositScreen : protected clsScreen
{
	static string _ReadAccountNumber()
	{
		cout << "Enter Acccount Number : ";
		string AccNum = clsInputValidate::ReadString();
		return AccNum;
	}
public:

	static void DepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account number not exists, try another one " << endl;
			AccountNumber = _ReadAccountNumber();
		}
		cout << "Enter the amount you want to deposit ? " << endl;
		float amount = 0;
		amount = clsInputValidate::ReadFloatNumber();

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Print();

		cout << "Are you sure you want to deposit this number ? " << endl;
		char ans = 'n';
		cin >> ans;
		if (ans == 'Y' || ans == 'y') {

			Client.Deposit(amount);
			cout << " Deposit Successfully .... :)  " << endl;
			cout << " New balance is " << Client.GetAccountBalance() << endl;
		}
		else cout << "operation was cancelled " << endl;

	}
};

