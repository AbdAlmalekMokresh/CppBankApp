#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"
#include"clsPerson.h"

using namespace std;
								//  BACK-END HERE .... ~
class clsBankClient : public clsPerson
{
private:
	enum _enMode {EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };
	_enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool MarkedForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string line, string Seperator="#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(line, Seperator);

		return clsBankClient(_enMode::UpdateMode, vClientData[0], vClientData[1], 
			vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stoi(vClientData[6]));
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(_enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	string _ConvertClientToLine(clsBankClient Client, string sep="#//#")
	{// firstname,lastname, email ,phonenumber, accountnumb, pincode , balance
	// --- #//# --- #//# --- 
		return Client.GetFirstName() + sep + Client.GetLastName() + sep +
			Client.GetEmail() + sep + Client.GetPhone() + sep + Client.GetAccountNumber() +
			sep + Client.GetPinCode() + sep + to_string(Client.GetAccountBalance());
	}
	void _SaveClientDataToFile(vector<clsBankClient>Clients)
	{
		fstream MyFile;
		MyFile.open("E:/Clients.txt", ios::out);// overwrite

		string line;
		if (MyFile.is_open())
		{
			for (auto C : Clients)
			{
				if (C.MarkedForDelete == true)continue; 

				line = _ConvertClientToLine(C);
				MyFile << line << endl;
			}
		}
		MyFile.close();
	}
	/*
	Example about Clients.txt File
	===============================
	Mohammed123#//#abu-hadhu#//#32423#//#da#//#A101#//#32423#//#1626.000000
	Khaili#//#Ahmed#//#Khalil#//#8928982#//#A102#//#1234#//#7176.000000
	*/

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vClients;
		fstream MyFile;

		MyFile.open("E:/Clients.txt", ios::in); // read mode 
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(line);
				vClients.push_back(Client);

			}
			MyFile.close();
		}
		return vClients;
	}
	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient&C : _vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}

	void _AddDataLineToFile(string line)
	{
		fstream MyFile;
		MyFile.open("E:/Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientToLine(*this));
	}
	static void _SaveTransferLogFile(string From , string To , float amount)
	{
		fstream MyFile;
		MyFile.open("E:/LogFileTransfer.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string line = From + "###" + To + "###" + to_string(amount);
			MyFile << line << "\n";
		}
		MyFile.close();

	}
public:

	clsBankClient(_enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == _enMode::EmptyMode);
	}
	// we don't have set accountNumber only get
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	// __declspec(property(put = GetAccountNumber)) string AccountNumber;
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPhone, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	
	void Print()
	{
		cout << " Client Card: ";
		cout << "\nFirstName: " << FirstName;
		cout << "\nLastName : " << LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << Email;
		cout << "\nPhone    : " << Phone;
		cout << "\n Acc Num : " << _AccountNumber;
		cout << "\n Acc balance: " << _AccountBalance;
		cout << "\n-------------------\n";

	}

	static clsBankClient Find(string AccountNumber)
	{
		// vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("E:/Clients.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("E:/Clients.txt", ios::in); // read mode

		if(MyFile.is_open())
		{ 
			string line;
			while (getline(MyFile, line))
			{
				clsBankClient Client =  _ConvertLinetoClientObject(line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1 , FaildAccountNumberExist};
	
	enSaveResult Save()
	{
		switch (_Mode)
		{
			case _enMode::EmptyMode:
			{
				return enSaveResult::svFaildEmptyObject;
			}
			case _enMode::UpdateMode:
			{
				_Update();
				return enSaveResult::svSucceeded;
			}
			case _enMode::AddNewMode:
			{
				if (clsBankClient::IsClientExist(_AccountNumber))
				{
					return enSaveResult::FaildAccountNumberExist;
				}
				else {
					_AddNew();
					_Mode = _enMode::UpdateMode;
					return enSaveResult::svSucceeded;
				}
			}
		}
	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(_enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientDataFromFile();
		for (auto &C : vClients)
		{
			if (C.GetAccountNumber() == this->GetAccountNumber())
			{
				C.MarkedForDelete = true;
				break;
			}
		}
		_SaveClientDataToFile(vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> ShowListClients()
	{
		vector<clsBankClient> Clients = _LoadClientDataFromFile();
		return Clients;
	}
	static float ShowTotalBalance()
	{
		vector<clsBankClient> Clients = _LoadClientDataFromFile();
		float TotalBalance = 0.0;
		for (auto C : Clients)
		{
			TotalBalance += C.GetAccountBalance();
		}
		return TotalBalance;
	}
	void Deposit(float amount)
	{
		this->AccountBalance += amount;
		Save();
	}
	bool Withdraw(float amount)
	{
		if (amount > _AccountBalance)
		{
			return false;
		}
		else {
			this->AccountBalance -= amount;
			Save();
			return true;
		}
	}

	enum enTransfer { enSuccessful = 1, enFaildExceedBalance = 2, enFaildObjectEmpty = 3 };
	static enTransfer Transfer(string From, string To, float amount) 
	{
		clsBankClient ClientFrom = clsBankClient::Find(From);
		clsBankClient ClientTo = clsBankClient::Find(To);

		if (ClientTo.IsEmpty() || ClientFrom.IsEmpty()) return enTransfer::enFaildObjectEmpty;

		if (ClientFrom.GetAccountBalance() < amount) return enTransfer::enFaildExceedBalance;

		ClientFrom.SetAccountBalance(ClientFrom.GetAccountBalance() - amount);
		ClientTo.SetAccountBalance(ClientTo.GetAccountBalance() + amount);
		enSaveResult Res1 =  ClientFrom.Save();
		enSaveResult Res2 = ClientTo.Save();
		_SaveTransferLogFile(From, To, amount);
		return enTransfer::enSuccessful;
	}
	static vector<string> LoadDataFromLogFile()
	{
		fstream MyFile;
		MyFile.open("E:/LogFileTransfer.txt", ios::in); // read mode
		vector<string>History;
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				History.push_back(line);
			}
		}
		MyFile.close();
		return History;
	}
};