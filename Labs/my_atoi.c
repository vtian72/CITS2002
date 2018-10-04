//Writing our own atoi function to convert a string into an int
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int my_atoi(char string[]){
    int i = 0;
    int result = 0;
    bool negative = false;

    if(string[i] == '-'){
      negative = true;
      i++;
    }
    while(string[i] != '\0'){
      result = result * 10 + (string[i] - '0');
      i++;
    }
    if(negative){
      return -result;
    }
    else{
      return result;
    }
}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
      printf("String conversion of %s is %i \n", argv[i], my_atoi(argv[i]));
    }
}
