#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

	//variables
	double loanAmount;
	double annualInterest;
	double monthlyPayment;
	double balance;
	double paidOnBalance = 0;
	double interest = 0;
	double totalInterestPaid = 0;
	int month = 1;

	//precisionDecision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//userInput
	cout << "What is the loan amount? ";
	cin >> loanAmount;
	cout << "What is the annual interest? Type answer as a decimal (.1 for 10%, etc) ";
	cin >> annualInterest;
	cout << "What is the monthly payment? ";
	cin >> monthlyPayment;

	//initialBalanceSet
	balance = loanAmount;

	//monthlyInterestSet
	double monthlyInterest = annualInterest / 12;

	//validityCheck
	if (monthlyPayment <= balance * monthlyInterest) {
		cout << "You are not paying enough that you will never be able to pay your loan. \n";
		return 0;
	}

	//structureOutput
	cout << "Month\t" << setw(12) << "Balance\t" << setw(12) << "Payment\t" << "PaidOnBalance\t" << setw(10) << "Interest\t" << setw(10) << "Total Int. Paid\n";

	//calculation
	while (balance > 0) {
		if (balance < monthlyPayment) {
			interest = monthlyInterest * balance;
			monthlyPayment = balance + interest;
			paidOnBalance = balance;
			balance = 0;
			totalInterestPaid = totalInterestPaid + interest;
			cout << month << "\t " << setw(10) << balance << "\t " << setw(10) << monthlyPayment << "\t " << setw(12) << paidOnBalance << "\t " << setw(8) << interest << "\t " << setw(14) << totalInterestPaid << "\n";
			return 0;
		}
		interest = monthlyInterest * balance;
		balance = balance + interest - monthlyPayment;
		paidOnBalance = monthlyPayment - interest;
		totalInterestPaid = totalInterestPaid + interest;
		cout << month << "\t " << setw(10) << balance << "\t " << setw(10) << monthlyPayment << "\t " << setw(12) << paidOnBalance << "\t " << setw(8) << interest << "\t " << setw(14) << totalInterestPaid << "\n";
		if (month % 12 == 0) {
			cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		}
		month++;
	}
}