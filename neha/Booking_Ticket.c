#include <stdio.h>
char busNumbers[3][10] = {"1", "2", "3"};
char routes[3][50] = {"Jodhpur - Jaipur", "Jodhpur - Jaisalmer", "Jodhpur - Bikaner"};
float fares[3] = {25.5, 30.0, 20.0};

int seats[3][10] = {0};
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

    busIndex--;

    if (busIndex < 0 || busIndex >= 3)
    {
        printf("Invalid bus selection.\n");
        return;
    }

    printf("Enter the number of seats you want to book: ");
    scanf("%d", &numSeats);

    if (numSeats < 1 || numSeats > 10)
    {
        printf("Invalid seat count. Try again.\n");
        return;
    }

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

int main()
{
    bookTicket();
    return 0;
}
