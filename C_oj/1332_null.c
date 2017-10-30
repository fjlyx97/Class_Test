#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char str[12];
    gets(str);
    int input_hour = atoi(&str[3]);
    int input_min = atoi(&str[6]);
    int input_sec_1 = atoi(&str[9]);
    int input_sec = 0;
    scanf("%d",&input_sec);
    int hour , min , sec;
    if (input_sec >= 3600 )
    {
        hour = input_sec / 3600;
        input_sec -= hour * 3600;
        min = input_sec / 60;
        input_sec -= min * 60;
        sec = input_sec % 60;
    }
    else if (input_sec < 3600 && input_sec >= 60 )
    {
        hour = 0;
        min = input_sec / 60;
        input_sec -= min * 60;
        sec = input_sec % 60;
    }
    else
    {
        hour = 0;
        min = 0;
        sec = input_sec % 60;
    }
    
    if (str[0] == 'A' && str[1] == 'M')
    {
        input_hour += hour;
        input_min += min;
        input_sec_1 += sec;
        if (input_sec_1 >= 60)
        {
            input_min += 1;
            input_sec_1 -= 60;
        }
        if (input_min >= 60)
        {
            input_hour += 1;
            input_min -= 60;
        }
        if (input_hour > 11)
        {
            printf("PM %02d:%02d:%02d",input_hour,input_min,input_sec_1);
        }
        else
        {
            printf("AM %02d:%02d:%02d",input_hour,input_min,input_sec_1);
        }
    }
    else
    {  
        input_hour += hour;
        input_min += min;
        input_sec_1 += sec;
        if (input_sec_1 >= 60)
        {
            input_min += 1;
            input_sec_1 -= 60;
        }
        if (input_min >= 60)
        {
            input_hour += 1;
            input_min -= 60;
        }
        if (input_hour > 11)
        {
            printf("AM %02d:%02d:%02d",input_hour,input_min,input_sec_1);
        }
        else
        {
            printf("PM %02d:%02d:%02d",input_hour,input_min,input_sec_1);
        }
        
    }

    system("pause");
    return 0;
}