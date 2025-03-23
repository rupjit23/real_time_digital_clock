#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
void get_time_for_24_Hour(char *store_time)
{
    time_t raw_time; //data type to store current time
    struct tm *current_time; // holds the data time components & pointer to holad formatted time
    time(&raw_time); // take the current time and stores it
    current_time=localtime(&raw_time); // convert the raw time into a string(human redable formet)
    strftime(store_time,100,"%H:%M:%S",current_time); // formet of how the time string will be printed
}
void get_time_for_12_Hour(char *store_time)
{
    time_t raw_time; //data type to store current time
    struct tm *current_time; // holds the data time components & pointer to holad formatted time
    time(&raw_time); // take the current time and stores it
    current_time=localtime(&raw_time); // convert the raw time into a string(human redable formet)
    strftime(store_time,100,"%I:%M:%S %p",current_time); // formet of how the time string will be printed
}
void get_Date(char *store_date)
{
    time_t raw_date; //data type to store current time
    struct tm *current_date; // holds the data time components & pointer to holad formatted time
    time(&raw_date); // take the current time and stores it
    current_date=localtime(&raw_date); // convert the raw time into a string(human redable formet)
    strftime(store_date,100,"%A %B %Y",current_date); // formet of how the time string will be printed
}
void clear_screen()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
int main()
{
    char time[100],date[100]; // stores the time in string formet
    int choice;
   printf("1: 12-Hour Formet\n");
    printf("2: 24-Hour Formet\n");
    printf("Please choice the time formet: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:while(1)
    {
        get_time_for_12_Hour(time);
            get_Date(date);
            clear_screen();
            printf("The Current Time is: %s",time);
            printf("\n");
            printf("The Current Day is %s\n",date);
            sleep(1);
    }
        /* for 12 Hour Formet */
       break;
    
    case 2: while(1){
        get_time_for_24_Hour(time);
            get_Date(date);
            clear_screen();
            printf("The Current Time is: %s",time);
            printf("\n");
            printf("The Current Day is %s\n",date);
            sleep(1);
    }
}
    return 0;
}
