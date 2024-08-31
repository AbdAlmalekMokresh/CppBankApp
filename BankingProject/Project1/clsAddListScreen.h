#pragma once
#include<iostream>
#include<string>
#include"clsValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;

class clsAddListScreen  : clsScreen
{
private:
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

	static void ShowAddClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eAddNewClient))
		{
			return;
		}
		string AccountNumber;
		cout << "Enter AccountNumber :" << endl;
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Invalid Number, enter another one" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		ReadClientInfo(NewClient);

		clsBankClient::enSaveResult Res;
		Res = NewClient.Save();
		switch (Res)
		{
		case clsBankClient::enSaveResult::svFaildEmptyObject:
		{
			cout << "FAILED" << endl;
		}
		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "SUCCESED" << endl;
			NewClient.Print();
		}
		}
	}
};

