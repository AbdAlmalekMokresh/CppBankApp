#pragma once
#include<iostream>
#include<string>
#include<numeric>
#include<algorithm>
#include<limits>
using namespace std;
class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(int Number, int From, int To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(double Number, double From, double To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	/*
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) ||
			clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) ||
				clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}*/
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	/*
	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}*/

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
	/*
	static bool ValidateEmail(string email)
	{
		for (int i = 0;i < email.size();i++)
		{
			if (IsLetter(s[i]) || IsDigit(s[i]) || s[i] == '.' || s[i] == '_' || s[i] == '-')
				continue;
			else if (IsLetter(s[i]) == '@')
			{
				ind = i;
				break;
			}

		}
		// emial not containt #
		// only contain digit/letter/-._ @word.word
	}*/
	static string EncryptText(string Text, short EncryptKey)
	{
		for (int i = 0;i < Text.size();i++)
		{
			Text[i] = char((int)Text[i] + EncryptKey);
		}
		return Text;
	}
	static string Decrypt(string Text, short DecryptKey)
	{
		for (int i = 0;i < Text.size();i++)
		{
			Text[i] = char((int)Text[i] - DecryptKey);
		}
		return Text;
	}
};