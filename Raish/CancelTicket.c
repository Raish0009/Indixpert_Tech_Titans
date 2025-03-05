#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char busNumbers[3][10] = {"101", "102", "103"};
char routes[3][50] = {"Jodhpur - Jaipur", "Jodhpur - Jaisalmer", "Jodhpur - Bikaner"};
float fares[3] = {25.5, 30.0, 20.0};
int seats[3][10] = {0};

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

    busIndex--;

    if (busIndex < 0 || busIndex >= 3)
    {
        printf("Invalid bus selection.\n");
        return;
    }

    int bookedSeats = 0;
    for (int i = 0; i < 10; i++)
    {
        if (seats[busIndex][i] == 1)
        {
            bookedSeats++;
        }
    }

    if (bookedSeats == 0)
    {
        printf("No seats have been booked on this bus. You cannot cancel any tickets.\n");
        return;
    }

    printf("Enter the number of seats to cancel: ");
    
    if (scanf("%d", &seatsToCancel) != 1 || seatsToCancel < 1 || seatsToCancel > bookedSeats)
    {
        printf("Invalid number of seats to cancel. You can only cancel up to %d seats.\n", bookedSeats);
        while (getchar() != '\n'); 
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
    
    printf("\nTicket for bus %s\n%d seats have been canceled successfully!\n", busNumbers[busIndex], seatsToCancel);
}


int main()
{
    cancelTicket();
    return 0;
}