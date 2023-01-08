#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int seats_availablity(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i] == 0)
            return 1;
    }
    return 0;
}

int main()
{
    long long cost = 0;
    int Class, position, seat_1[15]={0}, seat_2[20]={0}, count_1st_class = 0, count_2nd_class = 0;
    char ch;
    do
    {
        system("color B");
        int flag = 0;
        printf("Press 1 for [First Class] - Rs 5000/Passenger\nPress 2 for [Economy Class] - Rs 2500/Passenger\n");
        scanf("%d",&Class);
        system("cls");
            switch(Class)
            {
            case 1:
                flag = seats_availablity(seat_1,15);
                if(flag == 1)
                {
                    flag = 0;
                    printf("Seats available \n");
                    for(int i=0;i<15;i++)
                    {
                        if(seat_1[i] == 0)
                            printf("%d ",i+1);
                    }
                    printf("\nChoose your seat : ");
                    scanf("%d",&position);
                    if(position > 15)
                        printf("!! Choose Valid Seat Number !!\n");
                    else if(seat_1[position-1] != 0)
                        printf("This seat is no longer Available\n");
                    else if(seat_1[position-1]==0)
                    {
                        printf("Boarding Pass:-\nYour Seat number = %d\nYour Section is [First Class]\n",position);
                        count_1st_class++;
                        cost += 5000;
                        seat_1[position-1]++;
                    }
                }
                else
                {
                    flag = seats_availablity(seat_2,20);
                    if(flag == 1)
                    {
                        flag = 0;
                        printf("Seats are available in Economy Section\nNext flight leaves in 3 hours\n");
                    }
                }
                break;

            case 2:
                flag = seats_availablity(seat_2,20);
                if(flag == 1)
                {
                    flag = 0;
                    printf("Seats available \n");
                    for(int i=0;i<20;i++)
                    {
                        if(seat_2[i] == 0)
                            printf("%d ",i+1);
                    }
                    printf("\nChoose your seat : ");
                    scanf("%d",&position);
                    if(position > 20)
                        printf("!! Choose Valid Seat Number !!\n");
                    else if(seat_2[position-1] != 0)
                        printf("This seat is no longer Available\n");
                    else if(seat_2[position-1]==0)
                    {
                        printf("Boarding Pass:-\nYour Seat number = %d\nYour Section is [Economy Section]\n",position);
                        count_2nd_class++;
                        cost += 2500;
                        seat_2[position-1]++;
                    }
                }
                else
                {
                    flag = seats_availablity(seat_1,15);
                    if(flag == 1)
                    {
                        flag = 0;
                        printf("Seats are available in First Class\nNext flight leaves in 3 hours\n");
                    }
                }
                break;
            }
            fflush(stdin);
            printf("Wish to continue(Y/N)\n");
            scanf("%c",&ch);
            system("cls");
    } while(ch=='Y'||ch=='y');
    system("color A");
    printf("Seats you have Booked :- \nFirst Class = %d\nEconomy Class = %d\n",count_1st_class,count_2nd_class);
    printf("\nTotal Money you need to pay = Rs %lld\n",cost);
    getch();
    return 0;
}
