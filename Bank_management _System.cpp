#include <iostream>
#include <cstdlib> // For system("pause")

using namespace std;

// Function prototypes
void displayMenu();
void createAccount(string[], string[], double[], int&);
int findAccountIndex(const string[], const string&, int);
void deposit(string[], double[], const string&, int);
void withdraw(string[], double[], const string&, int);
void checkBalance(const string[], const double[], const string&, int);

int main() {
    const int MAX_ACCOUNTS = 100;
    string accountNumbers[MAX_ACCOUNTS];
    string accountHolders[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS];
    int numAccounts = 0;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accountNumbers, accountHolders, balances, numAccounts);
                break;
            case 2: {
                string accNumber;
                cout << "Enter account number: ";
                cin >> accNumber;
                deposit(accountNumbers, balances, accNumber, numAccounts);
                break;
            }
            case 3: {
                string accNumber;
                cout << "Enter account number: ";
                cin >> accNumber;
                withdraw(accountNumbers, balances, accNumber, numAccounts);
                break;
            }
            case 4: {
                string accNumber;
                cout << "Enter account number: ";
                cin >> accNumber;
                checkBalance(accountNumbers, balances, accNumber, numAccounts);
                break;
            }
            case 5:
                cout << "Exiting the Bank Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        // Clear screen
        system("pause");
        system("cls");

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nBank Management System Menu:\n";
    cout << "1. Create a new account\n";
    cout << "2. Deposit money\n";
    cout << "3. Withdraw money\n";
    cout << "4. Check balance\n";
    cout << "5. Exit\n";
}

void createAccount(string accountNumbers[], string accountHolders[], double balances[], int& numAccounts) {
    if (numAccounts < 100) {
        cout << "Enter account number: ";
        cin >> accountNumbers[numAccounts];

        // Check if the account number already exists
        if (findAccountIndex(accountNumbers, accountNumbers[numAccounts], numAccounts) != -1) {
            cout << "Account with this number already exists.\n";
            return;
        }

        cout << "Enter account holder name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, accountHolders[numAccounts]);

        cout << "Enter initial balance: ";
        cin >> balances[numAccounts];

        cout << "Account created successfully.\n";
        numAccounts++;
    } else {
        cout << "Cannot create more accounts. Maximum limit reached.\n";
    }
}

int findAccountIndex(const string accountNumbers[], const string& accNumber, int numAccounts) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accountNumbers[i] == accNumber) {
            return i;
        }
    }
    return -1; // Account not found
}

void deposit(string accountNumbers[], double balances[], const string& accNumber, int numAccounts) {
    int index = findAccountIndex(accountNumbers, accNumber, numAccounts);
    if (index != -1) {
        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;
        balances[index] += amount;
        cout << "Deposit successful.\n";
    } else {
        cout << "Account not found.\n";
    }
}

void withdraw(string accountNumbers[], double balances[], const string& accNumber, int numAccounts) {
    int index = findAccountIndex(accountNumbers, accNumber, numAccounts);
    if (index != -1) {
        double amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;
        if (amount <= balances[index]) {
            balances[index] -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Insufficient funds.\n";
        }
    } else {
        cout << "Account not found.\n";
    }
}

void checkBalance(const string accountNumbers[], const double balances[], const string& accNumber, int numAccounts) {
    int index = findAccountIndex(accountNumbers, accNumber, numAccounts);
    if (index != -1) {
        cout << "Balance: $" << balances[index] << endl;
    } else {
        cout << "Account not found.\n";
    }
}
