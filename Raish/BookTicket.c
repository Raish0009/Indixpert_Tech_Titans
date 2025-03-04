#include <stdio.h>

char busNumbers[3][10] = {"11", "12", "13"};
char routes[3][50] = {"Jodhpur - Jaipur", "Jodhpur - Jaisalmer", "Jodhpur - Bikaner"};
float fares[3] = {25.5, 30.0, 20.0};
int seats[3][10] = {0};

void bookTicket();

void bookTicket()
{
    int busIndex, seatNumber;

    printf("Select a bus: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s - %s ($%.2f)\n", i + 1, busNumbers[i], routes[i], fares[i]);
    }
    printf("Choose Bus: ");
    scanf("%d", &busIndex);

    busIndex--;

    if (busIndex < 0 || busIndex >= 3)
    {
        printf("Invalid bus selection.\n");
        return;
    }

    printf("Enter seat number (1-10): ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > 10 || seats[busIndex][seatNumber - 1] != 0)
    {
        printf("Invalid or already booked seat. Try another.\n");
        return;
    }

    seats[busIndex][seatNumber - 1] = 1;
    printf("\nTicket booked successfully!\n \nBus number : %s \nSeat number : %d \nBus fare: $%.2f\n\n", busNumbers[busIndex], seatNumber, fares[busIndex]);
}


int main()
{
    bookTicket();
    return 0;
}
