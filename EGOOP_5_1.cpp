#include <iostream>

using namespace std;

class bank_account
{
	char name[30];
	int acc_no;
	char type[15];
	int balance;
public:
	void init_values(void);
	void display(void);
	void deposit(void);
	void withdraw(void);
};

void bank_account :: init_values(void)
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter Account number: ";
	cin >> acc_no;
	cout << "Enter account type: ";
	cin >> type;
	cout << "Enter initial balance: ";
	cin >> balance;
	cout << endl;
}

void bank_account :: display(void)
{
	cout << "Bank account name: " << name << endl;
	cout << "Account Balance  : " << balance << endl;
	cout << "\n";
}

void bank_account :: deposit(void)
{
	int dep;
	cout << "Current balance: " << balance << endl;
	cout << "Enter the amount to be deposited: ";
	cin >> dep;
	balance += dep;
	bank_account :: display();
}

void bank_account :: withdraw(void)
{
	int wit;
	cout << "Current balance: " << balance << endl;
	cout << "Enter the amount:";
	cin >> wit;
	if(wit <= balance)
		balance -= wit;
	else
		cout << "Not enough balance.\n";
	bank_account :: display();
}

int main()
{
	cout << "Please select one of the options:\n1. Create a new bank account\n2. Display account info.\n3. deposit money\n4. withdraw money\n";
	int option;
	cin >> option;
	while(option<5)
	{
		bank_account ashu;
		if(option == 1)
			ashu.init_values();
		else if(option == 2)
			ashu.display();
		else if(option == 3)
			ashu.deposit();
		else 
			ashu.withdraw();
		cout << "Enter the option:";
		cin >> option;
	}
	return 0;
}	