#pragma once
#include<iostream>
#include"clsScreen.h" // for inherit the screens 
#include"clsValidate.h" // validation
#include"clsBankClient.h"  // back-end
using namespace std;

class clsTransferScreen : protected clsScreen
{

private:
	static float _Print(string AccountNumber)
	{
		float balance = 0;
		vector<clsBankClient> vClients = clsBankClient::ShowListClients();
			for (auto C : vClients)
			{
				if (C.GetAccountNumber() == AccountNumber)
				{
					cout << "================" << endl;
					cout << "Name: " << C.GetFirstName() << " " << C.GetLastName() << endl;
					cout << "AccNum : " << C.GetAccountNumber() << endl;
					cout << "Balance : " << C.GetAccountBalance() << endl;
					balance = C.GetAccountBalance();
					break;
				}
			}
			return balance;
	}

public:
	static void Transfer()
	{
		_DrawScreenHeader("Transfer Screen");

		cout << "Enter the #AccountNumber To Transfer From : " << endl;
		string AccNum = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccNum))
		{
			cout << "NOT EXIST .. Try another one" << endl;
			AccNum = clsInputValidate::ReadString();
		}
		
		cout << "Enter the #AccNum to Transfer To : " << endl;
		string AccTo = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccTo))
		{
			cout << "NOT EXIST .. Try another one" << endl;
			AccTo = clsInputValidate::ReadString();
		}
		float b1 = _Print(AccNum);
		float b2 = _Print(AccTo);
		cout << "Enter the amount you want to transfer it ? " << endl;
		float amount = clsInputValidate::ReadFloatNumber();
		
		while (amount > b1 || amount <0)
		{
			cout << "amount is exceeded, try another one .. " << endl;
			cin >> amount;
		}
		clsBankClient::enTransfer Res;
		Res = clsBankClient::Transfer(AccNum, AccTo, amount);
		if (Res == clsBankClient::enTransfer::enSuccessful)
		{
			cout << "SUCCESSFULLY ..... " << endl;
		}
		else if (Res == clsBankClient::enTransfer::enFaildObjectEmpty)
		{
			cout << "Faild, Emtpy Object " << endl;
		}
		else cout << "the amount is exeeced for the balance .. " << endl;
	}

};