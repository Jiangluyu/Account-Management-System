#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<Windows.h>

#include"Account.h"
#include"BankAccount.h"
#include"List_stock.h"
#include"List_bank.h"
#include"Sort.h"
#include"StockAccount.h"

using namespace std;
/*
char* getTime()
{
	time_t seconds;
	seconds = time(NULL);
	tm * timeinfo;
	timeinfo = localtime(&seconds);
	std::cout << "The current local time and date is:" << asctime(timeinfo);
	return asctime(timeinfo);
}
*/
