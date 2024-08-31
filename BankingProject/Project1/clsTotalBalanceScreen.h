#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsClientListScreen.h"
using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
public:

	static void ShowTotalBalance()
	{
		_DrawScreenHeader("Balances List Screen");

		clsClientListScreen::ShowClientLIst();
		float TotalBalance = clsBankClient::ShowTotalBalance();
	}
};