#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


bool isLeapYear(int year){
    if(year % 400 == 0){
        return true;
    }
    if(year % 4 == 0){
        if(year % 100 == 0){
            return false;
        }
        return true;
    }
    return false;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "INVALID NUMBER OF ARGUMENTS, YOU NEED AT LEAST 1!\n");
        exit(EXIT_FAILURE);
    }
    else{
        for(int i = 1; i < argc; i++){
            char *check;
            int year = atoi(argv[i]);
            if(isLeapYear(year)){
                check = "true";
            }
            else{
                check = "false";
            }
            printf("%i is a leap year - %s \n", year, check);
        }
        exit(EXIT_SUCCESS);
    }

}
