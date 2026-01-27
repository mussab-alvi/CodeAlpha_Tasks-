#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* -------------------------------
   Transaction Class
   ------------------------------- */
class Transaction {
    int transactionID;
    string type;
    double amount;

public:
    Transaction(int id, string t, double a)
        : transactionID(id), type(t), amount(a) {}

    void displayTransaction() {
        cout << "Transaction ID: " << transactionID
             << " | Type: " << type
             << " | Amount: " << amount << endl;
    }
};

/* -------------------------------
   Account Class
   ------------------------------- */
class Account {
    int accountNumber;
    double balance;
    int customerID;
    vector<Transaction> transactions;
    int transactionCounter = 0;

public:
    Account(int accNo, int custID)
        : accountNumber(accNo), customerID(custID), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction(++transactionCounter, "Deposit", amount));
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction(++transactionCounter, "Withdraw", amount));
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Error: Insufficient balance!\n";
        }
    }

    void transfer(Account & toAccount, double amount) {
        if (amount <= balance) {
            balance -= amount;
            toAccount.balance += amount;

            transactions.push_back(Transaction(++transactionCounter, "Transfer Out", amount));
            toAccount.transactions.push_back(Transaction(++toAccount.transactionCounter, "Transfer In", amount));

            cout << "Transferred: " << amount << " to Account " << toAccount.accountNumber << endl;
        } else {
            cout << "Error: Insufficient balance!\n";
        }
    }

    void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber
             << " | Balance: " << balance << endl;
        cout << "Recent Transactions:\n";
        for (auto &t : transactions) {
            t.displayTransaction();
        }
    }

    int getAccountNumber() { return accountNumber; }
    int getCustomerID() { return customerID; }
};

/* -------------------------------
   Customer Class
   ------------------------------- */
class Customer {
    int customerID;
    string name;
    string email;

public:
    Customer(int id, string n, string e)
        : customerID(id), name(n), email(e) {}

    void displayCustomerInfo() {
        cout << "\nCustomer ID: " << customerID
             << " | Name: " << name
             << " | Email: " << email << endl;
    }

    int getCustomerID() { return customerID; }
};

/* -------------------------------
   Main Function with Menu
   ------------------------------- */
int main() {
    vector<Customer> customers;
    vector<Account> accounts;
    int option;
    int customerCounter = 0;
    int accountCounter = 1000; // starting account number

    do {
        cout << "\n----------------- Banking Menu ------------------\n";
        cout << "1. Register Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer Funds\n";
        cout << "6. View Account Info\n";
        cout << "7. Exit\n";
        cout << "-------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1: {
                string name, email;
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter customer email: ";
                cin >> email;
                customers.push_back(Customer(++customerCounter, name, email));
                cout << "Customer Registered Successfully!\n";
                break;
            }
            case 2: {
                int custID;
                cout << "Enter customer ID to create account: ";
                cin >> custID;
                bool found = false;
                for (auto &c : customers) {
                    if (c.getCustomerID() == custID) {
                        accounts.push_back(Account(++accountCounter, custID));
                        cout << "Account Created Successfully! Account Number: " << accountCounter << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Error: Customer ID not found!\n";
                break;
            }
            case 3: {
                int accNo;
                double amount;
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bool found = false;
                for (auto &a : accounts) {
                    if (a.getAccountNumber() == accNo) {
                        a.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Error: Account not found!\n";
                break;
            }
            case 4: {
                int accNo;
                double amount;
                cout << "Enter account number: ";
                cin >> accNo;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bool found = false;
                for (auto &a : accounts) {
                    if (a.getAccountNumber() == accNo) {
                        a.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Error: Account not found!\n";
                break;
            }
            case 5: {
                int fromAcc, toAcc;
                double amount;
                cout << "Enter source account number: ";
                cin >> fromAcc;
                cout << "Enter destination account number: ";
                cin >> toAcc;
                cout << "Enter transfer amount: ";
                cin >> amount;

                Account *src = nullptr, *dest = nullptr;
                for (auto &a : accounts) {
                    if (a.getAccountNumber() == fromAcc) src = &a;
                    if (a.getAccountNumber() == toAcc) dest = &a;
                }

                if (src && dest) {
                    src->transfer(*dest, amount);
                } else {
                    cout << "Error: One or both accounts not found!\n";
                }
                break;
            }
            case 6: {
                int accNo;
                cout << "Enter account number: ";
                cin >> accNo;
                bool found = false;
                for (auto &a : accounts) {
                    if (a.getAccountNumber() == accNo) {
                        a.displayAccountInfo();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Error: Account not found!\n";
                break;
            }
            case 7:
                cout << "Exiting Banking System...............!!!\n";
                break;
            default:
                cout << "Invalid choice, kindly try again.\n";
        }
    } while(option != 7);

    return 0;
}
