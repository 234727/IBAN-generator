// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <cstdlib>
#include "BankAccount.h"
#include <ctime>
#include <cstdio>
#include "Accounts.h"
// PROGRAM:
// 1. dodawanie/usuwanie kont
// 2. sprawdzenie poprawnoœci nr konta 
// 3. sprawdzenie poprawnoœci id banku
// 4. wypisywanie wszystkich kont z listy, które s¹ z tego samego banku, co podany identyfikator

int main()
{
	std::srand(std::time(NULL));
	Accounts acc;

	acc.addAccounts(10);
	std::cout << "Konta na liscie: " << std::endl;
	acc.showAll();
	std::cout << std::endl << "Konta z banku o nr 1090: " << std::endl;
	acc.showAllFromBankId("1090");
	std::cout << std::endl << "Dodanie nowego banku o nr banku: 1030194" << std::endl;
	acc.addAccount("1030194");
	std::cout << std::endl << "Aktualna lista kont: " << std::endl;
	acc.showAll();
	std::cout << std::endl << "Usuniecie konta o nr: " << acc.getAccount(1) << std::endl;
	acc.deleteAccount(acc.getAccount(1));
	std::cout << std::endl << "Aktualna lita kont: " << std::endl;
	acc.showAll();

	char c = getchar();
    return 0;
}

