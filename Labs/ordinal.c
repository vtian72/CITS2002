#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ordinal(int number){
    if(number % 100 == 11 || number % 100 == 12 || number % 100 == 13){
        printf("%i%s\n", number, "th");
    }
    else if(number % 10 == 1){
        printf("%i%s\n", number, "st");
    }
    else if(number % 10 == 2){
        printf("%i%s\n", number, "nd");
    }
    else if(number % 10 == 3){
        printf("%i%s\n", number, "rd");
    }
    else{
        printf("%i%s\n", number, "th");
    }
    return;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "NOT ENOUGH INPUTS!");
    }
    else{
        for(int i = 1; i < argc; i++){
            ordinal(atoi(argv[i]));
        }
    }
}
