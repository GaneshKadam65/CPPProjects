#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(const string& accNumber, const string& accHolder)
        : accountNumber(accNumber), accountHolder(accHolder), balance(0.0) {}

    // Member functions
    void showAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: " << balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid amount for withdrawal." << endl;
        }
    }
};

int main() {
    string accountNumber, accountHolder;
    int choice;
    double amount;

    cout << "*** Bank Management System ***" << endl;

    cout << "Enter account number: ";
    getline(cin, accountNumber);

    cout << "Enter account holder: ";
    getline(cin, accountHolder);

    BankAccount account(accountNumber, accountHolder);

    do {
        cout << "\n*** MENU ***" << endl;
        cout << "1. Show Account Details" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.showAccountDetails();
                break;
            case 2:
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 3:
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
