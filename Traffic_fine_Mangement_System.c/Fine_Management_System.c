#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_VEHICLE_LEN 15
#define MAX_NAME_LEN 50
#define MAX_LOCATION_LEN 100
#define LATE_FEE_PERCENTAGE 20
#define DISMISSAL_DAYS 10
#define GRACE_PERIOD_DAYS 3

struct Fine
{
    int fineID;
    char vehicle[MAX_VEHICLE_LEN];
    char ownerName[MAX_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    int violationType;
    int baseAmount;
    int finalAmount;
    int isPaid;
    int isAppealed;
    int appealstatus;
    char appealReason[200];
    time_t issueTime;
    time_t payTime;
    char issuedBy[MAX_NAME_LEN];
};

struct PaymentHistory
{
    int fineID;
    int amoutn;
    time_t paymentDate;
    char paymentMethod[20];
};

struct Statistics
{
    int totalFines;
    int paidFines;
    int unpaidFines;
    int dismissedFines;
    int appealedFines;
    int PendingRevenue;
};

void issueFine();
void viewFines();
void payFine();
void dashboard();
void searchFine();
void appealFine();
void processAppeals();
void generateReports();
void vehicleHistory();
void exportData();
void modifyFine();
void deleteFine();


int fineIDExists(int id);
int daysBetween(time_t a, time_t b);
int getBaseFine(int type);
const char *getViolationName(int type);
void pause();
void clearScreen();
int  validateVehicle(char *vehicle);
void toUpperCase(char *str);
int getNextFineID();
void savePaymentHistory(int fineID, int amount, const char *method);
void displayStatistics(struct Statistics *stats);
void calculateStatistics(struct Statistics *stats);
int confirmAction(const char *message);
void printHeader(const char *title);
void displayFineDetails(struct Fine *f, time_t now);

int main()
{
    int choice;

    do
    {
        // clearScreen();
        // printHeader("TRAFFIC FINE MANAGEMENT SYSTEM")
        printf("1. Issue New Fine\n");
        printf("2. View All Fines\n");
        printf("3. Search Fine\n");
        printf("4. Pay Fine\n");
        printf("5. Appeal Fine\n");
        printf("6. Process Appeals (Admin Only)\n");
        printf("7. Modify Fine\n");
        printf("8. Delete Fine (Admin Only)\n");
        printf("9. Vehicle History\n");
        printf("10. Admin Dashboard\n");
        printf("11. Generate Reports\n");
        printf("12. Export Data\n");
        printf("13. Exit\n");
        printf("=====================================\n");
        printf("Enter Choice: ");
        
        if (scanf("%d",&choice)!=1)
        {
            while(getchar()!='\n');
            printf("Invalid Input! only Numbers from 1-13 !)\n");
            choice=-1;
        }

        switch (choice)
        {
        case 1:
            issueFine();
            break;
        case 2:
            viewFines();
            break;
        case 3:
            searchFine();
            break;
        case 4:
            payFine();
            break;
        case 5:
            appealFine();
            break;
        case 6:
            processAppeals();
            break;
        case 7:
            modifyFine();
            break;
        case 8:
            deleteFine();
            break;
        case 9:
            vehicleHistory();
            break;
        case 10:
            dashboard();
            break;
        case 11:
            generateReports();
            break;
        case 12:
            exportData();
        case 13:
            printf("\n Exiting System.... Thank you!\n");
            break;
        default:
            printf("\n Invalid Choice! Please try again.\n");
            pause();
        }
    } while (choice!=13);
    
    return 0;
}










