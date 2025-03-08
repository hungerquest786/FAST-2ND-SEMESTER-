#include <iostream>
using namespace std;

class Account {
public:
    int accountNumber;
    float balance;

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class saveAccount : public Account {
public:
    int interestRate;

    void calculateInterest() {
        balance = balance + (balance * interestRate / 100);
    }

    void display() {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class checkingAccount : public Account {
public:
    float overdraftbalance;

    void withdraw(float amount) {
        if (balance + overdraftbalance >= amount)
            balance = balance - amount;
        else
            cout << "Insufficient funds" << endl;
    }

    void display() {
        Account::display();
        cout << "Overdraft Balance: " << overdraftbalance << endl;
    }
};

int main() {
   
    saveAccount sa;
    cout << "Enter Savings Account Number: ";
    cin >> sa.accountNumber;
    cout << "Enter Initial Balance: ";
    cin >> sa.balance;
    cout << "Enter Interest Rate: ";
    cin >> sa.interestRate;
    
    
    sa.calculateInterest();
    cout << "\nSavings Account Details After Interest Calculation:\n";
    sa.display();

    
    checkingAccount ca;
    cout << "\nEnter Checking Account Number: ";
    cin >> ca.accountNumber;
    cout << "Enter Initial Balance: ";
    cin >> ca.balance;
    cout << "Enter Overdraft Balance: ";
    cin >> ca.overdraftbalance;

    
    float withdrawAmount;
    cout << "\nEnter amount to withdraw from Checking Account: ";
    cin >> withdrawAmount;
    ca.withdraw(withdrawAmount);

    cout << "\nChecking Account Details After Withdrawal:\n";
    ca.display();

    return 0;
}
