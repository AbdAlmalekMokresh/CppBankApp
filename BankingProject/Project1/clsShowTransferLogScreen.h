#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;

class clsShowTransferLogScreen : protected clsScreen
{
public:
	static void TransferLogFile()
	{
		_DrawScreenHeader("Transfer log List Screen ");
		cout << endl; 
		vector<string> vHistory =  clsBankClient::LoadDataFromLogFile();
		for (int i = 0;i < vHistory.size();i++)
		{
			for (int j = 0;j < vHistory[i].size();j++)
			{
				if (vHistory[i][j] == '#') { cout << "		";continue; }
				cout << vHistory[i][j];
			}
			cout << endl;
		}
	}
};