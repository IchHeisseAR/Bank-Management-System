#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class Add {
private:
	double addAmount;
protected:
	std::string accountNumber;
	int CVC, SecurityPin;
	double currentAmount;
public:
	Add(): accountNumber(""), CVC(0), SecurityPin(0), currentAmount(0), addAmount(0) {}
	void Details() {
		std::cout << "Enter your Account Number: ";
		std::getline(std::cin, accountNumber);
		std::cout << "Enter your CVC number: ";
		std::cin >> CVC;
		std::cout << "Enter Card Security Pin: ";
		std::cin >> SecurityPin;
		std::cout << "Enter Current Amount: ";
		std::cin >> currentAmount;
	}
	void setDetailsAdd() {
		Details();
		std::cout << "Enter Amount to add: ";
		std::cin >> addAmount;
	}
	void changeAmount() {
		std::cout << "Enter new Amount: ";
		std::cin >> addAmount;
	}
	Add(std::string accountNumber, int CVC, int SecurityPin, double Amount, double Current_Amount) {
		this->accountNumber = accountNumber;
		this->CVC = CVC;
		this->SecurityPin = SecurityPin;
		this->addAmount = Amount;
		this->currentAmount = Current_Amount;
	}
	std::string getAccountNumber() { return accountNumber; }
	int getCVC() { return CVC; }
	int getSecurityPin() { return SecurityPin; }
	double getAmount() { return addAmount; }
	double getCurrentAmount() { return currentAmount; }
	double getAddedAmount() { return currentAmount + addAmount; }
	void ReceiptAdd() { 
		std::cout << "\*********************************************************************\n";
		std::cout<<"          ~Here is your Receipt~ \n\n" << "          Account Number: " << getAccountNumber() << std::endl << "          Amount Added: " << getAmount() << std::endl << "          Your current Amount is now: " << getAddedAmount() << std::endl<<std::endl;
		std::cout << "\*********************************************************************\n";
	}
	~Add(){}
};

class Withdraw : protected Add {
private:
	double withdrawalAmount;
public:
	Withdraw(): withdrawalAmount(0) {}
	void setDetailsWithdrawal() {
		Details();
		std::cout << "Enter Amount to Withdraw (Amount must be less than " << currentAmount << ": ";
		std::cin >> withdrawalAmount;
		while (withdrawalAmount > currentAmount) {
			std::cout << "\nYou can't Withdraw more than " << currentAmount << ", please enter a valid amount: ";
			std::cin >> withdrawalAmount;
		}
	}
	Withdraw(double withdrawalAmount) { this->withdrawalAmount = withdrawalAmount; }
	double getWithdraw() { return withdrawalAmount; }
	double getWithdrawnAmount() { return currentAmount - withdrawalAmount; }
	void ReceiptWithdraw() {
		std::cout << "\*********************************************************************\n\n";
		std::cout << "          Account Number: " << getAccountNumber() << std::endl << "          Amount Withdrawn: " << getWithdraw() << std::endl << "          Your current amount is now: " << getCurrentAmount() << std::endl;
		std::cout << "\*********************************************************************\n";
	}
	~Withdraw(){}
};

class Loan {
private:
	double loanAmount, duration;
public:
	Loan(): loanAmount(0), duration(0) {
		std::cout << "Enter Loan Amount: ";
		std::cin >> loanAmount;
		std::cout << "Enter Loan Duration: ";
		std::cin >> duration;
	}
	double getLoanAmount() { return loanAmount; }
	double getDuration() { return duration; }
	void displayLoan() {
		std::cout << "\*********************************************************************\n\n";
		std::cout << "           Loan Amount by you: "<<getLoanAmount() << std::endl << "          Chosen Duration: " << getDuration() << std::endl;
		std::cout << "\*********************************************************************\n";
	}
	~Loan(){}
};

class CustomerCare {
private:
	int query, choice;
public:
	CustomerCare(): query(0), choice(0) {
		std::cout << "1. For Queries relating to any problem.\n";
		std::cout << "2. For Opening a bank Account.\n";
		std::cout << "3. For Closing existing bank account\n";
		std::cout << "Enter your Choice: ";
	}
	~CustomerCare(){}
};

void Types() {
	std::cout << "\n\nPress\n";
	std::string Types[3] = { "1. If you're a user.","\n2. If you're an Authorized Person.\n","3. If you want a Job (We're Actively Hiring).\n" };
	for (int i = 0; i < 3; i++) {
		std::cout << Types[i];
	}
	std::cout << "Enter Your Choice: ";
}
void userMenu(){
	std::cout << "\n\nPress\n";
	std::string Menu[4] = { "1. To Add Money.\n","2. To Withdraw Money.\n", "3. To go to the ATM.\n","4. For Customer Servie.\n" };
	for (int i = 0; i < 4; i++) {
		std::cout << Menu[i];
	}
	std::cout << "Enter Your Choice: ";
}
void AuthorityMenu(){}
void JobSeekerMenu(){}

int main(){
	system("cls");
	system("COLOR E4");
	std::cout << "\n\n                                 *********************************************\n";
	std::cout << "                                 *                                           *\n";
	std::cout << "                                 *        ~ Welcome to A U Z A Bank ~        *\n";
	std::cout << "                                 *                                           *\n";
	std::cout << "                                 *********************************************\n";

	int choice, userChoice, authChoice, jobChoice;
	char tryAgain='y', receipt, choiceNew;
	do {
		Types();
		std::cin >> choice;
		switch (choice) {
		case 1:
			userMenu();
			std::cin >> userChoice;
			switch (userChoice) {
			case 1:
				std::cin.ignore();
				Add addMoney;
				addMoney.setDetailsAdd();
				std::cout << "\n Would you like a receipt? (y/Y): ";
				std::cin >> receipt;
				if (receipt == 'y' || receipt == 'Y') {
					addMoney.ReceiptAdd();
				}
				std::cout << "Would you like to change the amount added: ";
				std::cin >> choiceNew;
			}
		}

		std::cout << "\nTry again? (y/Y): ";
		std::cin >> tryAgain;
	} while (tryAgain == 'y' || tryAgain == 'Y');
	return 0;
}