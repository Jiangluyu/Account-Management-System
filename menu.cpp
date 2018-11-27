#include "headers.h"

void displayMainMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ▂ ▃ ▄ ▅ ▆ ▇ █  Welcome to the Account Management System  █ ▇ ▆ ▅ ▄ ▃ ▂                   *");
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
//main menu

void mainMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayMainMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		switch (option)
		{
		case '1':
			system("CLS");
			infoMenu();
			break;
		case '2':
			system("CLS");
			displayCommonMenu();
			
			break;
		case '3':
			system("CLS");
			displayCommonMenu();
			
			break;
		default:
			system("CLS");
			fflush(stdin);
			break;
		}
	}
	exit(0);
}

void displayInfoMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ▂ ▃ ▄ ▅ ▆ ▇ █  Welcome to the Account Management System  █ ▇ ▆ ▅ ▄ ▃ ▂                   *");
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

void infoMenu()
{

	char option = 'a';

	while (option != '0')
	{
		displayInfoMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		switch (option)
		{
		case '1':
			system("CLS");
			
			break;
		case '2':
			system("CLS");
			
			break;
		case '3':
			system("CLS");
			
			break;
		case '4':
			system("CLS");
			
			break;
		case '5':
			system("CLS");
			
			break;
		case '0':
			break;
		default:
			puts("Invalid input. Please enter your choice again\n");
			system("pause");
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
	puts(" *             ▂ ▃ ▄ ▅ ▆ ▇ █  Welcome to the Account Management System  █ ▇ ▆ ▅ ▄ ▃ ▂                   *");
	puts(" *                                                                                                                    *");
	puts(" **********************************************************************************************************************");
}

void displayFinanceMenu()
{
	puts(" **********************************************************************************************************************");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *                                                                                                                    *");
	puts(" *             ▂ ▃ ▄ ▅ ▆ ▇ █  Welcome to the Account Management System  █ ▇ ▆ ▅ ▄ ▃ ▂                   *");
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

void financeMenu()
{
	char option = 'a';

	while (option != '0')
	{
		displayFinanceMenu();
		int ch;
		option = 'a';
		scanf("%c", &option);
		while ((ch = getchar()) != '\n' && ch != EOF);//清空缓存区
		switch (option)
		{
		case '1':
			system("CLS");
			
			system("CLS");
			break;
		case '2':
			system("CLS");
			
			system("CLS");
			break;
		case '0':
			break;
		default:
			puts("Invalid input. Please enter your choice again\n");
			system("pause");
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
	printf(" *                                                %d-%d-%d %d:%d:%d                                                  *\n",
		tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
}