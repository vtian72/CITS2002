#include <stdio.h>
#include <stdlib.h>

int my_strlen(char word[]){
    int len = 0;
    int i = 0;
    while(word[i] != '\0'){
        len++;
        i++;
    }
    return len;
}
int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "NOT ENOUGH INPUTS!");
        exit(EXIT_FAILURE);
    }
    else{
        for(int i = 1; i < argc; i++){
            printf("Length of %s is %i\n", argv[i], my_strlen(argv[i]));
        }
        exit(EXIT_SUCCESS);
    }
}
