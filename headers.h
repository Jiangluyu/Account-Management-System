#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include<iomanip>
#include<vector>
#include"Account.h"
#include"BankAccount.h"
#include"Sort.h"
#include"StockAccount.h" 

#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h" 
#include <engine.h>

using namespace std;

void printTime();
void mainMenu(BankAccount* bank, StockAccount* stock);
void displayMainMenu();
void StockMenu(StockAccount* stock);
void BankMenu(BankAccount* bank);
void displayCommonMenu();
void displayBankMenu();
void SettingMenu(StockAccount* stock);
void displaySettingMenu();
