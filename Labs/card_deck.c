#include <stdlib.h>
#include <stdio.h>

#define NSUITS        4
#define NVALUES       13
#define NCARDS        (NSUITS * NVALUES)

void print_cards(int cards[]){
  for(int i = 0; i < NCARDS; i++){
    int suit = cards[i] % NSUITS;
    int value = cards[i] % NVALUES;

    char suits[NSUITS] = "HDCS";
    if(value == 0){
      printf("A%c ", suits[suit]);
    }
    else if(value >=1 && value <= 9){
      printf("%i%c", value + 1, suits[suit]);
    }
    else{
      char royals[] = "JQK";
      printf("%c%c", royals[value - 10], suits[suit]);
    }
    printf("\n");
  }
  printf("\n");
}

void shuffle_cards(int cards[]){
  int nleft = NCARDS;
  while(nleft > 0){
    int choose = rand() % nleft; //swap the chosen card and the last card to shuffle deck
    int save = cards[nleft-1];
    cards[nleft - 1] = cards[choose];
    cards[choose] = save;
    nleft--;
  }
}

int main(int argc, char *argv[]){
    int cards[NCARDS];

    for(int i = 0; i < NCARDS; i++){
        cards[i] = i;
    }
    print_cards(cards);

    for(int i = 0; i < 3; i++){
      shuffle_cards(cards);
      print_cards(cards);
    }
}
