#pragma once
#include<iostream>
#include<string>
class BankAccount
{
	std::string ibanNumber;

	// funkcje pomocnicze do generowania iban
	char calculateCheckDigitForNrb();
	std::string prepareIbanToDiv();
	void generateCheckDigitForNrb();
	void generateUserId();
	void generateCheckDigitForIban(std::string number);
	int calculateDivRest(std::string &number, int divider = 97);

public:
	bool checkIbanNumber();
	bool checkBankNumber();
	std::string getIbanNumber() { return ibanNumber; }
	std::string getBankId();
	BankAccount(std::string bankId);
	BankAccount();
	~BankAccount();
};

