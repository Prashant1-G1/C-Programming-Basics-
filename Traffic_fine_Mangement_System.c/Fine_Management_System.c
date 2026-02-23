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
    int totalRevenue;
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
        clearScreen();
        printHeader("TRAFFIC FINE MANAGEMENT SYSTEM");
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
    printf("Fine ID: %d\n",f.fineID);

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
    printf("| 1. Signal Jump        (NPR1000)   |\n");
    printf("| 2. Speeding           (NPR1500)   |\n");
    printf("| 3. No Helmet          (NPR500)    |\n");
    printf("| 4. Wrong Parking      (NPR300)    |\n");
    printf("| 5. Drunk Driving      (NPR10000)  |\n");
    printf("| 6. No Seatbelt        (NPR1000)   |\n");
    printf("| 7. Triple Riding      (NPR500)    |\n");
    printf("| 8. No License         (NPR5000)   |\n");
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
    
    if(!fp)
    {
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
    printf("Owner      : %s", f.ownerName);
    printf("Location   : %s", f.location);
    printf("Violation  : %s\n", getViolationName(f.violationType));
    printf("Amount     : Rs. %d\n", f.baseAmount);
    printf("Issued By  : %s", f.issuedBy);
    printf("Date/Time  : %s", ctime(&f.issueTime));
    printf("----------------------------------------\n");
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
        printf("No Records found.\n");
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

void payFine()
{
    FILE *fp=fopen("fines.dat","rb+");
    struct Fine f;
    int id;
    char paymentMethod[20];
    time_t now=time(NULL);
    int found=0;

    clearScreen();
    printHeader("PAY FINE");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("Enter Fine ID to Pay: ");
    scanf("%d",&id);

    while(fread(&f,sizeof(f), 1,fp))
    {
        if(f.fineID==id)
        {
            found=1;

            if(f.isPaid)
            {
                printf("\nThis Fine has Already been Paid Off %s",ctime(&f.payTime));
                fclose(fp);
                pause();
                return;
            }

            if(f.isAppealed && f.appealstatus==1)
            {
                printf("\nAppeal Approved - Fine Waived!!\n");
                fclose(fp);
                pause();
                return;
            }

            int days=daysBetween(f.issueTime,now);

            if(days> DISMISSAL_DAYS)
            {
                printf("License Dismissed. Payment not Allowed!\n");
                printf("Please Contact The Traffic Department.\n");
                fclose(fp);
                pause();
                return;
            }

            if (days> GRACE_PERIOD_DAYS)
            {
                int lateFee=(f.baseAmount*LATE_FEE_PERCENTAGE)/100;
                f.finalAmount=f.baseAmount+lateFee;
                printf("Late Payment! Additional 20%% Late Fee Applied.\n");
            }
            else{
                f.finalAmount=f.baseAmount;
            }

            printf("\n____________________________________\n");
            printf("Fine ID         : %d\n",f.fineID);
            printf("Vehicle         : %s\n",f.vehicle);
            printf("Owner           : %s",f.ownerName);
            printf("Violation       : %s", getViolationName(f.violationType));
            printf("Base Amount     : NPR%d\n",f.baseAmount);
            if(days> GRACE_PERIOD_DAYS)
            {
                printf("Late Fee         :NPR %d",f.finalAmount-f.baseAmount);
            }
            printf("_____________________________________\n");
            printf("TOTAL AMOUNT    : %D\n",f.finalAmount);
            printf("_____________________________________\n");

            if (!confirmAction("Proceed With Payment?"))
            {
                fclose(fp);
                pause();
                return;
            }

            printf("\nPayement Method:\n");
            printf("1. Cash\n");
            printf("2. Card\n");
            printf("3. Nagarik App\n");
            printf("4. Net Banking\n");
            printf("Enter Choice: ");
            int method;
            scanf("%d",&method);

            switch (method)
            {
            case 1:
                strcpy(paymentMethod, "Cash");
                break;
            case 2: 
                strcpy(paymentMethod, "Card");
                break;
            case 3:
                strcpy(paymentMethod, "Nagarik App");
                break;
            case 4:
                strcpy(paymentMethod, "Net Banking");
                break;
            default:
                strcpy(paymentMethod,"Cash");
            }

            f.isPaid=1;
            f.payTime=now;

            fseek(fp,-(long)sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1 ,fp);
            fclose(fp);

            savePaymentHistory(f.fineID, f.finalAmount, paymentMethod);

            printf("\n====================================\n");
            printf("        PAYMENT SUCCESSFUL\n");
            printf("====================================\n");
            printf("Receipt No    : %d\n", f.fineID);
            printf("Amount Paid   : NPR %d\n", f.finalAmount);
            printf("Payment Method: %s\n", paymentMethod);
            printf("Date/Time     : %s", ctime(&f.payTime));
            printf("------------------------------------\n");
            printf("Thank you for your payment!\n");

            pause();
            return;
        }
    }

    fclose(fp);

    if(!found)
    {
        printf("\n Fine ID not Found.\n");
    }

    pause();
}

void appealFine()
{
    FILE *fp=fopen("fines.dat","rb+");
    struct Fine f;
    int id;
    time_t now=time(NULL);
    int found=0;

    clearScreen();
    printHeader("APPEAL FINE");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("Enter Fine ID to Appeal: ");
    scanf("%d",&id);

    while(fread(&f,sizeof(f),1,fp))
    {
        if(f.fineID==id)
        {
            found=1;

            if(f.isPaid)
            {
                printf("Fine is Alraedy Paid. Can't Appeal Paid Fined.\n");
                fclose(fp);
                pause();
                return;
            }

            if(f.isAppealed)
            {
                printf("\n Appeal Already Submitted for this Fine.\n");
                if(f.appealstatus==0)
                {
                    printf("Status: Pending\n");
                }
                else if(f.appealstatus==1)
                {
                    printf("Status: Approved\n");
                }
                else printf("Status: Rejected\n");
                fclose(fp);
                pause();
                return;
            }

            printf("\n-------------------------------------\n");
            printf("Fine ID    : %d\n", f.fineID);
            printf("Vehicle    : %s\n", f.vehicle);
            printf("Violation  : %s\n", getViolationName(f.violationType));
            printf("Amount     : NPR %d\n", f.baseAmount);
            printf("-------------------------------------\n");

            printf("\nEnter Reason for Appeal (Max 200 Charaters):\n");
            f.appealReason[strcspn(f.appealReason,"\n")] = 0;

            if(strlen(f.appealReason)<10)
            {
                printf("\nAppeal Reason too Short. Minimum 10 Characters Required\n");
            }

            f.isAppealed=1;
            f.appealstatus=0;

            fseek(fp, -(long)sizeof(f), SEEK_CUR);
            fwrite(&f,sizeof(f),1, fp);
            fclose(fp);

            printf("\n   Appeal Submitted Successfully.  \n");
            printf("Your Appeal is Pending Review by the Admin.\n");

            pause();
            return;
        }
    }

    fclose(fp);

    if(!found)
    {
        printf("\n Fine ID Not Found.\n");
    }

    pause();
}

void processAppeals()
{
    FILE *fp=fopen("fines.dat","rb+");
    struct Fine f;

    int count=0;
    int choice, id;

    clearScreen();
    printHeader("PROCESS APPEALS (ADMIN)");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("Pending Appeals:\n");
    printf("-------------------------------------------------------------------------\n");

    while(fread(&f, sizeof(f), 1, fp))
    {
        if(f.isAppealed && f.appealstatus ==0)
        {
            printf("\nFine ID     : %d\n",f.fineID);
            printf("Vehicle     : %s\n",f.vehicle);
            printf("Owner       : %s",f.ownerName);
            printf("Violation   : %s\n", getViolationName(f.violationType));
            printf("Amount      : NPR%d\n",f.finalAmount);
            printf("Reason      : %s\n",f.appealReason);
            printf("-------------------------------------------------------------------------\n");
            count++;
        }
    }

    if(count==0)
    {
        printf("NO Pending Appeals.\n");
        fclose(fp);
        pause();
        return;
    }

    printf("\nTotal Pending Appeals: %d",count);
    printf("\nEnter Fine ID to Process (0 to Cancel): ");
    scanf("%d",&id);

    if(id==0)
    {
        fclose(fp);
        return;
    }

    rewind(fp);

    while(fread(&f, sizeof(f), 1, fp)) 
    {
        if (f.fineID == id && f.isAppealed && f.appealstatus == 0) {
            printf("\nAppeal Decision:\n");
            printf("1. Approve (Waive fine)\n");
            printf("2. Reject\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                f.appealstatus = 1; 
                printf("\n Appeal approved. Fine waived.\n");
            } else if (choice == 2) {
                f.appealstatus = 2; 
                printf("\n Appeal rejected.\n");
            } else {
                printf("\n Invalid choice.\n");
                fclose(fp);
                pause();
                return;
            }

            fseek(fp, -(long)sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            fclose(fp);

            pause();
            return;
        }
    }

    fclose(fp);
    printf("\n Fine ID not found or not pending.\n");
    pause();
}

void dashboard()
{
    struct Statistics stats={0};

    clearScreen();
    printHeader("ADMIN DASHBOARD");

    calculateStatistics(&stats);
    displayStatistics(&stats);

    pause();
}

void generateReports()
{
    FILE *fp=fopen("fines.dat","rb");
    FILE *report;
    struct Fine f;
    time_t now=time(NULL);
    char filename[50];
    int reportType;

    clearScreen();
    printHeader("GENERATE REPORTS");
    
    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("Select Report Type:\n");
    printf("1. All Fines Report\n");
    printf("2. Unpaid Fines Report\n");
    printf("3. Revenue Report\n");
    printf("4. Daily Report\n");
    printf("Enter Choice: ");
    scanf("%d",&reportType);

    sprintf(filename,"report_%ld.txt",(long)now);
    report=fopen(filename,"w");

    if(!report)
    {
        printf("Error Creating Report File!\n");
        fclose(fp);
        pause();
        return;
    }

    fprintf(report,"-------------------------------------------------------\n");
    fprintf(report,"          TRAFFIC FINE MANAGEMENT SYSTEM- REPORT\n");
    fprintf(report,"-------------------------------------------------------\n");
    fprintf(report,"Generated on: %s",ctime(&now));
    fprintf(report,"-------------------------------------------------------\n");

    int count=0;
    int totalAmount=0;

    while(fread(&f,sizeof(f),1,fp))
    {
        int include=0;
        int days=daysBetween(f.issueTime,now);

        if(reportType==1)include=1;
        else if(reportType==2 && !f.isPaid && days <=DISMISSAL_DAYS) include=1;
        else if(reportType==3 && f.isPaid ) include=1;
        else if(reportType ==4 && daysBetween(f.issueTime, now)==0) include=1;

        if(include)
        {
            fprintf(report,"Fine ID    : %d\n",f.fineID);
            fprintf(report,"Vehicle    : %s\n",f.vehicle);
            fprintf(report,"Owner      : %s",f.ownerName);
            fprintf(report,"Violation  : %s\n",getViolationName(f.violationType));
            fprintf(report,"Amount     : NPR%d\n",f.finalAmount);
            fprintf(report,"Status     : %s\n",f.isPaid?"PAID":"UNPAID");
            fprintf(report,"Issue Date : %s",ctime(&f.issueTime));
            if(f.isPaid)
            {
                fprintf(report,"Pay Date            : %s",ctime(&f.payTime));        
            }
            fprintf(report,"-------------------------------------------------\n");
            count++;
            if(f.isPaid)
            {
                totalAmount+=f.finalAmount;
            }
        }
    }
        fprintf(report,"\nTotal Records: %d",count);
        if(reportType==3)
        {
            fprintf(report,"Total Revenue: NPR%d\n",totalAmount);
        }

        fclose(fp);
        fclose(report);

        printf("\n Report Generated Successfully.\n");
        printf("File Name: %s\n",filename);
        printf("Total Records: %d\n",count);

        pause();
}

void vehicleHistory()
{
    FILE *fp=fopen("fines.dat","rb");
    struct Fine f;
    char vehicle[MAX_VEHICLE_LEN];
    int found=0;
    int totalFines=0, paidFines=0, totalAmount=0;
    time_t now=time(NULL);

    clearScreen();
    printHeader("VEHICLE HISTORY");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("Enter Vehicle Number: ");
    scanf("%s",&vehicle);
    toUpperCase(vehicle);

    printf("\n----------------------------------------------------------\n");
    printf("Vehicle: %s\n",vehicle);
    printf("\n----------------------------------------------------------\n");

    while(fread(&f,sizeof(f),1,fp))
    {
        char tempVehicle[MAX_VEHICLE_LEN];
        strcpy(tempVehicle,f.vehicle);
        toUpperCase(tempVehicle);

        if(strcmp(tempVehicle,vehicle)==0);
        {
            if(!found)
            {
                printf("Owner: %s\n\n",f.ownerName);
                printf("Violation History:\n");
                printf("----------------------------------------------------------\n");
            }

            printf("Fine ID        : %d\n",f.fineID);
            printf("Violation      : %s\n",getViolationName(f.violationType));
            printf("Amount         : %s\n",f.finalAmount);
            printf("Status         : %s\n",f.isPaid?"PAID":"UNPAID");
            printf("Date           : %s\n",f.issueTime);
            printf("Location       : %s",f.location);
            printf("----------------------------------------------------------\n");

            found=1;
            totalFines++;
            if(f.isPaid)
            {
                paidFines++;
                totalAmount+=f.finalAmount;
            }
        }
    }

    fclose(fp);

    if(!found)
    {
        printf("No Fines Found for this vehicle.\n");
    }
    else
    {
        printf("\nSummary:\n");
        printf("Total Fines   : %d\n",totalFines);
        printf("Paid Fines    : %d\n",paidFines);
        printf("Unpaid Fines  : %d\n",totalFines-paidFines);
        printf("Total Paid    : NPR%d\n",totalAmount);
    }

    pause();
}

void modifyFine()
{
    FILE *fp=fopen("fines.dat","rb+");
    struct Fine f;

    int id , found=0;

    clearScreen();
    printHeader("MODIFY FINE (ADMIN)");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("Enter the Fine ID: ");
    scanf("%d",&id);

    while(fread(&f,sizeof(f),1,fp))
    {
        if(id==f.fineID)
        {
            found=1;

            printf("\nCurrent Details.\n");
            printf("-------------------------------------\n");
            printf("Vehicle    : %s\n",f.vehicle);
            printf("Owner      : %s",f.ownerName);
            printf("Violation  : %s",getViolationName(f.violationType));
            printf("Amount     : NPR%d",f.finalAmount);
            printf("Status     : %s",f.isPaid?"PAID":"UNPAID");
            printf("-------------------------------------\n");

            if(f.isPaid)
            {
                printf("\nCannot Modify a Paid Fie.\n");
                fclose(fp);
                pause();
                return;
            }

            if(!confirmAction("Modify this Fine"))
            {
                fclose(fp);
                return;
            }

            printf("\nModify:\n");
            printf("1. Vioaltion Type\n");
            printf("2. Amount\n");
            printf("3. Both\n");
            printf("Enter Choice: ");
            int choice;
            scanf("%d",&choice);

            if(choice == 1 || choice == 3)
            {
                printf("\nSelect New Violation Type:\n");
                printf("1. Signal Jump (NPR1000)\n");
                printf("2. Speeding (NPR1500)\n");
                printf("3. No Helmet (NPR500)\n");
                printf("4. Wrong Parking (NPR300)\n");
                printf("5. Drunk Driving (NPR10000)\n");
                printf("6. No Seatbelt (NPR1000)\n");
                printf("7. Triple Riding (NPR500)\n");
                printf("8. No License (NPR5000)\n");
                printf("Enter Choice: ");
                scanf("%d",&f.violationType);
                f.baseAmount=getBaseFine(f.violationType);
                f.finalAmount=f.baseAmount;
            }

            if(choice==2)
            {
                printf("Enter New Amoutn: ");
                scanf("%d",&f.baseAmount);
                f.finalAmount=f.baseAmount;
            }

            fseek(fp,-(long)sizeof(f),SEEK_CUR);
            fwrite(&f,sizeof(f),1,fp);
            fclose(fp);

            printf("\nFine Modified Successfully.\n");
            pause();
            return;
        }
    }
    fclose(fp);

    if(!found)
    {
        printf("\nFine ID Not Found.\n");
    }

    pause();
}

void deleteFine()
{
    FILE *fp=fopen("fines.dat","rb");
    FILE *temp=fopen("temp.dat","wb");
    struct Fine f;

    int id, found=0;

    clearScreen();
    printHeader("DELETE FINE (ADMIN)");

    if(!fp)
    {
        printf("No Records Found.\n");
        pause();
        return;
    }

    printf("WARNIGN: This action cannot be undone!\n\n");
    printf("Enter Fine ID to Delete: ");
    scanf("%d",&id);

    while(fread(&f,sizeof(f),1,fp))
    {
        if(f.fineID==id)
        {
            found=1;

            printf("\nFine Details:\n");
            printf("--------------------------------------\n");
            printf("Fine ID     : %d\n",f.fineID);
            printf("Vehicle     : %s\n",f.vehicle);
            printf("Owner       : %s",f.ownerName);
            printf("Violation   : %s",getViolationName(f.violationType));
            printf("Amount      : NPR%d",f.finalAmount);
            printf("--------------------------------------\n");

            if(!confirmAction("Delete this Fine Permanently?"))
            {
                fwrite(&f,sizeof(f),1,temp);
            }
            else{
                printf("\nFine Deleted Successfully!\n");
            }

        }else{
            fwrite(&f,sizeof(f),1,temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("fines.dat");
    rename("temp.dat","fines.dat");

    if(!found)
    {
        printf("\nFine ID not Found.\n");
    }

    pause();
}

void exportData() 
{
    FILE *fp = fopen("fines.dat", "rb");
    FILE *csv;
    struct Fine f;
    time_t now = time(NULL);
    char filename[50];

    clearScreen();
    printHeader("EXPORT DATA");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    sprintf(filename, "fines_export_%ld.csv", (long)now);
    csv = fopen(filename, "w");

    if (!csv) 
    {
        printf("Error creating export file!\n");
        fclose(fp);
        pause();
        return;
    }

    fprintf(csv, "Fine ID,Vehicle,Owner,Location,Violation,Base Amount,Final Amount,Status,Issue Date,Pay Date,Issued By\n");

    int count = 0;
    while (fread(&f, sizeof(f), 1, fp)) 
    {
        fprintf(csv, "%d,%s,%s,%s,%s,%d,%d,%s,%s,%s,%s\n",
                f.fineID,
                f.vehicle,
                f.ownerName,
                f.location,
                getViolationName(f.violationType),
                f.baseAmount,
                f.finalAmount,
                f.isPaid ? "PAID" : "UNPAID",
                ctime(&f.issueTime),
                f.isPaid ? ctime(&f.payTime) : "N/A",
                f.issuedBy);
        count++;
    }

    fclose(fp);
    fclose(csv);

    printf("Data exported successfully!\n");
    printf("Filename: %s\n", filename);
    printf("Total records: %d\n", count);

    pause();
}

int fineIDExists(int id)
{
    FILE *fp=fopen("fines.dat","rb");
    struct Fine f;

    if(!fp)
    {
        return 0;
    }

    while(fread(&f,sizeof(f),1,fp))
    {
        if(f.fineID==id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int getNextFineID()
{
    FILE *fp =fopen("fines.dat","rb");
    struct Fine f;

    int maxID=1000;

    if(!fp) 
    {
        return maxID;
    }

    while(fread(&f,sizeof(f),1,fp))
    {
        if(f.fineID>=maxID)
        {
            maxID=f.fineID+1;
        }
    }

    fclose(fp);
    return maxID;
}

int daysBetween(time_t a, time_t b)
{
    return(int)(difftime(b,a)/(60*60*25));
}

int getBaseFine(int type)
{
    switch (type)
    {
    case 1:
        return 1000;
    case 2:
        return 1500;
    case 3:
        return 500;
    case 4:
        return 300;
    case 5:
        return 10000;
    case 6:
        return 1000;
    case 7:
        return 500;
    case 8:
        return 5000;
    default:
        return 300;
    }
}

const char* getViolationName(int type)
{
    switch (type)
    {
    case 1:
        return "Signal Jump";
    case 2:
        return "Speeding";
    case 3:
        return "No Helmet";
    case 4:
        return "Wrong Parking";
    case 5:
        return "Drunk Driving";
    case 6:
        return "No Seatbelt";
    case 7:
        return "Triple Riding";
    case 8:
        return "No License";
    default:
        return "Unkown";
    }
}

int validateVehicle(char *vehicle)
{
    int len=strlen(vehicle);
    if(len<4||len>14) return 0;

    return  1;
}

void toUpperCase(char *str)
{
    for(int i=0; str[i]; i++)
    {
        str[i]=toupper(str[i]);
    }
}

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause()
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

int confirmAction(const char *message)
{
    char response;
    printf("\n%s(y/n)",message);
    scanf("%c",&response);
    return (response == 'y' || response == 'Y');
}

void printHeader(const char *title)
{
    printf("\n==================================================\n");
    printf("                %s\n",title);
    printf("===================================================\n");
}

void displayFineDetails(struct Fine *f, time_t now)
{
    int days=daysBetween((*f).issueTime,now);
    char status[15]="UNPAID";
    char note[25]="-";
    int displayAmount=(*f).finalAmount;

    if(!(*f).isPaid)
    {
        if((*f).isAppealed)
        {
            if((*f).appealstatus==0) strcpy(status,"APPEALED");
            else if ((*f).appealstatus==1) strcpy(status,"WAIVED");
            else strcpy(status,"REJECTED");
        }
        else if(days>DISMISSAL_DAYS)
        {
            strcpy(status,"DIMISSED");
            strcpy(status,"LICENSE HOLD");
        }
        else if(days>GRACE_PERIOD_DAYS)
        {
            displayAmount=(*f).baseAmount+((*f).baseAmount*LATE_FEE_PERCENTAGE/100);
            strcpy(note, "+20%% LATE");
        }
    }
    else{
        strcpy(status,"PAID");
        strcpy(note,"GOOD");
    }

    printf("%-5d %-12s %-20.20s %-15s NPR%-7d %-12s %-5d %-15s\n",
           f->fineID,
           f->vehicle,
           f->ownerName,
           getViolationName(f->violationType),
           displayAmount,
           status,
           days,
           note);
}

void savePaymentHistory(int fineID, int amount, const char *method)
{
    FILE *fp=fopen("payments.dat","ab");
    struct PaymentHistory payment;

    if (!fp) return;

    payment.fineID=fineID;
    payment.amoutn=amount;
    payment.paymentDate=time(NULL);
    strncpy(payment.paymentMethod, method, sizeof(payment.paymentMethod)-1);

    fwrite(&payment, sizeof(payment),1,fp);
    fclose(fp);
}

void calculateStatistics(struct Statistics *stats)
{
    FILE *fp=fopen("fines.dat","rb");
    struct Fine f;
    time_t now=time(NULL);

    if(!fp) return;

    while(fread(&f,sizeof(f),1,fp))
    {
        (*stats).totalFines++;

        if (f.isPaid)
        {
            stats->paidFines++;
            stats->totalRevenue += f.finalAmount;
        }
        else
        {
            int days=daysBetween(f.issueTime,now);
            if(days>DISMISSAL_DAYS)
            {
                stats->dismissedFines++;
            }
            else
            {
                stats->unpaidFines;
                int amount=f.baseAmount;
                if(days>GRACE_PERIOD_DAYS)
                {
                    amount += (f.baseAmount * LATE_FEE_PERCENTAGE/100);
                }
                stats->PendingRevenue+=amount;
            }
        }
        if(f.isAppealed)
        {
            stats->appealedFines++;
        }
    }
    fclose(fp);


}

void displayStatistics(struct Statistics *stats)
{
printf("\n========================================\n");
printf("           SYSTEM STATISTICS            \n");
printf("========================================\n");
printf(" Total Fines Issued    : %-14d\n", stats->totalFines);
printf(" Paid Fines            : %-14d\n", stats->paidFines);
printf(" Unpaid Fines          : %-14d\n", stats->unpaidFines);
printf(" License Dismissed     : %-14d\n", stats->dismissedFines);
printf(" Appealed Fines        : %-14d\n", stats->appealedFines);
printf("----------------------------------------\n");
printf(" Total Revenue         : %-14d\n", stats->totalRevenue);
printf(" Pending Revenue       : %-14d\n", stats->PendingRevenue);
printf("========================================\n");

if (stats->totalFines > 0)
{
    float collectionRate =
        (float)stats->paidFines / stats->totalFines * 100;

    printf("\nCollection Rate: %.2f%%\n", collectionRate);
}
}

















