#include <stdio.h>

#include <string.h>

void signUp();
int signIn();
int dashboard();
void bookTicket(int busNumber, int seats);
void cancelTicket(int busNumber, int seats);
void checkBusStatus(int busNumber);

char usernames[5][30];
char passwords[5][30];
int totalUsers = 0;


int dashboard()
{
    int choice, busNumber, seats;

    while (1)
    {
        printf("\n=== User Menu ===\n");
        printf("1. Book a Ticket\n");
        printf("2. Cancel a Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Bus Number: ");
            scanf("%d", &busNumber);
            printf("Enter Number Of Seats: ");
            scanf("%d", &seats);
            bookTicket(busNumber, seats);
        }
        else if (choice == 2)
        {
            printf("Enter Bus Number: ");
            scanf("%d", &busNumber);
            printf("Enter Number Of Seats to Cancel: ");
            scanf("%d", &seats);
            cancelTicket(busNumber, seats);
        }
        else if (choice == 3)
        {
            printf("Please enter Bus Number: ");
            scanf("%d", &busNumber);
            checkBusStatus(busNumber);
        }
        else if (choice == 4)
        {
            printf("Logout successful.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void signUp() {
    if (totalUsers >= 5) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    
    printf("Enter a username: ");
    fgets(usernames[totalUsers], 30, stdin);
    usernames[totalUsers][strcspn(usernames[totalUsers], "\n")] = 0;
    
    printf("Enter a password: ");
    fgets(passwords[totalUsers], 30, stdin);
    passwords[totalUsers][strcspn(passwords[totalUsers], "\n")] = 0;
    
    totalUsers++;
    printf("Sign-up successful! You can now log in.\n");
}

int signIn() {
    char username[30], password[30];
    
    printf("Enter your username: ");
    fgets(username, 30, stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Enter your password: ");
    fgets(password, 30, stdin);
    password[strcspn(password, "\n")] = 0;
    
    for (int i = 0; i < totalUsers; i++) {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


void bookTicket(int busNumber, int seats)
{
    printf("Ticket booked for Bus %d, Seats: %d\n", busNumber, seats);
}

void cancelTicket(int busNumber, int seats)
{
    printf("Canceled %d seat(s) from Bus %d\n", seats, busNumber);
}

void checkBusStatus(int busNumber)
{
    printf("Bus %d status: Available\n", busNumber);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Bus Reservation System ---\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            if (signIn())
            {
                dashboard();
            }
            else
            {
                printf("Invalid credentials. Please try again.\n");
            }
            break;
        case 3:
            printf("Exit successful.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
