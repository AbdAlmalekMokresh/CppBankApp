#include<iostream>
#include"clsLoginScreen.h" 
#include"Global.h"
using namespace std;

int main()
{

	while (times) {
		system("color 0A");
		clsLoginScreen::ShowLoginScreen();
	}
	
	system("pause>0");

	return 0;
}