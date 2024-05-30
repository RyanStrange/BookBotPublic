#include <stdio.h>
#include <string.h>
#include  <time.h>
#include <unistd.h>
#include <stdlib.h>

//ONLY START THE PROGRAM ON A WEEKEND

int main() {
   
    // 1 = Monday
    // 2 = Tuesday
    // 3 = Wednesday
    // 4 = Thursday
    // 5 = Friday

    char command[70];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
   
    int testDay = tm.tm_wday;
    int currentDay;

    // initial loop, will run so long as time on the system does not satisfy the if statement within the block.
    while (1) {

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        int hour = tm.tm_hour;
        int seconds = tm.tm_sec;
        int minute = tm.tm_min;

        printf("Current hour : %02d\n", hour);
        // if the hour equals midnight and the seconds is greater than 0, the statement is true and loop will break.
        if (hour == 0 && minute == 0 && seconds > 0) {
            printf("Lets-A-GO!!\n\n");
            break;
        }

        sleep(1);
    }

    //infinite loop, never breaks.
    while (1) {

        //lines 35 - 36 re-declares the value of time to the current time
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        //initialising variables for time
        currentDay = tm.tm_wday;
        printf("Current day : %02d\n", currentDay);
        int hour = tm.tm_hour;;

        int month = tm.tm_mon;
        int seconds = tm.tm_sec;


        //check to make sure the day has changed
        if (testDay != currentDay) {

            //check to see if the current day is Monday
            if (currentDay == 1) {

                // open Monday script
                strcpy(command, "PowerShell -File C:..\test.ps1");
                system(command);

                //if true, re-declare current day
                testDay = currentDay;
            }
            //check to see if the current day is Tuesday
            if (currentDay == 2) {

                //open Tuesday script
                strcpy(command, "PowerShell -File C:..\test.ps1");
                system(command);

                //if true, re-declare current day
                testDay = currentDay;
            }
            //check to see if the current day is Wednesday
            if (currentDay == 3) {

                //open Wednesday script
                strcpy(command, "PowerShell -File C:..\test.ps1");
                system(command);

                //if true, re-declare current day
                testDay = currentDay;
            }
            //check to see if the current day is Thursday
            if (currentDay == 4) {

                //open Thursday script
                strcpy(command, "PowerShell -File C:..\test.ps1");
                system(command);

                //if true, re-declare current day
                testDay = currentDay;
            }
            //check to see if the current day is Friday
            if (currentDay == 5) {

                //open Friday script
                strcpy(command, "PowerShell -File C:..\test.ps1");
                system(command);

                //if true, re-declare current day
                testDay = currentDay;
            }

        }



        //print time to terminal for review
        printf("\nCurrent month day hour & seconds is : %02d %02d %02d %02d", month, currentDay, hour, seconds);

        //for every iteration of the while loop, will sleep for 24 hours before iterating again
        sleep(86400);
    }






