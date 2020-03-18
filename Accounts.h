#pragma once
#include<vector>
#include "BankAccount.h"
const std::string bankNumbers[] = { "1030194", "1090259", "1020212", "1050193", "1140200", "1090194", "1140108", "1090244", "1090285", "1090136" };

class Accounts
{
	std::vector<BankAccount> accounts;

	public:
	void addAccount(std::string bankId);	// 7 cyfr - nr banku oraz nr odzia³u (bez ósmej - cyfry kontrolnej)
	void addAccounts(int amount);			// dodaje wiele kont na podstawie nr banków z tablicy powy¿ej
	int findAccount(std::string ibanNumber);
	void deleteAccount(std::string ibanNumber);
	void checkIbanNumber(std::string ibanNumber);	// sprawdza poprawnoœæ nr iban podanego konta (musi siê znajdowaæ na liœcie)
	void checkBankNumber(std::string ibanNumber);	// sprawdza poprawnoœæ nr banku podanego konta (musi siê znajdowaæ na liœcie)
	void showAllFromBankId(std::string bankId);	// wyszukiwanie po pierwszych 4 cyfrach banku - nr banku 
	void showAll();
	std::string getAccount(int position);
	Accounts();
	~Accounts();
};

