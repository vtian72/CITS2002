#include <stdlib.h>
#include <stdio.h>

void a(){
    printf("**********\n");
}

void b(){
    for(int i = 0; i < 10; i++){
        printf("*\n");
    }
}

void c(){
    for(int i = 0; i < 10; i++){
        printf("*****\n");
    }
}

void d(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void e(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i; j++){
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++){
            printf("*");
        }
        printf("\n");
    }
}

void f(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i; j++){
            printf("*");
        }
        printf("\n");
    }
}

void g(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i; j++){
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++){
            printf("*");
        }
        for(int l = 0; l < i; l++){
            printf("*");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "INVALID NUMBER OF INPUTS, YOU ONLY NEED 1 INPUT, YOU HAVE %i", argc - 1);
    }
    char *part = argv[1];
    switch(*part){
        case 'a':
            a();
            break;
        case 'b':
            b();
            break;
        case 'c':
            c();
            break;
        case 'd':
            d();
            break;
        case 'e':
            e();
            break;
        case 'f':
            f();
            break;
        case 'g':
            g();
            break;
        default:
            fprintf(stderr, "INVALID INPUT, ONLY a, b or c allowed!\n");
            exit(EXIT_FAILURE);
    }
}
