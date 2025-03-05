#include <stdio.h>
#include <string.h>

char busNumbers[3][10] = {"1", "2", "3"};
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

    printf("Enter the number of seats to cancel: ");
    scanf("%d", &seatsToCancel);


    if (seatsToCancel < 1 || seatsToCancel > 10)
    {
        printf("Invalid number of seats to cancel.\n");
        return;
    }

    printf("\nTicket for bus %s\n%d seats has been canceled successfully!\n", busNumbers[busIndex], seatsToCancel);
}

int main(){
    cancelTicket();
    return 0;
}
