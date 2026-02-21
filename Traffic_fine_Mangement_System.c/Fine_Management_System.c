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

void issueFine()
{
    struct Fine f;
    FILE *fp;

    clearScreen();
    printHeader("ISSUE NEW FINE");

    f.fineID=getNextFineID();
    printf("Fine ID: %d",&f.fineID);

    do{
        printf("Vehicle Number: ");
        scanf("%s",&f.vehicle);
        toUpperCase(f.vehicle);

        if(!validateVehicle(f.vehicle))
        {
            printf("Invalid Vehicle Number Format!\n");
        }
    }while(!validateVehicle(f.vehicle));

    printf("Owner Name: ");
    while(getchar()!='\n');
    fgets(f.ownerName,MAX_NAME_LEN,stdin);
    
    printf("Violation Location: ");
    fgets(f.location,MAX_LOCATION_LEN,stdin);

    printf("\n____________________________________\n");
    printf("|          SELECT VIOLATION TYPE    |\n");
    printf("|___________________________________|\n");
    printf("| 1. Signal Jump        (NPR1000)  |\n");
    printf("| 2. Speeding           (NPR1500)  |\n");
    printf("| 3. No Helmet          (NPR500)   |\n");
    printf("| 4. Wrong Parking      (NPR300)   |\n");
    printf("| 5. Drunk Driving      (NPR10000) |\n");
    printf("| 6. No Seatbelt        (NPR1000)  |\n");
    printf("| 7. Triple Riding      (NPR500)   |\n");
    printf("| 8. No License         (NPR5000)  |\n");
    printf("|___________________________________|\n");

    do{
        printf("Enter Choice: ");
        if(scanf("%d",&f.violationType)!=1)
        {
            printf("Invalid Choice! Numbers Only!");
            while (getchar()!='\n');  
            f.violationType=-1;
        }
        if(f.violationType<1 || f.violationType>8)
        {
            printf("Invalid Violation Type!\n");
        }
    }while(f.violationType<1||f.violationType>8);

    printf("Issued By (Officer Name): ");
    while(getchar()!='\n');
    fgets(f.issuedBy, MAX_NAME_LEN, stdin);

    f.baseAmount=getBaseFine(f.violationType);
    f.finalAmount=f.baseAmount;
    f.isPaid=0;
    f.isAppealed=0;
    f.appealstatus=0;
    strcpy(f.appealReason,"");
    f.issueTime=time(NULL);
    f.payTime=0;

    fp=fopen("fines.dat","ab");
    if(!fp){
        printf("Error opening File!\n");
        pause();
    }

    fwrite(&f,sizeof(f),1,fp);
    fclose(fp);

    printf("\n====================================\n");
    printf("      FINE ISSUED SUCCESSFULLY\n");
    printf("====================================\n");
    printf("Fine ID    : %d\n", f.fineID);
    printf("Vehicle    : %s\n", f.vehicle);
    printf("Owner      : %s\n", f.ownerName);
    printf("Location   : %s\n", f.location);
    printf("Violation  : %s\n", getViolationName(f.violationType));
    printf("Amount     : Rs. %d\n", f.baseAmount);
    printf("Issued By  : %s\n", f.issuedBy);
    printf("Date/Time  : %s", ctime(&f.issueTime));
    printf("------------------------------------\n");
    printf("Pay within 3 days to avoid 20%% late fee\n");
    printf("License will be dismissed after 10 days\n");
    
    pause();
}

void viewFines()
{
    FILE *fp=fopen("fines.dat","rb");
    struct Fine f;
    time_t now =time(NULL);
    int count=0;

    clearScreen();
    printHeader("ALL FINES");

    if(!fp)
    {
        printf("No Reocrds found.\n");
        pause();
        return;
    }
    
    printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
    printf("%-5s %-12s %-20s %-15s %-8s %-12s %-5s %-15s\n",
           "ID", "VEHICLE", "OWNER", "VIOLATION", "AMOUNT", "STATUS", "DAYS", "NOTE");
    printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
   
    while(fread(&f, sizeof(f), 1, fp))
    {
        displayFineDetails(&f,now);
        count++;
    }

    fclose(fp);

    if(count==0)
    {
        printf("No Fines Found.\n");
    }
    else
    {
        printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
        printf("Total Fines: %d\n",count);
    }
    pause();
}

void searchFine()
{
    FILE *fp =fopen("fines.dat","rb");
    struct Fine f;
    char searchTerm[MAX_VEHICLE_LEN];
    int searchType;
    int found=0;
    time_t now = time(NULL);

    clearScreen();
    printHeader("SEARCH FINE");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }
    printf("Search By:\n");
    printf("1. Fine ID\n");
    printf("2. Vehicle Number\n");
    printf("3. Owner Name\n");
    printf("Enter Choice: ");
    scanf("%d",&searchType);

    printf("Enter search term: ");
    while(getchar()!='\n');
    fgets(searchTerm,sizeof(searchTerm),stdin);
    toUpperCase(searchTerm);

    printf("\n─────────────────────────────────────────────────────────────────────────────────────────────\n");

    while(fread(&f,sizeof(f),1,fp))
    {
        char tempVehicle[MAX_VEHICLE_LEN], tempName[MAX_NAME_LEN];
        strcpy(tempVehicle,f.vehicle);
        strcpy(tempName,f.ownerName);
        toUpperCase(tempVehicle);
        toUpperCase(tempName);

        int match=0;
        if(searchType==1 && f.fineID==atoi(searchTerm)) match==1;
        else if(searchType==2 && strstr(tempVehicle, searchTerm)) match==1;
        else if(searchType==3 && strstr(tempName, searchTerm)) match==1;

        if(match){
            if(!found){
                printf("%-5s %-12s %-20s %-15s %-8s %-12s %-5s %-15s\n",
                       "ID", "VEHICLE", "OWNER", "VIOLATION", "AMOUNT", "STATUS", "DAYS", "NOTE");
                printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
            }
            displayFineDetails(&f,now);
            found++;
        }
    }

    fclose(fp);

    if(!found)
    {
        printf("No Mathcing fines Found.\n");
    }
    else{
        printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
        printf("Found %d matching fine(s)\n", found);
    }
    pause();
}













