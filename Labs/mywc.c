#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//method to find the number of lines, number of characters and words in a file
void counter(FILE *fp){

    int nlines = 0;
    int nchars = 0;
    int nwords = 0;

    char line[BUFSIZ];

    while(fgets(line, sizeof line, fp) != NULL){
        bool inside_word = false;
        char *s = line;

        printf("%s\n", line);

        nlines++;

        while(*s != '\0'){
            nchars++;
            //if we are inside_word is true and there is white space then we must be outside of the word
            //as inside_word was previously true
            if(inside_word && isspace(*s)){ //isspace() checks if it is a white space
                inside_word = false;
            }
            //if inside_word is false and there is white space, then it must be a word
            //as inside_word was previously false
            else if(!inside_word && !isspace(*s)){

                nwords++;
                inside_word = true;
            }
            s++;
        }
      }
    printf("Number of lines is %i\n", nlines);
    printf("Number of chars is %i\n", nchars);
    printf("Number of words is %i\n", nwords);
    exit(EXIT_SUCCESS);

  }



int main(int argc, char *argv[]){
    if(argc == 2){
       FILE *fp = fopen(argv[1], "r");

       if(fp == NULL){
          fprintf(stderr, "cannot open %s \n", argv[1]);
          exit(EXIT_FAILURE);
       }
       else{
         counter(fp);
         fclose(fp);
         exit(EXIT_SUCCESS);
       }
    }
    else{
         counter(stdin);
         exit(EXIT_SUCCESS);
    }
}
