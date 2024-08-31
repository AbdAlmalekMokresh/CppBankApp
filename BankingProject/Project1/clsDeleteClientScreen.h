#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsValidate.h"
using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
public:

	static void DeleteClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eDeleteClient))
			return;

			_DrawScreenHeader("Delete Screen");
			cout << "ENTER ACCOUNT NUMBER TO DELETE IT : ";
			string AccountNumber;
			AccountNumber = clsInputValidate::ReadString();

			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "This account number not exist, choose another one" << endl;
				AccountNumber = clsInputValidate::ReadString();
			}
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			Client.Print();
			cout << "___________________" << endl;
			cout << " Are you sure you want to delete this Client y/Y? " << endl;

			char answer = 'n';
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				if (Client.Delete())
				{
					cout << "Successfully" << endl;
					Client.Print();
				}
				else cout << "Failed" << endl;
			}
	}
};

