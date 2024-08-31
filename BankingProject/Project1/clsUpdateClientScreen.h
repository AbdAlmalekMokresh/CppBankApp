#pragma once
#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsValidate.h"
#include"clsScreen.h"
using namespace std;
class clsUpdateClientScreen  : protected clsScreen
{
	static void ReadClientInfo(clsBankClient &Client)
	{
		cout << "\nEnter FirstName : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter LastName : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\n Enter Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\n Enter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\n Enter AccountBalance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
public:

	static void UpdateClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eUpdateClients))
			return;

		string AccountNumber;
		cout << "Please enter account Number " << endl;
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Invalid Number, enter another one " << endl;
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Client.Print();
		cout << "_________________" << endl;
		cout << " TO UPDATE " << endl;
		cout << "_________________" << endl;
		ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveRes;
		SaveRes = Client.Save();

		switch (SaveRes)
		{
				    case clsBankClient::enSaveResult::svFaildEmptyObject:
					{
						cout << "FAILED" << endl;
						break;
					}
					case clsBankClient::enSaveResult::svSucceeded:
					{
						cout << " SUCCESED" << endl;
					}
		}
	}
};