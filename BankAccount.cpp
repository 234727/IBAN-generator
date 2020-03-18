
#include "stdafx.h"
#include "BankAccount.h"
//*************************************************
int BankAccount::calculateDivRest(std::string &number, int divider)
{
	int dividend = 0;
	std::string copyNumber = number;

	while (copyNumber.length() > 0)
	{
		while (1)
		{
			dividend += std::stoi(copyNumber.substr(0, 1));
			copyNumber.erase(0, 1);

			if (copyNumber.length() == 0)
				break;

			if (dividend < divider)
				dividend *= 10;
			else
				break;
		}

		dividend %= divider;
	}
	return dividend;
}
//*************************************************
bool BankAccount::checkIbanNumber()
{
	if (ibanNumber.length() != 26)
		return false;

	if (calculateDivRest(prepareIbanToDiv()) != 1)
		return false;
	return true;
}
//*************************************************
std::string BankAccount::prepareIbanToDiv()
{
	std::string copyNumber = ibanNumber;
	copyNumber += "2521";
	copyNumber += copyNumber.substr(0, 2);
	copyNumber.erase(0, 2);

	return copyNumber;
}
//*************************************************
void BankAccount::generateCheckDigitForNrb()
{
	ibanNumber[9] = calculateCheckDigitForNrb();
}
//*************************************************
void BankAccount::generateUserId()
{
	for (int i = 10; i < ibanNumber.length(); ++i)
	{
		char digit = (std::rand() % 10) + 48;
		ibanNumber[i] = digit;
	}
}
//*************************************************
BankAccount::BankAccount(std::string bankId)
{
	ibanNumber = "";
	for (int i = 0; i < 26; ++i)
		ibanNumber += "0";
	for (int i = 0; i < bankId.length(); ++i)
		ibanNumber[i + 2] = bankId[i];
	generateCheckDigitForNrb();
	generateUserId();
	generateCheckDigitForIban(prepareIbanToDiv());
}
//*************************************************
void BankAccount::generateCheckDigitForIban(std::string number)
{
	int rest = calculateDivRest(number);
	int checkSum = 98 - rest;
	if (checkSum < 10)
	{
		char digit = 48;
		ibanNumber[0] = digit;
		digit += checkSum;
		ibanNumber[1] = digit;
	}
	else
	{
		char digit = 48 + checkSum % 10;
		checkSum /= 10;
		ibanNumber[1] = digit;
		digit = 48 + checkSum;
		ibanNumber[0] = digit;
	}
}
//*************************************************
std::string BankAccount::getBankId()
{
	// identyfikator banku - cyfry od 2-6, kolejne 3 - id oddzie³u banku, ostatnia - suma kontrolna 
	std::string bankId = ibanNumber.substr(2, 4);
	return bankId;
}
//*************************************************
bool BankAccount::checkBankNumber()
{
	if (calculateCheckDigitForNrb() == ibanNumber[9])
		return true;
	return false;
}
//*************************************************
char BankAccount::calculateCheckDigitForNrb()
{
	std::string copy = ibanNumber.substr(3, 7);
	int weights[] = { 3, 9, 7, 1, 3, 9, 7 };
	int sum = 0, rest = 0;
	char tenth;

	for (int i = 0; i < copy.length(); ++i)
		sum += std::stoi(copy.substr(i, 1)) * weights[i];

	rest = sum % 10;
	if (rest != 0)
		rest = 10 - rest;
	tenth = rest + 48;

	return tenth;
}
//************************************************
BankAccount::BankAccount()
{
	ibanNumber = "";
}


BankAccount::~BankAccount()
{
}
