#include<cstdio>
#include<cstdlib>
#include "rr.h"
//Main function to implement the menu of the program 
int main()
{
    list l1;
    int opt,burst_time,const_time;
    while(1)
    {
        printf("\nMenu:\n");
        printf("1. Insert Process\n");
        printf("2. Execute\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                    printf("Enter process burst time: ");
                    scanf("%d", &burst_time);
                    l1.insert(burst_time);
                    l1.display();
                    break;
            case 2:
                    printf("Enter the fixed time slot (Time Quantum): ");
                    scanf("%d", &const_time);
                    l1.execute(const_time);
                    l1.display();
                    break;
            case 3:
                    printf("Exiting program.\n");
                    return 0;
            default:
                    printf("Invalid option\n");
        }
    }
}

