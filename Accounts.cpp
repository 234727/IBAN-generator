
#include "stdafx.h"
#include "Accounts.h"
#include "stdafx.h"

void Accounts::addAccount(std::string bankId)
{
	BankAccount *acc = new BankAccount(bankId);
	accounts.push_back(*acc);
}
//*************************************************
void Accounts::addAccounts(int amount)
{
	//std::string bankNumbers[] = { "1030194", "1090259", "1020212", "1050193", "1140200", "1090194", "1140108", "1090244", "1090285", "1090136" };

	for (int i = 0; i < amount; ++i)
	{
		int nr = rand() % 10;
		BankAccount *acc = new BankAccount(bankNumbers[i]);
		accounts.push_back(*acc);
		// std::cout << acc->getIbanNumber() << std::endl;
	}
}
//*************************************************
void Accounts::showAllFromBankId(std::string bankId)
{
	for (BankAccount acc : accounts)
	{
		if (acc.getBankId() == bankId)
			std::cout << acc.getIbanNumber() << std::endl;
	}
}
//**************************************************
int Accounts::findAccount(std::string ibanNumber)
{
	for (int i = 0; i < accounts.size(); ++i)
		if (accounts[i].getIbanNumber() == ibanNumber)
			return i;

	return -1;
}
//**************************************************
void Accounts::deleteAccount(std::string ibanNumber)
{
	int position = findAccount(ibanNumber);
	if (position != -1)
		accounts.erase(accounts.begin() + position);
}
//**************************************************
void Accounts::showAll()
{
	for (BankAccount acc : accounts)
		std::cout << acc.getIbanNumber() << std::endl;
}
//**************************************************
void Accounts::checkIbanNumber(std::string ibanNumber)
{
	int position = findAccount(ibanNumber);
	if (position != -1)
	{
		if (accounts[position].checkIbanNumber())
			std::cout << "Konto o nr: " << ibanNumber << " jest poprawne." << std::endl;
		else
			std::cout << "Konto o nr: " << ibanNumber << " jest niepoprawne." << std::endl;
	}
	else
		std::cout << "Nie znaleziono konta o podanym nr." << std::endl;

}
//**************************************************
void Accounts::checkBankNumber(std::string ibanNumber)
{
	int position = findAccount(ibanNumber);
	if (position != -1)
	{
		if (accounts[position].checkIbanNumber())
			std::cout << "Konto o nr: " << ibanNumber << "ma poprawny nr banku." << std::endl;
		else
			std::cout << "Konto o nr: " << ibanNumber << "ma niepoprawny nr banku." << std::endl;
	}
	else
		std::cout << "Nie znaleziono konta o podanym nr." << std::endl;

}
//**************************************************
std::string Accounts::getAccount(int position)
{
	if (accounts.size() - 1 < position)
		return "";
	return accounts[position].getIbanNumber();
}
//**************************************************
Accounts::Accounts()
{
}


Accounts::~Accounts()
{
}
