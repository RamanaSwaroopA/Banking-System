#include <stdio.h>
#include <string.h>
#include "bank.h"

// Define global variables
struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;  // Number of accounts created

// Function to create a new account
void createAccount() {
    if (accountCount < MAX_ACCOUNTS) {
        struct Account *newAccount = &accounts[accountCount];
        newAccount->accountNumber = accountCount + 1;  // Generate a unique account number
        newAccount->balance = 0.0;
        newAccount->transactionCount = 0;

        printf("Enter account holder name: ");
        fgets(newAccount->holderName, sizeof(newAccount->holderName), stdin);

        // Remove trailing newline character, if present
        size_t len = strlen(newAccount->holderName);
        if (len > 0 && newAccount->holderName[len - 1] == '\n') {
            newAccount->holderName[len - 1] = '\0';
        }

        printf("Account created successfully! Account Number: %d\n", newAccount->accountNumber);
        accountCount++;
    } else {
        printf("Sorry, maximum number of accounts reached!\n");
    }
}


// Function to deposit money into an account
void deposit() {
    int accNum;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum <= accountCount && accNum > 0) {
        struct Account *acc = &accounts[accNum - 1];
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);

        acc->balance += amount;
        printf("Amount deposited successfully. New balance: %.2f\n", acc->balance);

        // Save transaction
        strcpy(acc->transactions[acc->transactionCount].type, "Deposit");
        acc->transactions[acc->transactionCount].amount = amount;
        acc->transactionCount++;
    } else {
        printf("Invalid account number!\n");
    }
}

// Function to withdraw money from an account
void withdraw() {
    int accNum;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum <= accountCount && accNum > 0) {
        struct Account *acc = &accounts[accNum - 1];
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);

        if (amount <= acc->balance) {
            acc->balance -= amount;
            printf("Amount withdrawn successfully. New balance: %.2f\n", acc->balance);

            // Save transaction
            strcpy(acc->transactions[acc->transactionCount].type, "Withdraw");
            acc->transactions[acc->transactionCount].amount = amount;
            acc->transactionCount++;
        } else {
            printf("Insufficient balance!\n");
        }
    } else {
        printf("Invalid account number!\n");
    }
}

// Function to check the balance of an account
void checkBalance() {
    int accNum;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum <= accountCount && accNum > 0) {
        struct Account *acc = &accounts[accNum - 1];
        printf("Account Holder: %s\n", acc->holderName);
        printf("Current Balance: %.2f\n", acc->balance);
    } else {
        printf("Invalid account number!\n");
    }
}
