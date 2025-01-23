#include <iostream>

using namespace std;

int number = 0;

class BankAccount{
private:
	int accountNumber;
	string accountHolderName;
	double balance;
public:
	BankAccount(string accountHolderName);
	void deposit(double amount);
	double withdraw(double amount);
	void displayAccountDetails();
};

int main()
{
	BankAccount account("Talha Ahmad");
	
	account.deposit(50000);
	account.withdraw(1000);
	
	account.displayAccountDetails();
}

BankAccount::BankAccount(string accountHolderName)
{
	this->accountHolderName = accountHolderName;
	balance = 0;
	accountNumber = ++number;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

double BankAccount::withdraw(double amount)
{
	if (balance - amount >= 0){
		balance -= amount;
		return amount;
	}
	cout << "Insufficient balance! Rs." << balance << endl; 
	return 0;
}

void BankAccount::displayAccountDetails()
{
	cout << "Account Number:\t\t" << accountNumber << endl 
		 << "Account Holder Name:\t" << accountHolderName << endl
		 << "Current Balance:\tRs." << balance << endl;
}

