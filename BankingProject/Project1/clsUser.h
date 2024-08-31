#pragma once
#include<iostream>
#include"clsPerson.h"
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
using namespace std;
// BACK-END
class clsUser : public clsPerson
{
private:
	enum enMode { eEmptyMode = 0, eAddNewUser = 1, eUpdateUser = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permission;

	bool _MarkedForDelete = false;
	static vector<string> _LoadDataFromLogFile()
	{
		fstream MyFile;
		MyFile.open("E:/LogFile.txt", ios::in);
		vector<string>vUserLogFile;;
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				vUserLogFile.push_back(line);
			}
		}
		MyFile.close();
		return vUserLogFile;
	}
	static clsUser _GetEmptyUser()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::eUpdateUser, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

	}
	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#")
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += User.Password + Seperator;
		UserRecord += to_string(User.Permission);

		return UserRecord;
	}
	static  vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("E:/User.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}
	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == this->UserName)
			{
				U = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vUsers);

	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConverUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("E:/User.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << "\n";

			MyFile.close();
		}

	}
	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream MyFile;
		MyFile.open("E:/User.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConverUserObjectToLine(U);
					MyFile << DataLine << "\n";

				}

			}

			MyFile.close();

		}

	}


public:

	enum enPermissions {
		eAll = -1, eListClients = 1, eAddNewClient = 2, eDeleteClient = 4, eUpdateClients = 8,
		eFindClient = 16, eTransaction = 32, eManageUsers = 64, eRegisterUser = 128
	};
	
	bool CheckPermission(enPermissions ePerm)
	{
		if(this->_Permission == enPermissions::eAll) 
			return true;

		if (this->Permission & ePerm == ePerm)
			return true;
		return false;
	}
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName,
		string Password, int Permission) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::eEmptyMode;
	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	int GetPermission()
	{
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPassword)) int Permission;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("E:/User.txt", ios::in); // read mode 

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsUser User = _ConvertLinetoUserObject(line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
			return _GetEmptyUser();
		}
	}
	static clsUser Find(string UserName, string password)
	{
		fstream MyFile;
		MyFile.open("E:/User.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsUser User = _ConvertLinetoUserObject(line);
				if (User.GetPassword() == password && User.GetUserName() == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUser();
	}

	enum enSaveResult { svFaildEmptyMode = 0, svSucceeded = 1, svFaildUserExists = 2 };

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::eAddNewUser:
		{
			if (IsUserExist(_UserName)) return enSaveResult::svFaildEmptyMode;
			else {
				_AddNew();
				_Mode = enMode::eUpdateUser;
				return enSaveResult::svSucceeded;
			}
			break;
		}
		case enMode::eEmptyMode:
		{
			return enSaveResult::svFaildEmptyMode;
			break;
		}
		case enMode::eUpdateUser:
		{
			_Update();
			return enSaveResult::svSucceeded;
			break;
		}
		}
	}

	bool Delete()
	{
		vector<clsUser> _vUsers = _LoadUsersDataFromFile();

		for (auto &C : _vUsers)
		{
			if (C.GetUserName() == this->UserName)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUser();

		return true;
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	static clsUser AddNewUser()
	{
		return clsUser(clsUser::enMode::eAddNewUser, "", "", "", "", "", "", 0);
	}
	static void _SaveInLogFile(string UserName)
	{
		fstream MyFile;
		MyFile.open("E:/LogFile.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << UserName << "\n";
		}
		MyFile.close();
	}
	static vector<string> GetLogFile()
	{
		vector<string>vUserNames = _LoadDataFromLogFile();
		return vUserNames;
	}
};
