#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

/* ================= CONSTANTS ================= */

#define MAX_VEHICLE_LEN 15
#define MAX_NAME_LEN 50
#define MAX_LOCATION_LEN 100
#define LATE_FEE_PERCENTAGE 20
#define DISMISSAL_DAYS 10
#define GRACE_PERIOD_DAYS 3

/* ================= STRUCT DEFINITIONS ================= */

struct Fine {
    int fineID;
    char vehicle[MAX_VEHICLE_LEN];
    char ownerName[MAX_NAME_LEN];
    char location[MAX_LOCATION_LEN];
    int violationType;
    int baseAmount;
    int finalAmount;
    int isPaid;
    int isAppealed;
    int appealStatus; // 0=pending, 1=approved, 2=rejected
    char appealReason[200];
    time_t issueTime;
    time_t payTime;
    char issuedBy[MAX_NAME_LEN];
};

struct PaymentHistory {
    int fineID;
    int amount;
    time_t paymentDate;
    char paymentMethod[20];
};

struct Statistics {
    int totalFines;
    int paidFines;
    int unpaidFines;
    int dismissedFines;
    int appealedFines;
    int totalRevenue;
    int pendingRevenue;
};

/* ================= FUNCTION DECLARATIONS ================= */

// Main Menu Functions
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

// Helper Functions
int fineIDExists(int id);
int daysBetween(time_t a, time_t b);
int getBaseFine(int type);
const char* getViolationName(int type);
void pause();
void clearScreen();
int validateVehicle(char *vehicle);
void toUpperCase(char *str);
int getNextFineID();
void savePaymentHistory(int fineID, int amount, const char *method);
void displayStatistics(struct Statistics *stats);
void calculateStatistics(struct Statistics *stats);
int confirmAction(const char *message);
void printHeader(const char *title);
void displayFineDetails(struct Fine *f, time_t now);

/* ================= MAIN ================= */

int main() {
    int choice;

    do {
        clearScreen();
        printHeader("TRAFFIC FINE MANAGEMENT SYSTEM");
        printf("1.  Issue New Fine\n");
        printf("2.  View All Fines\n");
        printf("3.  Search Fine\n");
        printf("4.  Pay Fine\n");
        printf("5.  Appeal Fine\n");
        printf("6.  Process Appeals (Admin)\n");
        printf("7.  Modify Fine (Admin)\n");
        printf("8.  Delete Fine (Admin)\n");
        printf("9.  Vehicle History\n");
        printf("10. Admin Dashboard\n");
        printf("11. Generate Reports\n");
        printf("12. Export Data\n");
        printf("13. Exit\n");
        printf("=========================================\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: issueFine(); break;
            case 2: viewFines(); break;
            case 3: searchFine(); break;
            case 4: payFine(); break;
            case 5: appealFine(); break;
            case 6: processAppeals(); break;
            case 7: modifyFine(); break;
            case 8: deleteFine(); break;
            case 9: vehicleHistory(); break;
            case 10: dashboard(); break;
            case 11: generateReports(); break;
            case 12: exportData(); break;
            case 13: printf("\n✅ Exiting system... Thank you!\n"); break;
            default: printf("\n❌ Invalid choice! Please try again.\n"); pause();
        }

    } while (choice != 13);

    return 0;
}

/* ================= ISSUE FINE ================= */

void issueFine() {
    struct Fine f;
    FILE *fp;

    clearScreen();
    printHeader("ISSUE NEW FINE");

    // Auto-generate Fine ID
    f.fineID = getNextFineID();
    printf("Auto-generated Fine ID: %d\n\n", f.fineID);

    // Vehicle Number
    do {
        printf("Vehicle Number: ");
        scanf("%s", f.vehicle);
        toUpperCase(f.vehicle);
        
        if (!validateVehicle(f.vehicle)) {
            printf("❌ Invalid vehicle number format!\n");
        }
    } while (!validateVehicle(f.vehicle));

    // Owner Name
    printf("Owner Name: ");
    getchar();
    fgets(f.ownerName, MAX_NAME_LEN, stdin);
    f.ownerName[strcspn(f.ownerName, "\n")] = 0;

    // Location
    printf("Violation Location: ");
    fgets(f.location, MAX_LOCATION_LEN, stdin);
    f.location[strcspn(f.location, "\n")] = 0;

    // Violation Type
    printf("\n╔════════════════════════════════════╗\n");
    printf("║    SELECT VIOLATION TYPE           ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ 1. Signal Jump        (₹1000)     ║\n");
    printf("║ 2. Speeding           (₹1500)     ║\n");
    printf("║ 3. No Helmet          (₹500)      ║\n");
    printf("║ 4. Wrong Parking      (₹300)      ║\n");
    printf("║ 5. Drunk Driving      (₹10000)    ║\n");
    printf("║ 6. No Seatbelt        (₹1000)     ║\n");
    printf("║ 7. Triple Riding      (₹500)      ║\n");
    printf("║ 8. No License         (₹5000)     ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Enter choice: ");
    scanf("%d", &f.violationType);

    if (f.violationType < 1 || f.violationType > 8) {
        printf("❌ Invalid violation type!\n");
        pause();
        return;
    }

    // Issued By
    printf("Issued By (Officer Name): ");
    getchar();
    fgets(f.issuedBy, MAX_NAME_LEN, stdin);
    f.issuedBy[strcspn(f.issuedBy, "\n")] = 0;

    f.baseAmount = getBaseFine(f.violationType);
    f.finalAmount = f.baseAmount;
    f.isPaid = 0;
    f.isAppealed = 0;
    f.appealStatus = 0;
    strcpy(f.appealReason, "");
    f.issueTime = time(NULL);
    f.payTime = 0;

    fp = fopen("fines.dat", "ab");
    if (!fp) {
        printf("❌ Error opening file!\n");
        pause();
        return;
    }
    
    fwrite(&f, sizeof(f), 1, fp);
    fclose(fp);

    printf("\n╔════════════════════════════════════╗\n");
    printf("║   ✅ FINE ISSUED SUCCESSFULLY      ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Fine ID    : %d\n", f.fineID);
    printf("Vehicle    : %s\n", f.vehicle);
    printf("Owner      : %s\n", f.ownerName);
    printf("Location   : %s\n", f.location);
    printf("Violation  : %s\n", getViolationName(f.violationType));
    printf("Amount     : ₹%d\n", f.baseAmount);
    printf("Issued By  : %s\n", f.issuedBy);
    printf("Date/Time  : %s", ctime(&f.issueTime));
    printf("─────────────────────────────────────\n");
    printf("⚠️  Pay within 3 days to avoid 20%% late fee\n");
    printf("⚠️  License will be dismissed after 10 days\n");

    pause();
}

/* ================= VIEW FINES ================= */

void viewFines() {
    FILE *fp = fopen("fines.dat", "rb");
    struct Fine f;
    time_t now = time(NULL);
    int count = 0;

    clearScreen();
    printHeader("ALL FINES");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
    printf("%-5s %-12s %-20s %-15s %-8s %-12s %-5s %-15s\n",
           "ID", "VEHICLE", "OWNER", "VIOLATION", "AMOUNT", "STATUS", "DAYS", "NOTE");
    printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");

    while (fread(&f, sizeof(f), 1, fp)) {
        displayFineDetails(&f, now);
        count++;
    }

    fclose(fp);
    
    if (count == 0) {
        printf("No fines found.\n");
    } else {
        printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
        printf("Total Fines: %d\n", count);
    }
    
    pause();
}

/* ================= SEARCH FINE ================= */

void searchFine() {
    FILE *fp = fopen("fines.dat", "rb");
    struct Fine f;
    char searchTerm[MAX_VEHICLE_LEN];
    int searchType;
    int found = 0;
    time_t now = time(NULL);

    clearScreen();
    printHeader("SEARCH FINE");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Search by:\n");
    printf("1. Fine ID\n");
    printf("2. Vehicle Number\n");
    printf("3. Owner Name\n");
    printf("Enter choice: ");
    scanf("%d", &searchType);

    printf("Enter search term: ");
    getchar();
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;
    toUpperCase(searchTerm);

    printf("\n─────────────────────────────────────────────────────────────────────────────────────────────\n");

    while (fread(&f, sizeof(f), 1, fp)) {
        char tempVehicle[MAX_VEHICLE_LEN], tempName[MAX_NAME_LEN];
        strcpy(tempVehicle, f.vehicle);
        strcpy(tempName, f.ownerName);
        toUpperCase(tempVehicle);
        toUpperCase(tempName);

        int match = 0;
        if (searchType == 1 && f.fineID == atoi(searchTerm)) match = 1;
        else if (searchType == 2 && strstr(tempVehicle, searchTerm)) match = 1;
        else if (searchType == 3 && strstr(tempName, searchTerm)) match = 1;

        if (match) {
            if (!found) {
                printf("%-5s %-12s %-20s %-15s %-8s %-12s %-5s %-15s\n",
                       "ID", "VEHICLE", "OWNER", "VIOLATION", "AMOUNT", "STATUS", "DAYS", "NOTE");
                printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
            }
            displayFineDetails(&f, now);
            found++;
        }
    }

    fclose(fp);

    if (!found) {
        printf("No matching fines found.\n");
    } else {
        printf("─────────────────────────────────────────────────────────────────────────────────────────────\n");
        printf("Found %d matching fine(s)\n", found);
    }

    pause();
}

/* ================= PAY FINE ================= */

void payFine() {
    FILE *fp = fopen("fines.dat", "rb+");
    struct Fine f;
    int id;
    char paymentMethod[20];
    time_t now = time(NULL);
    int found = 0;

    clearScreen();
    printHeader("PAY FINE");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Enter Fine ID to pay: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID == id) {
            found = 1;

            if (f.isPaid) {
                printf("\n❌ This fine has already been paid on %s", ctime(&f.payTime));
                fclose(fp);
                pause();
                return;
            }

            if (f.isAppealed && f.appealStatus == 0) {
                printf("\n⚠️  This fine is under appeal. Please wait for appeal decision.\n");
                fclose(fp);
                pause();
                return;
            }

            if (f.isAppealed && f.appealStatus == 1) {
                printf("\n✅ Appeal approved - Fine waived!\n");
                fclose(fp);
                pause();
                return;
            }

            int days = daysBetween(f.issueTime, now);

            if (days > DISMISSAL_DAYS) {
                printf("\n❌ License dismissed. Payment not allowed.\n");
                printf("Please contact the traffic department.\n");
                fclose(fp);
                pause();
                return;
            }

            // Calculate final amount
            if (days > GRACE_PERIOD_DAYS) {
                int lateFee = (f.baseAmount * LATE_FEE_PERCENTAGE) / 100;
                f.finalAmount = f.baseAmount + lateFee;
                printf("\n⚠️  Late payment! Additional 20%% late fee applied.\n");
            } else {
                f.finalAmount = f.baseAmount;
            }

            printf("\n═════════════════════════════════════\n");
            printf("Fine ID      : %d\n", f.fineID);
            printf("Vehicle      : %s\n", f.vehicle);
            printf("Owner        : %s\n", f.ownerName);
            printf("Violation    : %s\n", getViolationName(f.violationType));
            printf("Base Amount  : ₹%d\n", f.baseAmount);
            if (days > GRACE_PERIOD_DAYS) {
                printf("Late Fee     : ₹%d\n", f.finalAmount - f.baseAmount);
            }
            printf("═════════════════════════════════════\n");
            printf("TOTAL AMOUNT : ₹%d\n", f.finalAmount);
            printf("═════════════════════════════════════\n");

            if (!confirmAction("Proceed with payment?")) {
                fclose(fp);
                pause();
                return;
            }

            printf("\nPayment Method:\n");
            printf("1. Cash\n");
            printf("2. Card\n");
            printf("3. UPI\n");
            printf("4. Net Banking\n");
            printf("Enter choice: ");
            int method;
            scanf("%d", &method);

            switch (method) {
                case 1: strcpy(paymentMethod, "Cash"); break;
                case 2: strcpy(paymentMethod, "Card"); break;
                case 3: strcpy(paymentMethod, "UPI"); break;
                case 4: strcpy(paymentMethod, "Net Banking"); break;
                default: strcpy(paymentMethod, "Cash");
            }

            f.isPaid = 1;
            f.payTime = now;

            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            fclose(fp);

            // Save payment history
            savePaymentHistory(f.fineID, f.finalAmount, paymentMethod);

            printf("\n╔════════════════════════════════════╗\n");
            printf("║  ✅ PAYMENT SUCCESSFUL             ║\n");
            printf("╚════════════════════════════════════╝\n");
            printf("Receipt No    : %d\n", f.fineID);
            printf("Amount Paid   : ₹%d\n", f.finalAmount);
            printf("Payment Method: %s\n", paymentMethod);
            printf("Date/Time     : %s", ctime(&f.payTime));
            printf("─────────────────────────────────────\n");
            printf("Thank you for your payment!\n");

            pause();
            return;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n❌ Fine ID not found.\n");
    }

    pause();
}

/* ================= APPEAL FINE ================= */

void appealFine() {
    FILE *fp = fopen("fines.dat", "rb+");
    struct Fine f;
    int id;
    time_t now = time(NULL);
    int found = 0;

    clearScreen();
    printHeader("APPEAL FINE");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Enter Fine ID to appeal: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID == id) {
            found = 1;

            if (f.isPaid) {
                printf("\n❌ Cannot appeal a paid fine.\n");
                fclose(fp);
                pause();
                return;
            }

            if (f.isAppealed) {
                printf("\n❌ Appeal already submitted for this fine.\n");
                if (f.appealStatus == 0) printf("Status: Pending\n");
                else if (f.appealStatus == 1) printf("Status: Approved\n");
                else printf("Status: Rejected\n");
                fclose(fp);
                pause();
                return;
            }

            int days = daysBetween(f.issueTime, now);
            if (days > DISMISSAL_DAYS) {
                printf("\n❌ Cannot appeal after license dismissal.\n");
                fclose(fp);
                pause();
                return;
            }

            printf("\n═════════════════════════════════════\n");
            printf("Fine ID    : %d\n", f.fineID);
            printf("Vehicle    : %s\n", f.vehicle);
            printf("Violation  : %s\n", getViolationName(f.violationType));
            printf("Amount     : ₹%d\n", f.baseAmount);
            printf("═════════════════════════════════════\n");

            printf("\nEnter reason for appeal (max 200 chars):\n");
            getchar();
            fgets(f.appealReason, sizeof(f.appealReason), stdin);
            f.appealReason[strcspn(f.appealReason, "\n")] = 0;

            if (strlen(f.appealReason) < 10) {
                printf("\n❌ Appeal reason too short. Minimum 10 characters required.\n");
                fclose(fp);
                pause();
                return;
            }

            f.isAppealed = 1;
            f.appealStatus = 0; // Pending

            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            fclose(fp);

            printf("\n✅ Appeal submitted successfully!\n");
            printf("Your appeal is pending review by the admin.\n");

            pause();
            return;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n❌ Fine ID not found.\n");
    }

    pause();
}

/* ================= PROCESS APPEALS ================= */

void processAppeals() {
    FILE *fp = fopen("fines.dat", "rb+");
    struct Fine f;
    int count = 0;
    int choice, id;

    clearScreen();
    printHeader("PROCESS APPEALS (ADMIN)");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Pending Appeals:\n");
    printf("─────────────────────────────────────────────────────────────────────────\n");

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.isAppealed && f.appealStatus == 0) {
            printf("\nFine ID    : %d\n", f.fineID);
            printf("Vehicle    : %s\n", f.vehicle);
            printf("Owner      : %s\n", f.ownerName);
            printf("Violation  : %s\n", getViolationName(f.violationType));
            printf("Amount     : ₹%d\n", f.baseAmount);
            printf("Reason     : %s\n", f.appealReason);
            printf("─────────────────────────────────────────────────────────────────────────\n");
            count++;
        }
    }

    if (count == 0) {
        printf("No pending appeals.\n");
        fclose(fp);
        pause();
        return;
    }

    printf("\nTotal pending appeals: %d\n", count);
    printf("\nEnter Fine ID to process (0 to cancel): ");
    scanf("%d", &id);

    if (id == 0) {
        fclose(fp);
        return;
    }

    rewind(fp);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID == id && f.isAppealed && f.appealStatus == 0) {
            printf("\nAppeal Decision:\n");
            printf("1. Approve (Waive fine)\n");
            printf("2. Reject\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                f.appealStatus = 1; // Approved
                printf("\n✅ Appeal approved. Fine waived.\n");
            } else if (choice == 2) {
                f.appealStatus = 2; // Rejected
                printf("\n❌ Appeal rejected.\n");
            } else {
                printf("\n❌ Invalid choice.\n");
                fclose(fp);
                pause();
                return;
            }

            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            fclose(fp);

            pause();
            return;
        }
    }

    fclose(fp);
    printf("\n❌ Fine ID not found or not pending.\n");
    pause();
}

/* ================= DASHBOARD ================= */

void dashboard() {
    struct Statistics stats = {0};

    clearScreen();
    printHeader("ADMIN DASHBOARD");

    calculateStatistics(&stats);
    displayStatistics(&stats);

    pause();
}

/* ================= GENERATE REPORTS ================= */

void generateReports() {
    FILE *fp = fopen("fines.dat", "rb");
    FILE *report;
    struct Fine f;
    time_t now = time(NULL);
    char filename[50];
    int reportType;

    clearScreen();
    printHeader("GENERATE REPORTS");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Select Report Type:\n");
    printf("1. All Fines Report\n");
    printf("2. Unpaid Fines Report\n");
    printf("3. Revenue Report\n");
    printf("4. Daily Report\n");
    printf("Enter choice: ");
    scanf("%d", &reportType);

    sprintf(filename, "report_%ld.txt", (long)now);
    report = fopen(filename, "w");

    if (!report) {
        printf("❌ Error creating report file!\n");
        fclose(fp);
        pause();
        return;
    }

    fprintf(report, "═══════════════════════════════════════════════════════════\n");
    fprintf(report, "        TRAFFIC FINE MANAGEMENT SYSTEM - REPORT\n");
    fprintf(report, "═══════════════════════════════════════════════════════════\n");
    fprintf(report, "Generated on: %s", ctime(&now));
    fprintf(report, "═══════════════════════════════════════════════════════════\n\n");

    int count = 0;
    int totalAmount = 0;

    while (fread(&f, sizeof(f), 1, fp)) {
        int include = 0;
        int days = daysBetween(f.issueTime, now);

        if (reportType == 1) include = 1;
        else if (reportType == 2 && !f.isPaid && days <= DISMISSAL_DAYS) include = 1;
        else if (reportType == 3 && f.isPaid) include = 1;
        else if (reportType == 4 && daysBetween(f.issueTime, now) == 0) include = 1;

        if (include) {
            fprintf(report, "Fine ID    : %d\n", f.fineID);
            fprintf(report, "Vehicle    : %s\n", f.vehicle);
            fprintf(report, "Owner      : %s\n", f.ownerName);
            fprintf(report, "Violation  : %s\n", getViolationName(f.violationType));
            fprintf(report, "Amount     : ₹%d\n", f.finalAmount);
            fprintf(report, "Status     : %s\n", f.isPaid ? "PAID" : "UNPAID");
            fprintf(report, "Issue Date : %s", ctime(&f.issueTime));
            if (f.isPaid) fprintf(report, "Pay Date   : %s", ctime(&f.payTime));
            fprintf(report, "───────────────────────────────────────────────────────────\n");
            count++;
            if (f.isPaid) totalAmount += f.finalAmount;
        }
    }

    fprintf(report, "\nTotal Records: %d\n", count);
    if (reportType == 3) {
        fprintf(report, "Total Revenue: ₹%d\n", totalAmount);
    }

    fclose(fp);
    fclose(report);

    printf("\n✅ Report generated successfully!\n");
    printf("Filename: %s\n", filename);
    printf("Total records: %d\n", count);

    pause();
}

/* ================= VEHICLE HISTORY ================= */

void vehicleHistory() {
    FILE *fp = fopen("fines.dat", "rb");
    struct Fine f;
    char vehicle[MAX_VEHICLE_LEN];
    int found = 0;
    int totalFines = 0, paidFines = 0, totalAmount = 0;
    time_t now = time(NULL);

    clearScreen();
    printHeader("VEHICLE HISTORY");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Enter Vehicle Number: ");
    scanf("%s", vehicle);
    toUpperCase(vehicle);

    printf("\n═══════════════════════════════════════════════════════════\n");
    printf("Vehicle: %s\n", vehicle);
    printf("═══════════════════════════════════════════════════════════\n\n");

    while (fread(&f, sizeof(f), 1, fp)) {
        char tempVehicle[MAX_VEHICLE_LEN];
        strcpy(tempVehicle, f.vehicle);
        toUpperCase(tempVehicle);

        if (strcmp(tempVehicle, vehicle) == 0) {
            if (!found) {
                printf("Owner: %s\n\n", f.ownerName);
                printf("Violation History:\n");
                printf("───────────────────────────────────────────────────────────\n");
            }

            printf("Fine ID    : %d\n", f.fineID);
            printf("Violation  : %s\n", getViolationName(f.violationType));
            printf("Amount     : ₹%d\n", f.finalAmount);
            printf("Status     : %s\n", f.isPaid ? "PAID" : "UNPAID");
            printf("Date       : %s", ctime(&f.issueTime));
            printf("Location   : %s\n", f.location);
            printf("───────────────────────────────────────────────────────────\n");

            found = 1;
            totalFines++;
            if (f.isPaid) {
                paidFines++;
                totalAmount += f.finalAmount;
            }
        }
    }

    fclose(fp);

    if (!found) {
        printf("No fines found for this vehicle.\n");
    } else {
        printf("\nSummary:\n");
        printf("Total Fines  : %d\n", totalFines);
        printf("Paid Fines   : %d\n", paidFines);
        printf("Unpaid Fines : %d\n", totalFines - paidFines);
        printf("Total Paid   : ₹%d\n", totalAmount);
    }

    pause();
}

/* ================= MODIFY FINE ================= */

void modifyFine() {
    FILE *fp = fopen("fines.dat", "rb+");
    struct Fine f;
    int id, found = 0;

    clearScreen();
    printHeader("MODIFY FINE (ADMIN)");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("Enter Fine ID to modify: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID == id) {
            found = 1;

            printf("\nCurrent Details:\n");
            printf("─────────────────────────────────────\n");
            printf("Vehicle    : %s\n", f.vehicle);
            printf("Owner      : %s\n", f.ownerName);
            printf("Violation  : %s\n", getViolationName(f.violationType));
            printf("Amount     : ₹%d\n", f.baseAmount);
            printf("Status     : %s\n", f.isPaid ? "PAID" : "UNPAID");
            printf("─────────────────────────────────────\n");

            if (f.isPaid) {
                printf("\n❌ Cannot modify a paid fine.\n");
                fclose(fp);
                pause();
                return;
            }

            if (!confirmAction("Modify this fine?")) {
                fclose(fp);
                return;
            }

            printf("\nModify:\n");
            printf("1. Violation Type\n");
            printf("2. Amount\n");
            printf("3. Both\n");
            printf("Enter choice: ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1 || choice == 3) {
                printf("\nSelect New Violation Type:\n");
                printf("1. Signal Jump (₹1000)\n");
                printf("2. Speeding (₹1500)\n");
                printf("3. No Helmet (₹500)\n");
                printf("4. Wrong Parking (₹300)\n");
                printf("5. Drunk Driving (₹10000)\n");
                printf("6. No Seatbelt (₹1000)\n");
                printf("7. Triple Riding (₹500)\n");
                printf("8. No License (₹5000)\n");
                printf("Enter choice: ");
                scanf("%d", &f.violationType);
                f.baseAmount = getBaseFine(f.violationType);
                f.finalAmount = f.baseAmount;
            }

            if (choice == 2) {
                printf("Enter new amount: ₹");
                scanf("%d", &f.baseAmount);
                f.finalAmount = f.baseAmount;
            }

            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            fclose(fp);

            printf("\n✅ Fine modified successfully!\n");
            pause();
            return;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\n❌ Fine ID not found.\n");
    }

    pause();
}

/* ================= DELETE FINE ================= */

void deleteFine() {
    FILE *fp = fopen("fines.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Fine f;
    int id, found = 0;

    clearScreen();
    printHeader("DELETE FINE (ADMIN)");

    if (!fp) {
        printf("No records found.\n");
        pause();
        return;
    }

    printf("⚠️  WARNING: This action cannot be undone!\n\n");
    printf("Enter Fine ID to delete: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID == id) {
            found = 1;

            printf("\nFine Details:\n");
            printf("─────────────────────────────────────\n");
            printf("Fine ID    : %d\n", f.fineID);
            printf("Vehicle    : %s\n", f.vehicle);
            printf("Owner      : %s\n", f.ownerName);
            printf("Violation  : %s\n", getViolationName(f.violationType));
            printf("Amount     : ₹%d\n", f.baseAmount);
            printf("─────────────────────────────────────\n");

            if (!confirmAction("Delete this fine permanently?")) {
                fwrite(&f, sizeof(f), 1, temp);
            } else {
                printf("\n✅ Fine deleted successfully!\n");
            }
        } else {
            fwrite(&f, sizeof(f), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("fines.dat");
    rename("temp.dat", "fines.dat");

    if (!found) {
        printf("\n❌ Fine ID not found.\n");
    }

    pause();
}

/* ================= EXPORT DATA ================= */

void exportData() {
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

    if (!csv) {
        printf("❌ Error creating export file!\n");
        fclose(fp);
        pause();
        return;
    }

    // Write CSV header
    fprintf(csv, "Fine ID,Vehicle,Owner,Location,Violation,Base Amount,Final Amount,Status,Issue Date,Pay Date,Issued By\n");

    int count = 0;
    while (fread(&f, sizeof(f), 1, fp)) {
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

    printf("✅ Data exported successfully!\n");
    printf("Filename: %s\n", filename);
    printf("Total records: %d\n", count);

    pause();
}

/* ================= HELPER FUNCTIONS ================= */

int fineIDExists(int id) {
    FILE *fp = fopen("fines.dat", "rb");
    struct Fine f;

    if (!fp) return 0;

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int getNextFineID() {
    FILE *fp = fopen("fines.dat", "rb");
    struct Fine f;
    int maxID = 1000;

    if (!fp) return maxID;

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.fineID >= maxID) {
            maxID = f.fineID + 1;
        }
    }

    fclose(fp);
    return maxID;
}

int daysBetween(time_t a, time_t b) 
{
    return (int)(difftime(b, a) / (60 * 60 * 24));
}

int getBaseFine(int type) {
    switch (type) {
        case 1: return 1000;  // Signal Jump
        case 2: return 1500;  // Speeding
        case 3: return 500;   // No Helmet
        case 4: return 300;   // Wrong Parking
        case 5: return 10000; // Drunk Driving
        case 6: return 1000;  // No Seatbelt
        case 7: return 500;   // Triple Riding
        case 8: return 5000;  // No License
        default: return 300;
    }
}

const char* getViolationName(int type) {
    switch (type) {
        case 1: return "Signal Jump";
        case 2: return "Speeding";
        case 3: return "No Helmet";
        case 4: return "Wrong Parking";
        case 5: return "Drunk Driving";
        case 6: return "No Seatbelt";
        case 7: return "Triple Riding";
        case 8: return "No License";
        default: return "Unknown";
    }
}

int validateVehicle(char *vehicle) {
    int len = strlen(vehicle);
    if (len < 4 || len > 14) return 0;
    // Basic validation - can be enhanced
    return 1;
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void pause() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int confirmAction(const char *message) {
    char response;
    printf("\n%s (y/n): ", message);
    scanf(" %c", &response);
    return (response == 'y' || response == 'Y');
}

void printHeader(const char *title) {
    printf("\n=========================================\n");
    printf("     %s\n", title);
    printf("=========================================\n");
}

void displayFineDetails(struct Fine *f, time_t now) {
    int days = daysBetween(f->issueTime, now);
    char status[15] = "UNPAID";
    char note[25] = "-";
    int displayAmount = f->finalAmount;

    if (!f->isPaid) {
        if (f->isAppealed) {
            if (f->appealStatus == 0) strcpy(status, "APPEALED");
            else if (f->appealStatus == 1) strcpy(status, "WAIVED");
            else strcpy(status, "REJECTED");
        } else if (days > DISMISSAL_DAYS) {
            strcpy(status, "DISMISSED");
            strcpy(note, "LICENSE HOLD");
        } else if (days > GRACE_PERIOD_DAYS) {
            displayAmount = f->baseAmount + (f->baseAmount * LATE_FEE_PERCENTAGE / 100);
            strcpy(note, "+20% LATE");
        }
    } else {
        strcpy(status, "PAID");
        strcpy(note, "✓");
    }

    printf("%-5d %-12s %-20.20s %-15s ₹%-7d %-12s %-5d %-15s\n",
           f->fineID,
           f->vehicle,
           f->ownerName,
           getViolationName(f->violationType),
           displayAmount,
           status,
           days,
           note);
}

void savePaymentHistory(int fineID, int amount, const char *method) {
    FILE *fp = fopen("payments.dat", "ab");
    struct PaymentHistory payment;

    if (!fp) return;

    payment.fineID = fineID;
    payment.amount = amount;
    payment.paymentDate = time(NULL);
    strncpy(payment.paymentMethod, method, sizeof(payment.paymentMethod) - 1);

    fwrite(&payment, sizeof(payment), 1, fp);
    fclose(fp);
}

void calculateStatistics(struct Statistics *stats) {
    FILE *fp = fopen("fines.dat", "rb");
    struct Fine f;
    time_t now = time(NULL);

    if (!fp) return;

    while (fread(&f, sizeof(f), 1, fp)) {
        stats->totalFines++;

        if (f.isPaid) {
            stats->paidFines++;
            stats->totalRevenue += f.finalAmount;
        } else {
            int days = daysBetween(f.issueTime, now);
            if (days > DISMISSAL_DAYS) {
                stats->dismissedFines++;
            } else {
                stats->unpaidFines++;
                int amount = f.baseAmount;
                if (days > GRACE_PERIOD_DAYS) {
                    amount += (f.baseAmount * LATE_FEE_PERCENTAGE / 100);
                }
                stats->pendingRevenue += amount;
            }
        }

        if (f.isAppealed) {
            stats->appealedFines++;
        }
    }

    fclose(fp);
}

void displayStatistics(struct Statistics *stats) {
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║          SYSTEM STATISTICS             ║\n");
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Total Fines Issued    : %-14d ║\n", stats->totalFines);
    printf("║ Paid Fines            : %-14d ║\n", stats->paidFines);
    printf("║ Unpaid Fines          : %-14d ║\n", stats->unpaidFines);
    printf("║ License Dismissed     : %-14d ║\n", stats->dismissedFines);
    printf("║ Appealed Fines        : %-14d ║\n", stats->appealedFines);
    printf("╠════════════════════════════════════════╣\n");
    printf("║ Total Revenue         : ₹%-13d ║\n", stats->totalRevenue);
    printf("║ Pending Revenue       : ₹%-13d ║\n", stats->pendingRevenue);
    printf("╚════════════════════════════════════════╝\n");

    if (stats->totalFines > 0) {
        float collectionRate = (float)stats->paidFines / stats->totalFines * 100;
        printf("\nCollection Rate: %.2f%%\n", collectionRate);
    }
}