#include <stdio.h>

#define MAX 50

struct Account
{
    int accountNumber;
    char name[50];
    char phone[15];
    float balance;
};

struct Account accounts[MAX];

int count = 0;
int nextAccountNumber = 1001;

int findAccount(int accountNumber)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
            return i;
    }

    return -1;
}

void createAccount()
{
    float amount;

    if (count >= MAX)
    {
        printf("\nMaximum account limit reached.\n");
        return;
    }

    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", accounts[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", accounts[count].phone);

    printf("Enter Initial Deposit: ");
    scanf("%f", &amount);

    if (amount < 0)
    {
        printf("\nInvalid amount.\n");
        return;
    }

    accounts[count].accountNumber = nextAccountNumber++;
    accounts[count].balance = amount;

    printf("\nAccount created successfully!\n");
    printf("Account Number: %d\n",
           accounts[count].accountNumber);

    count++;
}

void deposit()
{
    int accountNumber;
    int index;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nInvalid amount.\n");
        return;
    }

    accounts[index].balance += amount;

    printf("\nDeposit successful.\n");
    printf("Current Balance: Rs. %.2f\n",
           accounts[index].balance);
}

void withdraw()
{
    int accountNumber;
    int index;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nInvalid amount.\n");
        return;
    }

    if (amount > accounts[index].balance)
    {
        printf("\nInsufficient balance.\n");
        return;
    }

    accounts[index].balance -= amount;

    printf("\nWithdrawal successful.\n");
    printf("Current Balance: Rs. %.2f\n",
           accounts[index].balance);
}

void checkBalance()
{
    int accountNumber;
    int index;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
        return;
    }

    printf("\nAccount Number : %d\n",
           accounts[index].accountNumber);

    printf("Customer Name  : %s\n",
           accounts[index].name);

    printf("Balance        : Rs. %.2f\n",
           accounts[index].balance);
}

void displayAccount()
{
    int accountNumber;
    int index;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    index = findAccount(accountNumber);

    if (index == -1)
    {
        printf("\nAccount not found.\n");
        return;
    }

    printf("\n========== ACCOUNT DETAILS ==========\n");

    printf("Account Number : %d\n",
           accounts[index].accountNumber);

    printf("Customer Name  : %s\n",
           accounts[index].name);

    printf("Phone Number   : %s\n",
           accounts[index].phone);

    printf("Balance        : Rs. %.2f\n",
           accounts[index].balance);

    printf("=====================================\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== MINI BANKING MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
                displayAccount();
                break;

            case 6:
                printf("\nThank you for using the system.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}


--OUTPUT
===== MINI BANKING MANAGEMENT SYSTEM =====
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Display Account Details
6. Exit

Enter your choice: 1

Enter Customer Name: Priya
Enter Phone Number: 9876543210
Enter Initial Deposit: 5000

Account created successfully!
Account Number: 1001

Enter your choice: 2

Enter Account Number: 1001
Enter Deposit Amount: 2000

Deposit successful.
Current Balance: Rs. 7000.00

Enter your choice: 3

Enter Account Number: 1001
Enter Withdrawal Amount: 1500

Withdrawal successful.
Current Balance: Rs. 5500.00
