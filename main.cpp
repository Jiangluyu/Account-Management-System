#include"headers.h"
/*
	two design patterns:
		one in Sort.h, which uses Strategy Pattern
		the other in Account.h, which uses Decorator Pattern
*/
int main(void)
{
	StockAccount* stock = new StockAccount();
	BankAccount* bank = new BankAccount();

	mainMenu(bank, stock);
}
void displayMainMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ¨y ¨z ¨{ ¨| ¨} ¨~ ¨€  Welcome to the Account Management System  ¨€ ¨~ ¨} ¨| ¨{ ¨z ¨y                   *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                      Please select an account to access:                                           *");
	puts(" *                                                                                                                    *");
	puts(" *                                         [1] Stock Portfolio Account                                                *");
	puts(" *                                         [2] Bank Account                                                           *");
	puts(" *                                         [3] settings                                                               *");
	puts(" *                                         [0] exit                                                                   *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void mainMenu(BankAccount* bank, StockAccount* stock)
{
	char option = 'a';

	while (option != '0')
	{
		displayMainMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);
		switch (option)
		{
		case '1':
			system("CLS");
			StockMenu(stock);
			break;
		case '2':
			system("CLS");
			BankMenu(bank);
			break;
		case '3':
			system("CLS");
			SettingMenu(stock);
			break;
		default:
			system("CLS");
			fflush(stdin);
			break;
		}
	}
	
	stock->read();
	bank->read();
	ofstream outfile("generalInfo.txt", ios::app);
	double totalPortfolioValue = 0.0;
	Stock* p = new Stock;
	for (p = stock->getHead()->pNext; p != NULL; p = p->pNext)
	{
		totalPortfolioValue += p->share*stock->getPrice(p->stockSymbol);
	}
	totalPortfolioValue += bank->getCashBalance();
	
	time_t now;
	struct tm *tm_now;
	char timeTmp[25];
	time(&now);
	tm_now = localtime(&now);
	strftime(timeTmp, 25, "%D %H:%M:%S", localtime(&now));

	outfile << totalPortfolioValue << " " << timeTmp << endl;

	outfile.close();
	//system("pause");
	exit(0);
}

void displayStockMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ¨y ¨z ¨{ ¨| ¨} ¨~ ¨€  Welcome to the Account Management System  ¨€ ¨~ ¨} ¨| ¨{ ¨z ¨y                   *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                      Please select an account to access:                                           *");
	puts(" *                                                                                                                    *");
	puts(" *                                   [1] Display the price for a stock symbol                                         *");
	puts(" *                                   [2] Display the current portfolio                                                *");
	puts(" *                                   [3] Buy shares                                                                   *");
	puts(" *                                   [4] Sell shares                                                                  *");
	puts(" *                                   [5] View a graph for the portfolio value                                         *");
	puts(" *                                   [6] View transaction history                                                     *");
	puts(" *                                   [0] Return to previous menu                                                      *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void StockMenu(StockAccount* stock)
{

	char option = 'a';

	while (option != '0')
	{
		displayStockMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			char symbolTmp[20];
			cout << "Please enter the stock symbol: ";
			cin >> symbolTmp;
			stock->displayStockPrice(symbolTmp);
			system("pause");
			while ((ch = getchar()) != '\n' && ch != EOF);
			system("CLS");
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			stock->displayPortfolio();
			system("pause");
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			stock->buyShares();
			system("pause");
			while ((ch = getchar()) != '\n' && ch != EOF);
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			stock->sellShares();
			system("pause");
			while ((ch = getchar()) != '\n' && ch != EOF);
			system("CLS");
			break;
		case '5':
			system("CLS");
			displayCommonMenu();
			stock->displayPortfolioGraph();
			system("pause");
			system("CLS");
			break;
		case '6':
			system("CLS");
			displayCommonMenu();
			stock->displayTransactionHistory();
			system("pause");
			system("CLS");
			break;
		case '0':
			break;
		default:
			cout << "Invalid input. Please enter your choice again" << endl;
			system("pause");
			fflush(stdin);
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displayCommonMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *             ¨y ¨z ¨{ ¨| ¨} ¨~ ¨€  Welcome to the Account Management System  ¨€ ¨~ ¨} ¨| ¨{ ¨z ¨y                   *");
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void displayBankMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ¨y ¨z ¨{ ¨| ¨} ¨~ ¨€  Welcome to the Account Management System  ¨€ ¨~ ¨} ¨| ¨{ ¨z ¨y                   *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                      Please select an account to access:                                           *");
	puts(" *                                                                                                                    *");
	puts(" *                                   [1] View account balance                                                         *");
	puts(" *                                   [2] Deposit money                                                                *");
	puts(" *                                   [3] Withdraw money                                                               *");
	puts(" *                                   [4] Print out history                                                            *");
	puts(" *                                   [0] Return to previous menu                                                      *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void BankMenu(BankAccount* bank)
{

	char option = 'a';

	while (option != '0')
	{
		displayBankMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
			bank->displayAccountBalance();
			system("pause");
			system("CLS");
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			cout << "Enter the money you want to deposit: $";
			double moneyTmpDeposit;
			cin >> moneyTmpDeposit;
			bank->depositMoney(moneyTmpDeposit);
			system("pause");
			while ((ch = getchar()) != '\n' && ch != EOF);
			system("CLS");
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			cout << "Enter the money you want to withdraw: $";
			double moneyTmpWithdraw;
			cin >> moneyTmpWithdraw;
			bank->withdrawMoney(moneyTmpWithdraw);
			system("pause");
			while ((ch = getchar()) != '\n' && ch != EOF);
			system("CLS");
			break;
		case '4':
			system("CLS");
			displayCommonMenu();
			bank->printHistory();
			system("pause");
			system("CLS");
			break;
		case '0':
			break;
		default:
			cout << "Invalid input. Please enter your choice again" << endl;
			system("pause");
			fflush(stdin);
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void displaySettingMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ¨y ¨z ¨{ ¨| ¨} ¨~ ¨€  Welcome to the Account Management System  ¨€ ¨~ ¨} ¨| ¨{ ¨z ¨y                   *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                      Please select an account to access:                                           *");
	puts(" *                                                                                                                    *");
	puts(" *                                   [1] switch the sorting method                                                    *");
	puts(" *                                   [0] Return to previous menu                                                      *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	printTime();
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");

}

void SettingMenu(StockAccount* stock)
{
	char option = 'a';

	while (option != '0')
	{
		displaySettingMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);
		char choice = '0';
		switch (option)
		{
		case '1':
			system("CLS");
			displayCommonMenu();
		
			cout << "Current sorting method is: ";
			switch (stock->getBubble()->getSortKind())
			{
			case 1:
				cout << "bubble sort" << endl;
				break;
			case 2:
				cout << "select sort" << endl;
				break;
			case 3:
				cout << "insert sort" << endl;
				break;
			}

			cout << "1.bubble sort" << endl << "2.select sort" << endl << "3.insert sort" << endl;
			cout << "Enter your choice:";
			cin >> choice;
			while (choice != '1' && choice != '2' && choice != '3')
			{
				cout << "Please enter a valid number." << endl;
				cin >> choice;
			}
			switch (choice)
			{
			case'1':
				cout << "Bubble sort selected." << endl;
				stock->getBubble()->setsortKind(1);
				system("pause");
				while ((ch = getchar()) != '\n' && ch != EOF);
				break;
			case'2':
				cout << "Select sort selected." << endl;
				stock->getBubble()->setsortKind(2);
				system("pause");
				while ((ch = getchar()) != '\n' && ch != EOF);
				break;
			case'3':
				cout << "Insert sort selected." << endl;
				stock->getBubble()->setsortKind(3);
				system("pause");
				while ((ch = getchar()) != '\n' && ch != EOF);
				break;
			default:
				break;
			}
			system("CLS");
			break;
		case '0':
			break;
		default:
			cout << "Invalid input. Please enter your choice again" << endl;
			system("pause");
			fflush(stdin);
			system("CLS");
			break;
		}
	}
	system("CLS");
	return;
}

void printTime()
{
	time_t now;

	struct tm *tm_now;

	time(&now);

	tm_now = localtime(&now);
	if (tm_now->tm_hour >= 10 && tm_now->tm_min >= 10)
	{
		printf(" *                                            %d-%d-%d %d:%d                                                         *\n",
			tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
	}
	else if (tm_now->tm_hour < 10 && tm_now->tm_min >= 10)
	{
		printf(" *                                            %d-%d-%d 0%d:%d                                                         *\n",
			tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
	}
	else if (tm_now->tm_hour >= 10 && tm_now->tm_min < 10)
	{
		printf(" *                                            %d-%d-%d %d:0%d                                                         *\n",
			tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
	}
	else
	{
		printf(" *                                            %d-%d-%d 0%d:0%d                                                         *\n",
			tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
	}
}