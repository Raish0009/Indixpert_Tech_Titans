#include <stdio.h>

void Check_status();
void Bus_number();

void Check_status()
{
    int fare[5] = {100, 150, 180, 210, 250};
    int Bus[5][2] = {{11, 50}, {12, 50}, {13, 50}, {14, 50}, {15, 50}};
    char Source_City[5][10] = {"Jodhpur", "Jaipur", "Bikaner", "Barmer", "Udaipur"};
    char Destination_City[5][10] = {"Bikaner", "Udaipur", "Jaipur", "Jodhpur", "Barmer"};

    while (1)
    {
        int Bus_number = 0;

        printf("\nEnter Bus Number: ");
        if (scanf("%d", &Bus_number) != 1) 
        {
            while (getchar() != '\n');
            continue;
        }

        int match = -1;
        for (int i = 0; i < 5; i++)
        {
            if (Bus[i][0] == Bus_number)
            {
                match = i;
                break;
            }
        }

        if (match >= 0)
        {
            printf("\n Bus Number       :       %d", Bus[match][0]);
            printf("\n Source           :       %s", Source_City[match]);
            printf("\n Destination      :       %s", Destination_City[match]);
            printf("\n Total Seats      :       %d", 50);
            printf("\n Available Seats  :       %d", Bus[match][1]);
            printf("\n Fare             :       %d", fare[match]);
        }
    }
}

void Bus_number()
{
    printf(" Bus Numbers :\n");
    printf(" 11 \n");
    printf(" 12 \n");
    printf(" 13 \n");
    printf(" 14 \n");
    printf(" 15 \n");
}

int main()
{
    Bus_number();
    Check_status();
    return 0;
}