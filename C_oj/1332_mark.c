#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char input_time[12];
    int hour , min , sec;
    gets(input_time);
    if ( input_time[0] == 'A' && input_time[1] == 'M')
    {
        hour = (input_time[3] - 48) * 10 + (input_time[4] - 48);
        min = (input_time[6] - 48) * 10 + (input_time[7] - 48);
        sec = (input_time[9] - 48) * 10 + (input_time[10] - 48);
    }
    else
    {
        hour = (input_time[3] - 48) * 10 + (input_time[4] - 48);
        if (hour != 12)
        {
            hour += 12;
        }
        min = (input_time[6] - 48) * 10 + (input_time[7] - 48);
        sec = (input_time[9] - 48) * 10 + (input_time[10] - 48);
    }
    int input_sec;
    int myinput_hour , myinput_min , myinput_sec;
    scanf("%d",&input_sec);
    myinput_hour = input_sec / 3600;
    myinput_min = (input_sec - (myinput_hour * 3600)) / 60;
    myinput_sec = input_sec - (myinput_hour * 3600 + myinput_min * 60);

    int carry = 0 , temp;

    carry = (sec + myinput_sec) / 60;
    sec = (sec + myinput_sec) % 60;

    temp = carry;
    carry = (min + myinput_min + carry ) / 60;
    min = (min + myinput_min + temp) % 60;

    temp = carry;
    hour = (hour + myinput_hour + carry) % 24;
    
    if ( 0 <= hour && hour <= 11 )
    {
        if (hour == 0)
        {
            printf("AM %02d:%02d:%02d",hour+12,min,sec);
        }
        else
        {
            printf("AM %02d:%02d:%02d",hour,min,sec);
        }
    }
    else if ( 12 <= hour && hour <= 23)
    {
        if ( 12 == hour)
        {
            printf("PM %02d:%02d:%02d",hour,min,sec);
        }
        else
        {
            printf("PM %02d:%02d:%02d",hour-12,min,sec);
        }
    }
    system("pause");
    return 0;
}