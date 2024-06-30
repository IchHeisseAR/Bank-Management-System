
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <vector>

class Add {
private:
	double addAmount, totalAdd;
protected:
	std::string accountNumber;
	int CVC, SecurityPin;
	static long float currentAmount;
public:
	Add() : accountNumber(""), CVC(0), SecurityPin(0), addAmount(0), totalAdd(0) {}
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
	virtual void Receipt() {
		std::cout << "\n*********************************************************************\n";
		std::cout << "\n          ~Here is your Receipt~ \n\n" << "          Account Number: " << getAccountNumber() << std::endl << "          Amount Added: " << std::setprecision(2) << getAmount() << std::endl << "          Your current Amount is now: " << getCurrentAmount() << std::endl;
		std::cout << "\n*********************************************************************\n";
	}
	~Add() {}
};
long float Add::currentAmount = rand() % 99999;
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
	void Receipt() {
		std::cout << "\n*********************************************************************\n";
		std::cout << "          ~Here is your Receipt~ \n\n" << "          Account Number: " << getAccountNumber() << std::endl << "          Amount Withdrawn: " << std::setprecision(2) << getWithdraw() << std::endl << "          Your current amount is now: " << getWithdrawnAmount() << std::endl;
		std::cout << "\n*********************************************************************\n";
	}
	~Withdraw() {}
};

class Loan {
private:
	double loanAmount;
	std::string duration;
public:
	Loan() : loanAmount(0), duration("") {
		std::cout << "Enter Loan Amount: ";
		std::cin >> loanAmount;
		std::cin.ignore();
		std::cout << "Enter Loan Duration: ";
		std::getline(std::cin, duration);
	}
	double getLoanAmount() { return loanAmount; }
	std::string getDuration() { return duration; }
	void displayLoan() {
		std::cout << "\n*********************************************************************\n\n";
		std::cout << "          ~Loan Info~\n\n" << "          Loan Amount by you : " << getLoanAmount() << std::endl << "          Chosen Duration : " << getDuration() << std::endl << std::endl;
		std::cout << "\n*********************************************************************\n";
	}
	~Loan() {}
};

class CustomerCare : protected Add {
private:
	int choice, type, accNumber, ZIP;
	char queryAgain;
	double initialDeposit;
	std::string password, name, CNIC, DOB, Email, phNo, Address, City, State;
public:
	CustomerCare() : choice(0), queryAgain(NULL), type(0), initialDeposit(0), name(""), CNIC(""), accNumber(0), DOB(""), Email(""), phNo(""), password(""), ZIP(0), Address(""), City(""), State("") {
		do {
			std::cout << "\n1. For Queries relating to any problem.\n";
			std::cout << "2. For Opening a bank Account.\n";
			std::cout << "3. For Closing existing bank account\n";
			std::cout << "Enter your Choice: ";
			std::cin >> choice;
			switch (getChoice()) {
			case 1:
				Query();
				break;
			case 2:
				OpenBank();
				displayOpen();
				break;
			case 3:
				std::cin.ignore();
				closeBank();
				break;
			default:
				std::cout << "\nInvalid Choice.\n";
			}
		} while (choice > 3 || choice < 1);
	}
	void Query() {
		std::cout << "\nState your Query Type\n1. Technical Issue\n2. Issue Related to Account\n3. Other sort of Assistance.\nChoice: ";
		std::cin >> choice;
		std::cout << std::endl;
		switch (choice) {
		case 1:
			std::cout << "\n1. Why aren't online services working right now?\n2. What happened to the ATM?\n3. Vending Machine got my money stuck in it\nPick your Problem: ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				std::cout << "Our IT team is working on it right now, Thank you for your patience.\nWe will have it fixed shortly!";
				break;
			case 2:
				std::cout << "Due to heavy storms, our ATM machine can't synchronize with your Data.\nThank you for your empathy!";
				break;
			case 3:
				std::cout << "Mr. Davidson here will help you with your problem!\nHere are the $" << rand() % 30 << " you had inserted!";
				break;
			default:
				std::cout << "\nInvalid Input.\n";
				Query();
			}
			break;
		case 2:
			std::cout << "\n1. How do I close my Account?\n2. What are the requirements to open a new Account?\n3. How to Activate my bank account?\nChoice: ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				std::cout << "Here are the few steps, the process could even take days to finish.\nFirst, Write a closure statement to the bank.\nSecond, We will take further verification steps to permanently wipe your bank account from existence.\nThe process will then persist and your bank account will close.";
				break;
			case 2:
				std::cout << "You'll need your CNIC, Driving License (optional), Domicile and some other documents depending on the type of account you want to open.";
				break;
			case 3:
				std::cout << "You need to make an initial deposit of atleast 1 Dollar to activate your bank account. Then you are ready to make transactions freely!";
				break;
			default:
				std::cout << "\nInvalid Input.\n";
				Query();
			}
			break;
		case 3:
			std::cout << "1. How do I apply for Job?\n2. Who is the Manager here? I wish to talk to him.\nWhat are the Opening and closing timings of the bank.\nChoice: ";
			std::cin >> choice;
			switch (choice) {
			case 1:
				std::cout << "You'll need some skills depending on the post you want the job on, furthermore you must have atleast Matric Qualification.";
				break;
			case 2:
				std::cout << "Mr. J.Robert Falcone is the Manager. You'll need an appointment to see him however.";
				break;
			case 3:
				std::cout << "Our Bank stays open Monday - Saturday from 9 AM through 5 PM.\nATM however, stays open 24/7!";
				break;
			default:
				std::cout << "\nInvalid Input.\n";
				Query();
			}
			break;
		default:
			std::cout << "\nInvalid Input!\n";
			Query();
		}
		std::cout << '\n';
		std::cout << "\nNeed more assistance? (y/Y): ";
		std::cin >> queryAgain;
		if (queryAgain == 'y' || queryAgain == 'Y') { Query(); }
	}
	void bankDetails() {
		std::cout << "Enter CNIC: ";
		std::getline(std::cin, CNIC);
		std::cout << "Enter Date of Birth: ";
		std::getline(std::cin, DOB);
		std::cout << "Enter Email: ";
		std::getline(std::cin, Email);
		std::cout << "Enter Current Phone Number: ";
		std::getline(std::cin, phNo);
		std::cout << "Enter your City: ";
		std::getline(std::cin, City);
		std::cout << "Enter your State: ";
		std::getline(std::cin, State);
		std::cout << "Enter your Address: ";
		std::getline(std::cin, Address);
		std::cout << "Enter ZIP Code: ";
		std::cin >> ZIP;
		accNumber = rand() % INT_MAX;
	}
	void OpenBank() {
		std::cout << "Setting up things for you...\n";
		std::cout << "\nSelect Type:\n1. Saving\n2. Joint\n3. Business\nEnter your Choice: ";
		std::cin >> type;
		std::cin.ignore();
		std::cout << "\nEnter Name: ";
		std::getline(std::cin, name);
		bankDetails();
		std::cin.ignore();
		std::cout << "Please set up a Password: ";
		std::getline(std::cin, password);
		do {
			std::cout << "Please make an initial deposit to activate your Account: ";
			std::cin >> initialDeposit;
			if (initialDeposit < 0) { std::cout << "\nEnter a valid Amount: \n"; }
		} while (initialDeposit < 0);
		currentAmount = initialDeposit;
		if (initialDeposit == 0) { std::cout << "Your Account is NOT activated as the initial deposit is $0.\nActivate your Account to get your Credit Card.\n"; }
		else { std::cout << "Thank you for Opening your Bank Account.\nHere is your Credit Card Good Sir!\n"; }
	}
	void closeBank() {
		std::cout << "\nYour Closing application is under process, Please wait...\nFor further verification, enter your current password: ";
		std::getline(std::cin, password);
		bankDetails();
		std::cout << "\nThe Bank Account " << getAccountNumber() << " has been Successfully closed.\nYou had $" << rand() % 999 << " saved.\n";
	}
	inline int getChoice() { return choice; }
	int getQuery() { return queryAgain; }
	int getType() { return type; }
	int getAccountNumber() { return accNumber; }
	int getZIP() { return ZIP; }
	double getDeposit() { return initialDeposit; }
	std::string getName() { return name; }
	std::string getPassword() { return password; }
	std::string getCNIC() { return CNIC; }
	std::string getDateOfBirth() { return DOB; }
	std::string getEmail() { return Email; }
	std::string getPhone() { return phNo; }
	std::string getCity() { return City; }
	std::string getState() { return State; }
	std::string getAddress() { return Address; }
	void displayOpen() { std::cout << "\nName: " << getName() << "\nCNIC: " << getCNIC() << "\nDate of Birth : " << getDateOfBirth() << "\nCity: " << getCity() << "\nState: " << getState() << "\nCurrent Amount: " << getDeposit(); }
	~CustomerCare() {}
};

void Types() {
	std::cout << "\n\nPress\n";
	std::string Types[3] = { "1. If you're a user.","\n2. If you're an Authorized Person.\n","3. If you want a Job (We're Actively Hiring).\n" };
	for (int i = 0; i < 3; i++) {
		std::cout << Types[i];
	}
	std::cout << "Enter Your Choice: ";
}
void userMenu() {
	std::cout << "\nPress\n";
	std::string Menu[4] = { "1. To Add Money.\n","2. To Withdraw Money.\n","3. For Loan\n","4. For Customer Service.\n" };
	for (int i = 0; i < 4; i++) {
		std::cout << Menu[i];
	}
	std::cout << "Enter Your Choice: ";
}
class Authority {
	int f, l, choice;
	char given;
	static int i;
	std::string fname, lname, etype;
	std::vector <std::string> firstName = { "Umer","Abdullah","Muneeb","Ayesha","Zeeshan","Moiz","Zain","Khateeja","Tariq","Daniyal" };
	std::vector <std::string> lastName = { "Javaid","Ahmad","Ijaz","Imtiaz","Khalil","-ul- Hassan","-ul- Arfeen","Yousaf","-ur- Rahman", "bin Abdur Rahman" };
	std::vector <std::string> employeeType = { "Accountant","Janitor", "Security Guard", "Receptionist", "IT Engineer" };
public:
	Authority() :f(0), l(0), choice(0), fname(""), lname("") {
		std::cout << "State your Type: \n1. HR\n2. Boss\3. Janitor\n4. Accountant\n5. Manager\nEnter your Choice: ";
		std::cin >> choice;
	}
	void manageEmployees() {
		std::cout << "\nYou have " << i << " employees working in your bank at the moment: \n";
		for (int j = 0; j < i; j++) { std::cout << j + 1 << ". " << firstName[rand() % firstName.size()] << " " << lastName[rand() % lastName.size()] << " (" << employeeType[rand() % employeeType.size()] << ") " << std::endl; }
		if (firstName.size() > 10) { std::cout << fname << " " << lname << std::endl; }
		std::cout << "\n1. Fire\n2. Hire\nEnter your Choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Enter Employee Number from the Given List: ";
			std::cin >> choice;
			if (choice >= 0 && choice <= i) {
			}
			else { std::cout << "\nInvalid Choice!\n"; }
			break;
		case 2:
			std::cout << "Enter First name of the new Employee: ";
			std::cin.ignore();
			std::getline(std::cin,fname);
			std::cout << "Enter Last Name: ";
			std::getline(std::cin, lname);
			firstName.push_back(fname);
			lastName.push_back(lname);
			for (int j = 0; j < employeeType.size(); j++) { std::cout << j + 1 << ". " << employeeType[j] << std::endl; }
			std::cout << "\nIs he from the one of the given types?(y/Y): ";
			std::cin >> given;
			switch (given) {
			case 'y':
			case 'Y':
				std::cout << "Select Type: ";
				std::cin >> choice;
				i++;
				break;
			default:
				std::cout << "Enter a new type: ";
				std::cin.ignore();
				std::getline(std::cin, etype);
				employeeType.push_back(etype);
			}
		}
	}
};
int Authority::i = rand() % 100;

class JobSeeker {
	int skill, qualification;
public:
	JobSeeker() :skill(0), qualification(0) {
		std::cout << "\nSelect your Qualification.\n1. Graduate\n2. F.Sc\n3. Matric\n4. Diploma\n5. None\nEnter your Choice: ";
		std::cin >> qualification;
		eligibility();
	}
	void eligibility() {
		switch (qualification) {
		case 1:
			std::cout << "Select your Degree type\n1. Bachelors\n2. Masters\nEnter your choice: ";
			std::cin >> qualification;
			switch (qualification) {
			case 1:
				std::cout << "Enter your Degree\n1. BS Accounting\n2. BS Finance\n3. BS Economic\n4. B.A";
				std::cin >> qualification;
				switch (qualification) {
				case1:
				case2:
				case3:
				case4:
					std::cout << "Your interview is scheduled on " << rand() % 30 << " / " << rand() % 12 << " / " << 2024;
					if (rand() %  2 == 1) { std::cout << "\nCongratulations! You're Hired as our new receptionist!"<<"\nYour Hourly salary is: $"<<rand()%20; }
					else { std::cout << "\nYou've failed the interview. I'm afraid you'll have to apply somewhere else Sir."; }
					break;
				default:
					std::cout << "\nInvalid Input!!!\n";
					eligibility();
				}
				break;
			case 2:
				std::cout << "Enter your Degree\n1. ";
				std::cin >> qualification;
				break;
			default:
				std::cout << "\nInvalid Input!\n";
				eligibility();
			}
			break;
		case 2:
			std::cout << "Enter your Qualification\n1. Pre Engineering\n2. ICS (Computer)\n3. ICS (Stats)\n4. None\nEnter your Choice: ";
			std::cin >> qualification;
			switch (qualification) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				std::cout << "\nYou're Ineligible\n";
				break;
			default:
				std::cout << "\nInvalid Input!\n";
				eligibility();
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			std::cout << "\nI'm afraid you're not eligible to apply for job at our bank.\n";
			break;
		default:
			std::cout << "\nInvalid input.\n";
			eligibility();
		}
	}
	int getQualification() { return qualification; }
	int getSkill() { return skill; }
	~JobSeeker() {}
};

int main() {
	system("cls");
	system("COLOR E4");
	std::cout << "\n\n                                 *********************************************\n";
	std::cout << "                                 *                                           *\n";
	std::cout << "                                 *        ~ Welcome to A U Z A Bank ~        *\n";
	std::cout << "                                 *                                           *\n";
	std::cout << "                                 *********************************************\n";

	int choice, userChoice, authChoice, jobChoice;
	char tryAgain = 'y', receipt, choiceNew;
	srand(time(NULL));
	Types();
	std::cin >> choice;
	switch (choice) {
	case 1:
		userMenu();
		std::cin >> userChoice;
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
			if (receipt == 'y' || receipt == 'Y') { addMoney.Receipt(); }
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
				withdrawMoney.Receipt();
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
			break;
		}
		default:
			std::cout << "\nINVALID INPUT!";
			main();
		}
		break;
	case 2: {
		Authority auth;
		auth.manageEmployees();
		break;
	}
	case 3:
		break;
	default:
		std::cout << "\nINVALID INPUT!";
		main();
	}
	std::cout << "\nApply for Job, Add/Withdraw money, Authorized?(y/Y): ";
	std::cin >> tryAgain;
	if (tryAgain == 'y' || tryAgain == 'Y') { main(); }
	std::cout << "\nThanks for preferring our bank service, have a NICE day!\n";
	return 0;
}
