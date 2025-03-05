#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char busNumbers[3][10] = {"1", "2", "3"};
char routes[3][50] = {"Jodhpur - Jaipur", "Jodhpur - Jaisalmer", "Jodhpur - Bikaner"};
float fares[3] = {25.5, 30.0, 20.0};
int seats[3][10] = {0};

char usernames[5][30];
char passwords[5][30];
int totalUsers = 0;

void signUp();
int signIn();
void dashboard();
void bookTicket();
void cancelTicket();
void checkBusStatus();

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
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void signUp()
{
    if (totalUsers >= 5)
    {
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

int signIn()
{
    char username[30], password[30];

    printf("Enter your username: ");
    fgets(username, 30, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter your password: ");
    fgets(password, 30, stdin);
    password[strcspn(password, "\n")] = 0;

    for (int i = 0; i < totalUsers; i++)
    {
        if (strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void dashboard()
{
    int choice;
    while (1)
    {
        printf("\n--- Dashboard ---\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            bookTicket();
            break;
        case 2:
            cancelTicket();
            break;
        case 3:
            checkBusStatus();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

void bookTicket()
{
    int busIndex, numSeats, booked = 0;

    printf("Select a bus:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s - %s ($%.2f)\n", i + 1, busNumbers[i], routes[i], fares[i]);
    }
    printf("Enter your choice: ");
    scanf("%d", &busIndex);
    getchar();
    busIndex--;

    if (busIndex < 0 || busIndex >= 3)
    {
        printf("Invalid bus selection.\n");
        return;
    }

    printf("Enter the number of seats you want to book: ");
    scanf("%d", &numSeats);
    getchar();

    if (numSeats < 1 || numSeats > 10)
    {
        printf("Invalid seat count. Try again.\n");
        return;
    }

    // Check available seats
    for (int i = 0; i < 10; i++)
    {
        if (seats[busIndex][i] == 0)
        {
            seats[busIndex][i] = 1;
            booked++;

            if (booked == numSeats)
                break;
        }
    }

    if (booked < numSeats)
    {
        printf("Only %d seats were available and booked.\n", booked);
    }
    else
    {
        printf("Successfully booked %d seats on Bus %s!\n", numSeats, busNumbers[busIndex]);
    }
}

void cancelTicket()
{
    int busIndex, seatsToCancel;

    printf("Select a bus:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s - %s\n", i + 1, busNumbers[i], routes[i]);
    }
    printf("Enter your choice: ");
    scanf("%d", &busIndex);
    getchar();
    busIndex--;

    if (busIndex < 0 || busIndex >= 3)
    {
        printf("Invalid bus selection.\n");
        return;
    }

    printf("Enter the number of seats to cancel: ");
    scanf("%d", &seatsToCancel);
    getchar();

    if (seatsToCancel < 1 || seatsToCancel > 10)
    {
        printf("Invalid number of seats to cancel.\n");
        return;
    }

    int canceledSeats = 0;

    while (canceledSeats < seatsToCancel)
    {
        int seatNumber = rand() % 10;
        if (seats[busIndex][seatNumber] == 1)
        {
            seats[busIndex][seatNumber] = 0;
            canceledSeats++;
        }
    }
    printf("\nTicket for bus %s\n%d seats has been canceled successfully!\n", busNumbers[busIndex], seatsToCancel);
}

void checkBusStatus()
{
    int busIndex, availableSeats;

    printf("Select a bus to check status:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. Bus %s - %s\n", i + 1, busNumbers[i], routes[i]);
    }
    printf("Enter the bus number (1-3): ");
    scanf("%d", &busIndex);
    getchar();

    if (busIndex < 1 || busIndex > 3)
    {
        printf("Invalid bus number. Please select a number between 1 and 3.\n");
        return;
    }

    busIndex--;

    availableSeats = 0;

    for (int i = 0; i < 10; i++)
    {
        if (seats[busIndex][i] == 0)
        {
            availableSeats++;
        }
    }

    // Display bus status
    printf("\n--- Bus %s ---\n", busNumbers[busIndex]);
    printf("Route: %s\n", routes[busIndex]);
    printf("Total Seats: 10\n");
    printf("Available Seats: %d\n", availableSeats);
    printf("Fare: $%.2f\n", fares[busIndex]);
}
