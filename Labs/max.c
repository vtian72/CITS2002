#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int v1, char *val2){
    int v2 = atoi(val2);
    if(v1 < v2){
        return v2;
    }
    return v1;
}

int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "NOT ENOUGH ARGUMENTS, YOU NEED AT LEAST 2, YOU CURRENTLY HAVE %i\n", argc - 1);
        exit(EXIT_FAILURE);
    }
    else{
        int num = atoi(argv[1]);
        for(int i = 1; i < argc - 1; i++){
            num = max(num, argv[i + 1]);
        }
        printf("MAX of list is %i \n", num);
        exit(EXIT_SUCCESS);
    }
}
