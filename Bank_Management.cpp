#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

class Add {
private:
	double addAmount, totalAdd;
protected:
	std::string accountNumber;
	int CVC, SecurityPin;
	double currentAmount;
public:
	Add() : accountNumber(""), CVC(0), currentAmount(rand() % 999999), SecurityPin(0), addAmount(0), totalAdd(0) {}
	void Details() {
		std::cout << "Enter your Account Number: ";
		std::getline(std::cin, accountNumber);
		std::cout << "Enter your CVC number: ";
		std::cin >> CVC;
		std::cout << "Enter Card Security Pin: ";
		std::cin >> SecurityPin;
	}
	void setAddAmount() {
		std::cout << "Enter Amount to add: ";
		std::cin >> addAmount;
		currentAmount += addAmount;
		totalAdd += addAmount;

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
	double getAmount() { return totalAdd; }
	double getCurrentAmount() { return currentAmount; }
	double getAddedAmount() { return currentAmount += addAmount; }
	void ReceiptAdd() { 
		std::cout << "\n*********************************************************************\n";
		std::cout<<"\n          ~Here is your Receipt~ \n\n" << "          Account Number: " << getAccountNumber() << std::endl << "          Amount Added: " << getAmount() << std::endl << "          Your current Amount is now: " << getCurrentAmount() << std::endl;
		std::cout << "\n*********************************************************************\n";
	}
	~Add(){}
};

class Withdraw : protected Add {
private:
	double withdrawalAmount, totalWithdraw;
public:
	Withdraw() : withdrawalAmount(0), totalWithdraw(0) { Details(); }
	void setWithdrawAmount() {
		std::cout << "Enter Amount to Withdraw (Current Amount is " << currentAmount << "): ";
		std::cin >> withdrawalAmount;
		while (withdrawalAmount > currentAmount) {
			std::cout << "You can't Withdraw more than " << currentAmount << ", please enter a valid amount: ";
			std::cin >> withdrawalAmount;
		}
		currentAmount -= withdrawalAmount;
		totalWithdraw += withdrawalAmount;
	}
	Withdraw(double withdrawalAmount) { this->withdrawalAmount = withdrawalAmount; }
	double getWithdraw() { return totalWithdraw; }
	double getWithdrawnAmount() { return currentAmount; }
	void ReceiptWithdraw() {
		std::cout << "\*********************************************************************\n\n";
		std::cout <<"          ~Here is your Receipt~ \n\n"<< "          Account Number: " << getAccountNumber() << std::endl << "          Amount Withdrawn: " << getWithdraw() << std::endl << "          Your current amount is now: " << getWithdrawnAmount() << std::endl;
		std::cout << "\*********************************************************************\n";
	}
	~Withdraw(){}
};

class Loan {
private:
	double loanAmount;
	std::string duration;
public:
	Loan(): loanAmount(0), duration("") {
		std::cout << "Enter Loan Amount: ";
		std::cin >> loanAmount;
		std::cin.ignore();
		std::cout << "Enter Loan Duration: ";
		std::getline(std::cin, duration);
	}
	double getLoanAmount() { return loanAmount; }
	std::string getDuration() { return duration; }
	void displayLoan() {
		std::cout << "\*********************************************************************\n\n";
		std::cout << "          ~Loan Info~\n\n" << "          Loan Amount by you : " << getLoanAmount() << std::endl << "          Chosen Duration : " << getDuration() << std::endl << std::endl;
		std::cout << "\*********************************************************************\n";
	}
	~Loan(){}
};

class CustomerCare {
private:
	int choice, query, pin;
public:
	CustomerCare(): choice(0), query(0), pin(0) {
		std::cout << "1. For Queries relating to any problem.\n";
		std::cout << "2. For Opening a bank Account.\n";
		std::cout << "3. For Closing existing bank account\n";
		std::cout << "Enter your Choice: ";
		std::cin >> choice;
	}
	void Query() {}
	void OpenBank() {
		std::cout << "Setting up things for you...\n";
		std::cout << "You're opening bank account for:\n";
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
	std::string Menu[4] = { "1. To Add Money.\n","2. To Withdraw Money.\n","3. For Loan\n","4. For Customer Service.\n" };
	for (int i = 0; i < 4; i++) {
		std::cout << Menu[i];
	}
	std::cout << "Enter Your Choice: ";
}
void AuthorityMenu(){}
void JobSeekerMenu(){}

int main() {
	srand(time(NULL));
	system("cls");
	system("COLOR E4");
	std::cout << "\n\n                                 *********************************************\n";
	std::cout << "                                 *                                           *\n";
	std::cout << "                                 *        ~ Welcome to A U Z A Bank ~        *\n";
	std::cout << "                                 *                                           *\n";
	std::cout << "                                 *********************************************\n";

	int choice, userChoice, authChoice, jobChoice;
	char tryAgain = 'y', receipt, choiceNew;
	do {
		Types();
		std::cin >> choice;
		system("COLOR 79");
		switch (choice) {
		case 1:
			userMenu();
			std::cin >> userChoice;
			system("Color B0");
			switch (userChoice) {
			case 1: {
				std::cin.ignore();
				Add addMoney;
				addMoney.Details();
				do {
					addMoney.setAddAmount();
					std::cout << "Add more money(y/Y): ";
					std::cin >> choiceNew;
				} while (choiceNew == 'y' || choiceNew == 'Y');
				std::cout << "Would you like a receipt? (y/Y): ";
				std::cin >> receipt;
				if (receipt == 'y' || receipt == 'Y') { addMoney.ReceiptAdd(); }
				break;
			}
			case 2: {
				std::cin.ignore();
				Withdraw withdrawMoney;
				do {
					withdrawMoney.setWithdrawAmount();
					std::cout << "Withdraw more money?(y/Y): ";
					std::cin >> choiceNew;
				} while (choiceNew == 'y' || choiceNew == 'Y');
				std::cout << "Would you like a receipt? (y/Y): ";
				std::cin >> receipt;
				if (receipt == 'y' || receipt == 'Y') {
					withdrawMoney.ReceiptWithdraw();
				}
				break;
			}
			case 3: {
				Loan getLoan;
				getLoan.displayLoan();
				break;
			}
			case 4: {
				CustomerCare care;

			}
			default:
				std::cout << "\nINVALID INPUT!";
			}
		
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			std::cout << "\nINVALID INPUT!";
		}
		std::cout << "\nApply for Job, Add/Withdraw money, Authorized?(y/Y): ";
		std::cin >> tryAgain;
	} while (tryAgain == 'y' || tryAgain == 'Y');

	return 0;
}