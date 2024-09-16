#ifndef BANK_H
#define BANK_H

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

// Define structure for storing transactions
struct Transaction {
    char type[10];  // "Deposit" or "Withdraw"
    float amount;
};

// Define structure for storing account details
struct Account {
    int accountNumber;
    char holderName[50];
    float balance;
    struct Transaction transactions[MAX_TRANSACTIONS];  // Array to store transaction history
    int transactionCount;
};

// Declare global variables as extern
extern struct Account accounts[MAX_ACCOUNTS];
extern int accountCount;

// Declare function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();

#endif
