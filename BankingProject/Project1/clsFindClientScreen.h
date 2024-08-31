#pragma once
#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsFindClientScreen: protected clsScreen
{
	static void PrintClient(clsBankClient Client)
	{
		cout << "FirstName: " << Client.GetFirstName() << endl;
		cout << "LstName: " << Client.GetLastName() << endl;
		cout << "Acc Num : " << Client.GetAccountNumber() << endl;
		cout << "Balance : " << Client.GetAccountBalance() << endl;
	}

public:

	static void FindClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eFindClient))
			return;

		_DrawScreenHeader("##  FIND CLIENT  ##");
		cout << "ENTER ACCOUNT NUMBER : ";
		string AccountNumber;
		AccountNumber = clsInputValidate::ReadString();
		if(!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "NOT EXIST, Do you want to try another one ? [y/n] .. " << endl;
			char Answer = 'n';
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				FindClient();
		}
		else {
			clsBankClient Client = clsBankClient::Find(AccountNumber);	
			PrintClient(Client);
		}

	}
};