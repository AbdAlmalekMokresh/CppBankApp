#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUser.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
private:
	static string NumberToText(int num)
	{
		if (num <= 19) {
			string arr[] = { "zero","one","two"
				,"three","four","five","six","seven","eight","night","ten","eleven","twelve","thirteen","forteen",
				"fifteen","sixteen","seventeen","eighteen","nighteen" };
			return arr[num];
		}
		else if (num < 100)
		{						// 2     3       4 
			string arr[] = { "twenty","thirty","forty","fivty","sixty","seventy","eighty","nighty" };
			return arr[(num / 10) - 2] + " " + NumberToText(num % 10);
		}
		else if (num < 1000)
		{
			return NumberToText(num / 100) + " Hundered " + NumberToText(num % 100);
		}
		else if (num < 100000)
		{
			return NumberToText(num / 1000) + " Thousand " + NumberToText(num % 1000);
		}

		else return "";
	}
	static float ShowTotalBalace()
	{
		float TotalBalance = clsBankClient::ShowTotalBalance();
		return TotalBalance;
	}

public:
	static void ShowClientLIst()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eListClients))
		{
			return;
		}

		_DrawScreenHeader("Client List");

		
		vector<clsBankClient>vClients = clsBankClient::ShowListClients();
		if (vClients.size() == 0)cout << "NO Clinets in this system" << endl;
		else {
			cout << "					Clients List	(" << vClients.size() << ")			" << endl;
			cout << "________________________________________________________________________________________________________________________" << endl;
			for (auto c : vClients)
			{
				cout << "|" << left << setw(10) << "FirstName: ";
				cout << left << setw(10) << c.GetFirstName();
				cout << "          ";

				cout << "|" << left << setw(10) << "LastName: ";
				cout << left << setw(10) << c.GetLastName();
				cout << "          ";

				cout << "|" << left << setw(14) << "Accountnumber: ";
				cout << left << setw(5) << c.GetAccountNumber();
				cout << "          ";

				cout << "|" << left << setw(5) << "Balance : ";
				cout << left << setw(10) << c.GetAccountBalance();
				cout << endl;
			}
			cout << "-------------" << endl;
			cout << "Total Balance: " << ShowTotalBalace() << "   " << NumberToText(ShowTotalBalace()) << endl;
			cout << "-------------" << endl;
		}
	}
	
};

