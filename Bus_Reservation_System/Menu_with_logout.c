#include <stdio.h>


void bookTicket(int busNumber, int seats);
void cancelTicket(int busNumber, int seats);
void checkBusStatus(int busNumber);

int main() {
    int choice, busNumber, seats;

    while (1) {
        printf("\n=== User Menu ===\n");
        printf("1. Book a Ticket\n");
        printf("2. Cancel a Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Bus Number: ");
            scanf("%d", &busNumber);
            printf("Enter Number Of Seats: ");
            scanf("%d", &seats);
            bookTicket(busNumber, seats);
        } else if (choice == 2) {
            printf("Enter Bus Number: ");
            scanf("%d", &busNumber);
            printf("Enter Number Of Seats to Cancel: ");
            scanf("%d", &seats);
            cancelTicket(busNumber, seats);
        } else if (choice == 3) {
            printf("Please enter Bus Number: ");
            scanf("%d", &busNumber);
            checkBusStatus(busNumber);
        } else if (choice == 4) {
            printf("Logout successful.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void bookTicket(int busNumber, int seats) {
    printf("Ticket booked for Bus %d, Seats: %d\n", busNumber, seats);
}

void cancelTicket(int busNumber, int seats) {
    printf("Canceled %d seat(s) from Bus %d\n", seats, busNumber);
}

void checkBusStatus(int busNumber) {
    printf("Bus %d status: Available\n", busNumber);
}
