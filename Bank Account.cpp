Project Bank System;
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    Account(string holder, int accNum, double bal) {
        accountHolder = holder;
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(double amount) {
        if(amount>0){
                balance += amount;
        cout << amount << " deposited. New balance: " << balance << endl;
        }
        else cout<<"invalid balance: "<<endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << amount << " withdrawn. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    virtual void displayInfo() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string holder, int accNum, double bal,double rate )
    :Account( holder,accNum,bal),interestRate(rate){}

    void applyInterest() {
        double interest = (interestRate / 100) * balance;
        balance += interest;
        cout << "Interest applied. New balance: " << balance << endl;
    }

    void displayInfo() override {
        cout << "Savings Account" << endl;
        Account::displayInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Bank Class
class Bank {
private:
    Account* accounts[100]; // Array of pointers (for polymorphism)
    int accountCount;

public:
    Bank() {
        accountCount = 0;
    }

    void addAccount(string holder, int accNum, double bal) {
        accounts[accountCount++] = new Account(holder, accNum, bal);
    }

    void addSavingsAccount(string holder, int accNum, double bal, double rate) {
        accounts[accountCount++] = new SavingsAccount(holder, accNum, bal, rate);
    }

    void displayAccounts() {
        for (int i = 0; i < accountCount; i++) {
            cout << "-----------------------" << endl;
            accounts[i]->displayInfo();
        }
    }

    ~Bank() {
        for (int i = 0; i < accountCount; i++) {
            delete accounts[i];
        }
    }
};

// Main Function
int main() {
    Bank bank;


    bank.addAccount("Ali", 1001, 5000);
    bank.addSavingsAccount("Omar", 1002, 10000, 5);

    bank.displayAccounts();
    cout << "\nPerforming transactions...\n";

    Account* acc1 = new Account("Test", 2001, 3000);
    acc1->deposit(500);
    acc1->withdraw(1000);
    acc1->displayInfo();

    cout << endl;

    SavingsAccount* acc2 = new SavingsAccount("Sara", 2002, 8000, 4);
    acc2->applyInterest();
    acc2->displayInfo();

    delete acc1;
    delete acc2;

    return 0;
}
