#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int randomise(int value);
void delay(int seconds);
int slots(int money, int flc);
int guess(int money, int flc);
typedef struct _player {
  char name[20];
  int difficulty;
  int money;
  int day;
  int strength;
  int reserve;
  int energy;
  int tonic;
  int flc;
  int hourglass;
  int bobblehead;
  int luckMeter;
  int complete;
} Player;

void delay(int seconds){
  int c = 1, d = 1;

  for ( c = 1 ; c <= 8000*seconds ; c++ )
  for ( d = 1 ; d <= 8000*seconds ; d++ )
  {}

}
int rollDice(int value){
    srand(time(NULL));
    int result;
    result = 1 + rand()%value;
    printf("%d\n", result);
    return result;
}

int randomise(int value){
    srand(time(NULL));
    int result;
        result = 1 + rand()%value;
    return result;
}
int slots(int money, int flc){
  int bet;
  while(1==1){
    printf("Do you wish to continue?(Y/N)\n");
    char reply[3];
    scanf("%s", reply);
    if(reply[0] == 'n' || reply[0] == 'N'){
      return money;
    }
    printf("You have $%d. How much do you want to bet?\n", money);
    scanf("%d", &bet);
    if(bet > money){
      printf("not enough funds\n");
    }else{
      money = money - bet;
      int reels[3];
      int counter = 0;
      while(counter < 3){
        printf("type anything to spin next reel");
        char thing[200];
        scanf("%s", thing);
        int reel = randomise(5);
        if(counter == 0){
          printf("The FIRST reel rolled:");
        }else if(counter == 1){
          printf("The SECOND reel rolled:");
        }else{
          printf("The THIRD reel rolled:");
        }
        delay(1);
        if(counter == 2){
          delay(1);
        }
        if(reel == 1){
          printf("LEMON");
          reels[counter] = 1;
        }else if(reel == 2){
          printf("APPLE");
          reels[counter] = 2;
        }else if(reel == 3){
          printf("PEAR");
          reels[counter] = 3;
        }else if(reel == 4){
          printf("CHERRY");
          reels[counter] = 4;
        }else{
          printf("PINEAPPLE");
          reels[counter] = 5;
        }
        printf("\n");
        counter++;
      }
      counter = 0;
      if(reels[0] == reels[1] && reels[1] == reels[2]){
        printf("JACKPOT, You've won %d!\n", reels[0]*bet*2);
        money = money + reels[0]*bet*2;
      }else if(reels[0] == reels[1] || reels[0] == reels[2]){
        if(bet%2 == 1){
          bet++;
        }
        printf("MINOR PRIZE, You've won %d!\n", reels[0]*bet/2);
        money = money + reels[0]*bet/2;
      }else if(reels[1] == reels[2]){
        if(bet%2 == 1){
          bet++;
        }
        printf("MINOR PRIZE, You've won %d!\n", reels[1]*bet/2);
        money = money + reels[1]*bet/2;
      }else{
        printf("Sorry nothing came up. :(\n");
      }
    }
  }
  return money;
}
int guess(int money, int flc){
  int answer;
  printf("I'm thinking of a number between 0-99 \nIf you get within 30 of the number you get 2 times your bet.\n");
  printf("If you get within 10 of the number you get 3 times your bet\n");
  printf("If you get right on the number, you get 10 times your bet\n");
  while(1 == 1){
    printf("Do you wish to continue?(Y/N)");
    char response[3];
    scanf("%s", response);
    if(response[0] == 'n' || response[0] == 'N'){
      return money;
    }
    int bet;
    printf("You have %d. How much do you want to bet?", money);
    scanf("%d", &bet);
    if(bet > money){
      printf("You dont have that much money");
    }else{
      money = money - bet;
      printf("Ok let's begin\n");
      printf("hmm\n");
      delay(1);
      printf("Ok I got a number\n");
      answer = randomise(99);
      printf("What's your guess?\n");
      int guess;
      scanf("%d", &guess);
      if(guess == answer){
        printf("WOWZERS, that was exactly the number I was thinking of.\n");
        printf("Here's %d! Congratulations!\n", bet*10);
        money = money + bet*10;
      }else if(guess >= (answer - 10) && guess <= (answer + 10)){
        printf("You were very close, my number was %d\n", answer);
        printf("Here's %d!\n", bet*3);
        money = money + bet*3;
      }else if(guess >= (answer - 30) && guess <= (answer + 30)){
        printf("You were pretty close, my number was %d\n", answer);
        printf("Here's %d!\n", bet*2);
        money = money + bet*2;
      }else{
        printf("You were nowhere near, my number was %d\n", answer);
        printf("Sorry you didn't win anything\n");
      }
    }
  }

  return money;
}


