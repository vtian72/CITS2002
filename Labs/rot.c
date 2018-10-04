#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define initial_rotate 13

// Compile this program with:
//      cc -std=c99 -Wall -Werror -pedantic -o rot rot.c

//  The rotate function returns the character ROT positions further along the
//  alphabetic character sequence from c, or c if c is not lower-case

char rotate(char c, int rotate_by)
{
  // Check if c is lower-case or not
  if (islower(c))
  {
    // The ciphered character is ROT positions beyond c,
    // allowing for wrap-around
    return ('a' + (c - 'a' + rotate_by) % 26);
  }
  else if(isupper(c))
  {
    return ('A' + (c - 'A' + rotate_by) % 26);
  }

  return c;
}

//function to check if an input string is an integer
bool isNumber(char *test){
  int length = strlen(test);
  for(int i = 0; i < length; i++ ){
    if(isdigit(test[i]) == false){
    }
  }
  return true;
}
//  Execution of the whole program begins at the main function

int main(int argc, char *argv[])
{
  // Exit with an error if the number of arguments (including
  // the name of the executable) is not precisely 2
  if(argc <= 1)
  {
    fprintf(stderr, "%s: program expected at 1 argument, but instead received %d\n", argv[0], argc-1);
    exit(EXIT_FAILURE);
  }
  else
  {
    int rotation = initial_rotate;
    for(int a = 1; a < argc; a++){
      // Calculate the length of each argument
      if(isNumber(argv[a])){
        rotation = atoi(argv[a]);
        continue;
      }
      int length = strlen(argv[a]);
      // Loop for every character in the text
      for(int i = 0; i < length; i++)
      {
        // Determine and print the ciphered character
        char ch = argv[a][i];
        printf("%c %c %d\n", rotate(ch, rotation), ch, i);
      }
      // Print one final new-line character
      printf("\n");
    }
    // Exit indicating success
    exit(EXIT_SUCCESS);
  }
  return 0;
}
