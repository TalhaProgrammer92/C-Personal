#include <iostream>
#include <ctime>
#include <cstring>
#include <vector>
#include <fstream>
#include <conio.h>

using namespace std;

/*
Important: Must create a file name "user_info.txt" and write:
[user_name]	-- minimum length of 3
[password]	-- minimum length of 8
*/


//////////////////////////////
// Misc - Functions
//////////////////////////////
string currentTime();								// To get current date and time as string
vector<string> readFile(const string&);				// To read from a file
void writeToFile(const string&, const string&);		// To write to a file
void userAuthentication();							// For user authentication
void hold();										// Hold user on a screen untill he press a key


//////////////////////////////
// Account - Class
//////////////////////////////
class Account {
private:
	unsigned int Id;			// For unique identifier
	string name;				// Account Name
	unsigned long int balance;	// Account Balance
	string type;				// Type: saving, checking, etc

public:
	Account (unsigned int, string, string);					// Constructor
	void deposit(unsigned long int);						// To deposit money
	unsigned long int withdraw(unsigned long int);			// To withdraw the money
	bool transfer(Account, unsigned long int);				// To transfer money into another account
	void displayInfo();										// To display account's information
	unsigned int getId();									// To get id of the account
	unsigned long int getCurrentBalance();					// To get current balance
};


//////////////////////////////
// Transaction - Class
//////////////////////////////
class Transaction {
private:
	unsigned int Id;			// For unique identifier
	unsigned int account_id;	// Associated Account
	string type;				// Such as deposit, withdraw and transfer
	unsigned long int amount;	// The transaction amount
	string data_time;			// To store the time and date of the transaction

public:
	Transaction (unsigned int, unsigned int, string, unsigned long int);	// Constructor
	void displayInfo();														// Display transaction information
	unsigned int getAccountId();											// To get account id
};


//////////////////////////////
// Bank - Class
//////////////////////////////
class Bank {
private:
	vector<Account> accounts;
	vector<Transaction> transactions;
	unsigned int transaction_id_counter, current_account_id;

	bool isValidId(unsigned int);					// To check whether the given account id is valid or not
	unsigned int getAccountIndex(unsigned int);		// To get the index of specific account id

public:
	Bank ();

	void createAccount();				// To create a new account
	void openAccount();					// Open an existing account

	void deposit();						// To deposit money to a specific account
	void withdraw();					// To withdraw money from a specific account
	void transfer();					// To transfer money between two accounts

	void displayAccountInfo();			// To display all the information of specific account
	void displayTransactionHistory();	// To display all the transaction history
};


//////////////////////////////
// User - Class
//////////////////////////////
class User {
private:
	string name;		// Name of the user
	string password;	// Password to be set by the user

public:
	User (string, string);	// Constructor

	void loginUser();		// Login an old user
	void registerUser();	// Register a new user
};


//////////////////////////////
// Main - Function
//////////////////////////////
int main() {
	userAuthentication();
	Bank my_bank;
	int option;

	while (true) {
		// Main menu
		system("cls");
		cout << "Select an option" << endl;
		cout << "1. Create an account\n" << "2. Open an account\n" << "3. Quit\n" << endl;
		cin >> option;

		cout << endl;

		switch (option) {
			case 1:
				// Account creation
				my_bank.createAccount();
				continue;
			case 2:
				// Open an exiting account
				my_bank.openAccount();
				break;
			default:
				exit(0);
		}

		// Account menu
ACCOUNT_DEAL:
		system("cls");
		cout << "Select an option" << endl;
		cout << "1. Deposit\n" << "2. Withdraw\n" << "3. Transfer\n"  << "4. Account History\n" << "5. Transaction History\n" << "6. Back\n" << endl;
		cin >> option;

		cout << endl;

		switch (option) {
			case 1:
				my_bank.deposit();
				goto ACCOUNT_DEAL;
			case 2:
				my_bank.withdraw();
				goto ACCOUNT_DEAL;
			case 3:
				my_bank.transfer();
				goto ACCOUNT_DEAL;
			case 4:
				my_bank.displayAccountInfo();
				goto ACCOUNT_DEAL;
			case 5:
				my_bank.displayTransactionHistory();
				goto ACCOUNT_DEAL;
			case 6:
				continue;
			default:
				exit(0);
		}
	}
}


//////////////////////////////
// Misc - Functions
//////////////////////////////

// The currentTime function
string currentTime() {
	time_t now = time(0);
	struct tm *tstruct = localtime(&now);
	char buf[80];

	// Format the date and time as desired
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tstruct);

	return buf;
}

// The readFile function
vector<string> readFile(const string& filename) {
	ifstream file(filename);
	vector<string> content;

	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			content.push_back(line);
		}
		file.close();
	}

	return content;
}

// The writeToFile function
void writeToFile(const string& filename, const string& content) {
	ofstream file(filename);

	if (file.is_open()) {
		file << content;
		file.close();
	}
}

// The user authentication function
void userAuthentication() {
	// Variables
	char choice;
	string name, password;
	vector<string> content;

	cout << "1-Login, 2-Register>> ";
	choice = getche();

	// User Authentication
	do {
		cout << "\nEnter user name>> ";
		getline(cin, name);
		if (name.length() < 3)
			cout << "It must contain at least 3 letters" << endl;
	} while (name.length() < 3);

	do {
		cout << "Enter password>> ";
		getline(cin, password);
		if (password.length() < 8)
			cout << "It must contain at least 8 characters" << endl;
	} while (password.length() < 8);

	// Login
	if (choice == '1') {
		content = readFile("user_info.txt");
		if (content.size() == 2) {
			if (!(content.at(0) == name && content.at(1) == password))
				exit(0);
		}
	}
	// Register
	else if (choice == '2') {
		writeToFile("user_info.txt", name + '\n' + password);
	} else
		exit(0);
	system("cls");
}

// The hold method
void hold() {
	cout << "Press any key to continue...";
	getch();
	system("cls");
}


//////////////////////////////
// Account - Class
//////////////////////////////

// The constructor
Account::Account(unsigned int Id, string name, string type) {
	this->Id = Id;
	this->name = name;
	this->type = type;
	this->balance = 0;
}

// The deposit method
void Account::deposit(unsigned long int amount) {
	this->balance += amount;
}

// The displayInfo method
void Account::displayInfo() {
	cout << "ID:\t" << this->Id << endl
	     << "Name:\t" << this->name << endl
	     << "Balance:\t" << this->balance << endl
	     << "Type:\t" << this->type << endl;
}

// The transfer method
bool Account::transfer(Account account, unsigned long int amount) {
	if (amount <= this->balance) {
		account.deposit(amount);
		this->balance -= amount;
		return true;
	}
	return false;
}

// The withdraw method
unsigned long int Account::withdraw(unsigned long int amount) {
	if (amount <= this->balance) {
		this->balance -= amount;
		return amount;
	}
	return 0;
}

// The getId method
unsigned int Account::getId() {
	return this->Id;
}

// The getCurrentBalance method
unsigned long int Account::getCurrentBalance() {
	return this->balance;
}


//////////////////////////////
// Transaction - Class
//////////////////////////////

// The Constructor
Transaction::Transaction(unsigned int transaction_id, unsigned int account_id, string type, unsigned long int amount) {
	this->data_time = currentTime();
	this->Id = transaction_id;
	this->account_id = account_id;
	this->type = type;
	this->amount = amount;
}

// The displayInfo method
void Transaction::displayInfo() {
	cout << "Transaction Id:\t" << this->Id << endl
	     << "Account Id:\t" << this->account_id << endl
	     << "Transaction type:\t" << this->type << endl
	     << "Amount:\t\t" << this->amount << endl
	     << "Date & Time:\t" << this->data_time << endl;
}

// The getAccountId method
unsigned int Transaction::getAccountId() {
	return this->account_id;
}


//////////////////////////////
// Bank - Class
//////////////////////////////

// The constructor
Bank::Bank() {
	this->transaction_id_counter = 1;
}

// The createAccount method
void Bank::createAccount() {
	// Local variables
	unsigned int account_id;
	string account_name, account_type;
	int choice;

	// Get account name from customer
	cout << "Enter account name>> ";
	getline(cin, account_name);

	// Get account type form customer
	cout << "Select account type:\n1-Checking, 2-Savings>> ";
	cin >> choice;
	if (choice == 1)
		account_type == "check";
	else if (choice == 2)
		account_type = "saving";

	// Get account id from teller
	while (true) {
		cout << "Enter a unique account id>> ";
		cin >> account_id;
		if (!this->isValidId(account_id))
			break;
		else
			cout << "Already exists!" << endl;
	}

	// Creating the new account
	Account new_acocunt(account_id, account_name, account_type);
	this->accounts.push_back(new_acocunt);
	system("cls");
}

// The opernAccount method
void Bank::openAccount() {
	unsigned int temp_id;

	// Get data
	do {
		cout << "Enter your account id>> ";
		cin >> temp_id;
		if (!this->isValidId(temp_id))
			cout << "Invalid Id! Please try again..." << endl;
	} while (!this->isValidId(temp_id));

	this->current_account_id = temp_id;
	system("cls");
}

// The deposit method
void Bank::deposit() {
	unsigned long int amount;
	unsigned int account_index;

	account_index = this->getAccountIndex(this->current_account_id);

	// Get the amount
	cout << "\nEnter amount>> ";
	cin >> amount;

	// Deposit
	this->accounts.at(account_index).deposit(amount);

	Transaction new_transaction(this->transaction_id_counter++, this->current_account_id, "deposit", amount);
	this->transactions.push_back(new_transaction);

	system("cls");
}

// The withdraw method
void Bank::withdraw() {
	unsigned long int withdraw_amount, current_amount;
	unsigned int account_index;

	// Get required info

	account_index = this->getAccountIndex(this->current_account_id);
	current_amount = this->accounts.at(account_index).getCurrentBalance();

	do {
		cout << "\nEnter amount>> ";
		cin >> withdraw_amount;
		if (withdraw_amount > current_amount)
			cout << "Insufficient balance! " + to_string(current_amount) << endl;
	} while (withdraw_amount > current_amount);

	// Withdraw
	this->accounts.at(account_index).withdraw(withdraw_amount);

	Transaction new_transaction(this->transaction_id_counter++, this->current_account_id, "withdraw", withdraw_amount);
	this->transactions.push_back(new_transaction);

	system("cls");
}

// The transfer method
void Bank::transfer() {
	unsigned long int transfer_amount, current_amount;
	unsigned int account_index_from, account_id_to, account_index_to;

	// Get required data
	do {
		cout << "\nEnter account id (To)>> ";
		cin >> account_id_to;
	} while (!isValidId(account_id_to));

	account_index_from = this->getAccountIndex(this->current_account_id);
	account_index_to = this->getAccountIndex(account_id_to);
	current_amount = this->accounts.at(account_index_from).getCurrentBalance();

	do {
		cout << "Enter amount>> ";
		cin >> transfer_amount;
		if (transfer_amount > current_amount)
			cout << "Insufficient balance! " + to_string(current_amount) << endl;
	} while (transfer_amount > current_amount);

	// Transfer
	this->accounts.at(account_index_to).deposit(this->accounts.at(account_index_from).withdraw(transfer_amount));

	Transaction new_transaction(this->transaction_id_counter++, this->current_account_id, "transfer [to " + to_string(account_id_to) + "]", transfer_amount);
	this->transactions.push_back(new_transaction);

	system("cls");
}

// The displayAccountInfo method
void Bank::displayAccountInfo() {
	this->accounts.at(this->getAccountIndex(this->current_account_id)).displayInfo();
	hold();
}

// The displayTransactionHistory method
void Bank::displayTransactionHistory() {
	for (unsigned int i = 0; i < this->transactions.size(); i++) {
		if (this->transactions.at(i).getAccountId() == this->current_account_id) {
			this->transactions.at(i).displayInfo();
			cout << endl;
		}
	}
	hold();
}

// The isValidId method
bool Bank::isValidId(unsigned int account_id) {
	for (unsigned int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts.at(i).getId() == account_id)
			return true;
	}
	return false;
}

// The getAccountIndex method
unsigned int Bank::getAccountIndex(unsigned int account_id) {
	unsigned int i;
	for (i = 0; i < this->accounts.size(); i++) {
		if (this->accounts.at(i).getId() == account_id)
			break;
	}
	return i;
}


//////////////////////////////
// User - Class
//////////////////////////////

// The constructor
User::User (string name, string password) {
	if (name.length() >= 3 && password.length() >= 8) {
		this->name = name;
		this->password = password;
	}
}

// The login methd
void User::loginUser() {
	vector<string> data = readFile("user_info.txt");
	string user_name = data.at(0), user_password = data.at(1);

	if (data.size() == 2 && user_name.length() >= 3 && user_password.length() >= 8) {
		if (!(this->name == user_name && this->password == user_password))
			cout << "Something went wrong!" << endl;
		exit(0);
		cout << "Successful!" << endl;
	} else
		cout << "Something went wrong!" << endl;
	hold();
}

// The register method
void User::registerUser() {
	if (readFile("user_info.txt").size() != 2)
		writeToFile("user_info.txt", this->name + '\n' + this->password);
}
