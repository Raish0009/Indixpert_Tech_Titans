#include <stdio.h>

void Check_status();

void Bus_number();

void Check_status()
{
    int fare[3] = {100, 140, 180};
    int Bus[3][2] = {{101, 50}, {102, 50}, {103, 50}};
    char Source_City[5][10] = {"Jodhpur", "Jaipur", "Bikaner"};
    char Destination_City[5][10] = {"Bikaner", "Udaipur", "Jaipur"};

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
        for (int i = 0; i < 3; i++)
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
    printf(" 101 \n");
    printf(" 102 \n");
    printf(" 103 \n");
}

int main()
{
    Bus_number();
    Check_status();
    return 0;
}
