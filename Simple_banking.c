#include <stdio.h>
#include <string.h>
#include <time.h>

struct Card
{
    char Name[20];
    long long card_number;
    int pin;
};

void Receipt(int option, int withdrawal, int Balance, char Name[10], int limit)
{
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    switch (option)
    {
    case 1:
        printf("\n  =============================\n");
        printf(" |     Withdrawal Receipt     |\n");
        printf(" |============================|\n");
        printf(" | Name: %-20s |\n", Name);
        printf(" |                            |\n");
        printf(" | Withdrawn Amount: %-8d |\n", withdrawal);
        printf(" |                            |\n");
        printf(" | Limit Remaining: %-9d |\n", limit);
        printf(" |                            |\n");
        printf(" | Remaining Balance: %-7d |\n", Balance);
        printf(" |============================|\n");

        /* Date & Time */
        printf(" | Date: %02d-%02d-%04d           |\n",
               tm_info->tm_mday,
               tm_info->tm_mon + 1,
               tm_info->tm_year + 1900);

        printf(" | Time: %02d:%02d:%02d             |\n",
               tm_info->tm_hour,
               tm_info->tm_min,
               tm_info->tm_sec);

        printf(" |============================|\n");
        printf(" |   Thank You For Using ATM  |\n");
        printf(" =============================\n");
        break;
    }
}



int main()
{
    int language, pin;
    int count = 3;

    struct Card c1 = {
        "Prashant", 123456789, 1234
    };

    int Balance = 10000;
    int limit = 5000;

    printf("1.Nepali\n2.English\n");
    printf("Select the language (1/2): ");
    scanf("%d", &language);

    if(language == 1)
        printf("Nepali Language Selected.\n");
    else if(language == 2)
        printf("English Language Selected.\n");
    else
    {
        printf("Invalid Input.\n");
        return 0;
    }

    
    while(count > 0)
    {
        printf("\nEnter PIN Number: ");
        scanf("%d", &pin);

        if(pin != c1.pin)
        {
            count--;
            printf("Invalid PIN\n");
            printf("Attempts Remaining: %d\n", count);

            if(count == 0)
            {
                printf("Card Blocked.\n");
                return 0;
            }
        }
        else
        {
            printf("PIN Verified.\n");
            break;
        }
    }

    
    while(1)
    {
        int option, Withdrawal;
        char Name[10];

        printf("\n------- Main Menu -------\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Interbank Transfer\n");
        printf("4. Exit\n");
        printf("Select Option (1/2/3/4): ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Current Balance: %d\n", Balance);
                break;

            case 2:
                printf("Name: ");
                scanf("%s",&Name);
                printf("\nEnter Withdrawal Amount: ");
                scanf("%d", &Withdrawal);

                if(Withdrawal > limit)
                {
                    printf("Cann't withdraw more than daily limit (%d).\n", limit);
                }
                else if(Withdrawal > Balance)
                {
                    printf("Insufficient Balance.\n");
                }
                else
                {
                    Balance -= Withdrawal;
                    limit -= Withdrawal;
                    printf("Withdrawal Successful.\n");
                    printf("Withdrawn Amount: %d\n", Withdrawal);
                    printf("Remaining Balance: %d\n", Balance);
                    int option2;
                    printf("Want Receipt?\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("Enter choice (1/2): ");
                    scanf("%d", &option2);
                    Receipt(option2,Withdrawal,Balance,Name,limit);
                }
                break;

            case 3:
            {
                int transferAmount;
                long int targetAccount;

                printf("Enter Target Account Number: ");
                scanf("%ld", &targetAccount);

                printf("Enter Transfer Amount: ");
                scanf("%d", &transferAmount);

                if(transferAmount > Balance)
                {
                    printf("Insufficient Balance for transfer.\n");
                }
                else
                {
                    Balance -= transferAmount;
                    printf("Transfer Successful.\n");
                    printf("Transferred Amount: %d\n", transferAmount);
                    printf("Remaining Balance: %d\n", Balance);
                }
                break;
            }

            case 4:
                printf("Thank you for using ATM.\n");
                return 0;

            default:
                printf("Invalid Option. Try again.\n");
        }
    }
}
