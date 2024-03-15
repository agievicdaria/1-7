#pragma once
#include "Money.h"
#include <string>
using namespace std;

class Account {
private:
    string ownerLastName;
    string accountNumber;
    double interestRate;
    Money balance;

public:
    const string& GetOwnerLastName() const { return ownerLastName; }
    const string& GetAccountNumber() const { return accountNumber; }
    double GetInterestRate() const { return interestRate; }
    const Money& GetBalance() const { return balance; }
    void SetOwnerLastName(const string& value) { ownerLastName = value; }
    void SetAccountNumber(const string& value) { accountNumber = value; }
    void SetInterestRate(double value) { interestRate = value; }
    void SetBalance(const Money& value) { balance = value; }

    void Init(const string& ownerLastName, const string& accountNumber, double interestRate, const Money& balance);
    void ChangeOwner(const string& newOwnerLastName);
    void Withdraw(const Money& amount);
    void Deposit(const Money& amount);
    void AddInterest();
    void ConvertToDollars();
    void ConvertToEuros();
    void ConvertToHryvnya();
    void Read();
    void Display() const;
    string ToString() const;
    string AmountInWords() const;  
};