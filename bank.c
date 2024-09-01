#include <stdio.h>
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void viewTransactions();
void deleteAccount();
void saveTransaction();

int main()
{
   int choice;
    while(1) {
        printf("\nIndian Banking System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. Check Balance\n");
        printf("5. View Transactions\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
            break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                viewTransactions();
                break;
            case 6:
                deleteAccount();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
