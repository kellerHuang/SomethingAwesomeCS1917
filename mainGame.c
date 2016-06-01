#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "city.h"
#include "help.h"
#include "mainGame.h"
Player gym(Player player);
Player home(Player player);
Player shop(Player player);
Player gamesHouse(Player player);
Player door(Player player);
/*Actions:
0. Help
1. Home
2. Gym
3. Shop
4. Gameshouse
5. Door
6. Stats
7. Invent
*/
int checkTrue(char *string);
int checkAction(char *action);
void printMan(void);
Player introduction(Player player);
int main(void){
    char input[20];
    Player player;
    player.reserve = 0;
    player.complete = 0;
    player = introduction(player);
    int action = 0;
    player.day = 1;
    while(input[0] != 'q'){
      if(player.complete == 0){
        printCity();
        if(player.name[0] == 'g' && player.name[1] == '\0'){

  player.money = 9999;
  player.strength = 500;
  player.energy = 9000;
  player.tonic = 100;
  player.flc = 100;
  player.hourglass = 100;
  player.bobblehead = 100;
        }
        printf("It is day %d. Where do you wish to go?(type h for help)\n", player.day);
        scanf("%s", input);
        action = checkAction(input);
        if(action == 0){
          giveHelp();
        }else if(action == 1){
          player = home(player);
        }else if(action == 2){
          player = gym(player);
        }else if(action == 3){
          player = shop(player);
        }else if(action == 4){
          player = gamesHouse(player);
        }else if(action == 5){
          player = door(player);
        }else if(action == 6){
          printf("\nSTATS\nSTRENGTH: %d\nMONEY: %d", player.strength, player.money);
        }else if(action == 7){
          printf("\nINV\nTONIC: %d\nFOUR LEAF CLOVERS: %d\nHOURGLASSES: %d\nBOBBLEHEADS: %d\n", player.tonic, player.flc, player.hourglass, player.bobblehead);
        }else if(action == 8){
          printf("A mysterious voice echoes...");
          delay(2);
          printf("echoes...\n");
          delay(2);
          printf("No secret here, try again.\n");
        }
        delay(2);
      }else{
        printRuins();
        printMan();
        printf("You see this?\n");
        printf("This is another dimension\n");
        delay(1);
        printf("One that you were living in before\n");
        printf("This is what you have done\n");
        delay(1);
        printf("I hoped that by living in the safety of another world you would forget this one\n");
        printf("But instead, you have now brought this upon yourself\n");
        delay(1);
        printf("Goodbye...");
        printRuins();
        return 0;
      }
    }
    return 0;
}
void printMan(void){
  printf("  O  \n");
  printf(" /|\\ \n");
  printf(" / \\ \n");
}

Player introduction(Player player){
  char difficulty[20];
  printMan();
  printf("Hi there, I see you're new to this world. Now what's your name?\n");
  scanf("%s", player.name);
  printf("%s is it? Well that's a nice name. But of course not as nice as mine ;).\n", player.name);
  printf("Now what difficulty do you want? (Easy, Medium, Hard)\n");
  scanf("%s", difficulty);
  printf("Oh %s difficulty?", difficulty);
  delay(1);
  printf("\n...");
  delay(1);
  printf("\nWe dont have that difficulty right now, but we can do VERY HARD if you want?\n");
  delay(2);
  printf("So what do you think? The expression on your face doesn't give away much.");

  printf("Is that a yes or a no?\n");
  scanf("%s", difficulty);
  int trueOrFalse = 0;
  trueOrFalse = checkTrue(difficulty);
  while(trueOrFalse == 3){
    printf("I couldn't quite get that. Say again? (Yes/No)\n");
    scanf("%s", difficulty);
    trueOrFalse = checkTrue(difficulty);
  }
  if(trueOrFalse == 1){
    printf("Well very hard it shall be!\n");
    player.difficulty = 1;
  }else{
    printf("Fine, we'll go with a little bit hard instead\n");
    player.difficulty = 0;
  }
  player.day = 1;
  player.strength = 1;
  player.reserve = 0;
  player.energy = 100;
  player.tonic = 0;
  player.flc = 0;
  player.hourglass = 0;
  player.bobblehead = 0;
  player.luckMeter = 0;
  player.money = 0;
  delay(2);
  printf("Now here's your small town of Vernal\n");
  delay(2);
  printf("But you should know the place right? You live here!\n");
  delay(2);
  printCity();
  printf("I expect you know this place like the back of your hand,\n but i'll leave you to explore. Have fun! Bye!\n");
  delay(2);
  printf("Oh, and here's $20 for you to get you on your way\n");
  player.money = player.money + 20;
  delay(2);
  return player;
}
int checkTrue(char *string){
 int trueOrFalse = 0;
 if(string[0] == 'y' && string[1] == 'e' && string[2] == 's'){
   trueOrFalse = 1;
 }else if(string[0] == 'Y' && string[1] == 'e' && string[2] == 's'){
   trueOrFalse = 1;
 }else if(string[0] == 'N' && string[1] == 'o'){
   trueOrFalse = 0;
 }else if(string[0] == 'n' && string[1] == 'o'){
   trueOrFalse = 0;
 }else{
   trueOrFalse = 3;
 }
 return trueOrFalse;
}
int checkAction(char *action){
  int actionCode = 0;
  if(action[0] == 'h' && action[1] == '\0'){
    actionCode = 0;
  }else if(action[0] == 'H' && action[1] == 'O' && action[2] == 'M'
  && action[3] == 'E' && action[4] == '\0'){
    actionCode = 1;
  }else if(action[0] == 'G' && action[1] == 'Y' && action[2] == 'M'
  && action[3] == '\0'){
    actionCode = 2;
  }else if(action[0] == 'S' && action[1] == 'H' && action[2] == 'O'
  && action[3] == 'P' && action[4] == '\0'){
    actionCode = 3;
  }else if(action[0] == 'G' && action[1] == 'A' && action[2] == 'M'
  && action[3] == 'E' && action[4] == 'S'){
    actionCode = 4;
  }else if(action[0] == 'D' && action[1] == 'O' && action[2] == 'O'
  && action[3] == 'R' && action[4] == '\0'){
    actionCode = 5;
  }else if(action[0] == 'S' && action[1] == 'T' && action[2] == 'A'
  && action[3] == 'T' && action[4] == 'S'){
    actionCode = 6;
  }else if(action[0] == 'I' && action[1] == 'N' && action[2] == 'V'
  && action[3] == '\0'){
    actionCode = 7;
  }else{
    actionCode = 8;
  }
  return actionCode;
}
Player home(Player player){
  printf("You're home now.\n");
  delay(2);
  char action[20];
  printf("Do you want to SLEEP or check SAVINGS?\n");
  scanf("%s", action);
  if(action[0] == 'S' && action[1] == 'L'){
    printf("Goodnight\n");
    delay(2);
    printf("...");
    delay(2);
    player.day++;
    player.luckMeter = 0;
    printf("One day has passed.. It is day %d\n", player.day);
    player.energy = 100;
    player.reserve = player.reserve*randomise(3);
  }else if(action[0] == 'S' && action[1] == 'A'){
    printf("\nA magical box that multiplies your money\n");
    printf("There's $%d in it\nYou have $%d on you.\n", player.reserve, player.money);
    printf("Would you like to make a DEPOSIT or WITHDRAWL?\n");
    scanf("%s", action);
    int transfer = 0;
    if(action[0] == 'D' && action[1] == 'E'){
      printf("how much would you like to deposit?(between 0-%d)\n", player.money);
      scanf("%d", &transfer);
      if(transfer <= player.money){
        player.money = player.money-transfer;
        player.reserve = player.reserve+transfer;
      }else{
        printf("ERROR, nice try\n");
      }
    }else if(action[0] == 'W' && action[1] == 'I'){
      printf("How much would you like to withdraw?(between 0-%d)\n", player.reserve);
      scanf("%d", &transfer);
      if(transfer <= player.reserve){
        player.reserve = player.reserve - transfer;
        player.money = player.money+transfer;
      }else{
        printf("ERROR, nice try\n");
      }
    }
  }else{
    printf("Only one of the two are allowed currently\n");
  }
  return player;
}
Player gym(Player player){
  printMan();
  printf("Yo, you looking to work out the EASY way? \n Or maybe train the HARD way?");
  char response[20];
  scanf("%s", response);
  if(response[0] == 'E'){
    printf("Alright the EASY way it is\n");
    delay(1);
    printf("As a wise guy once said, Time = Money\n");
    printf("I'm just here to convert all that money you got back into time\n");
    printf("So its $5 for one Strength\n");
    printf("All Strength gain is instant\n");
    printf("Sound simple enough?\n");
    delay(3);
    printf("So how much do you want?");
    int purchase = 0;
    scanf("%d", &purchase);
    int tonic = 0;
    if(player.tonic > 0){
      printf("Do you want to use your tonic?(Y/N)\n");
      char reply[3];
      scanf("%s", reply);
      if(reply[0] == 'Y' || reply[0] == 'y'){
        printf("Alright drink up!");
        tonic++;
        player.tonic = player.tonic - 1;
      }
    }
    if(purchase*5 <= player.money){
      player.money = player.money - purchase*5;
      player.strength = player.strength + purchase;
      if(tonic == 1){
        player.strength = player.strength + purchase;
      }
      printf("Consider it done\n");
    }else{
      printf("Buddy, mate, not enough money\nCan't turn your money back into time at the gym if you got no money.\n");
    }
  }else if(response[0] == 'H'){
    printf("Well the hard way it is\n");
    printf("I can't guarantee any results, but I guarantee it'll take your energy (energy -50)\n");
    printf("Do you wish to continue?(Y/N)");
    char response;
    scanf("%s", &response);
    if(response == 'Y' || response == 'y'){
      if(player.energy >= 50){
        printf("Well here we go.\n");
        printf("Hocus pocus\n");
        delay(1);
        printf("um\n");
        delay(1);
        int increase = randomise(5);
        printf("There we go, your strength went up by %d\n", increase);
        player.strength = player.strength + increase;
      }else{
        printf("You are too tired for this");
      }
    }else{
      printf("Well come back if you change your mind!");
    }
    delay(2);
  }
  return player;
}
Player shop(Player player){
  printMan();
  printf("Hi there, hehe, have we met?\n");
  printf("Anyways, what do you want here?\n");
  printf("Do you want to WORK or BUY?\n");
  char response[20];
  scanf("%s", response);
  if(response[0] == 'W'){
    printf("This will take all of your energy.");
    printf("Are you sure?(Y/N)\n");
    char responses[3];
    scanf("%s", responses);
    if(responses[0] == 'Y'){
      if(player.energy > 0 && player.energy < 100){
        printf("You're not fully energised, but you do your best anyway!");
        printf("Energy - player.energy");
        player.money = player.money + player.energy;
        player.energy = 0;
      }else if(player.energy == 100){
        printf("You're fully energised, you do your best!");
        player.money = player.money + 120;
        player.energy = 0;
      }else{
        printf("You are too tired to do this");
      }
    }else{
      printf("Well come back if you change your mind!");
    }
  }else if(response[0] == 'B'){
    printf("Here's our items:\n");
    printf("1.Tonic - Increases your strength for today           ($100)\n");
    printf("2.Four Leaf Clover - LUCKY!!!!!!                      ($30)\n");
    printf("3.Hourglass - There's a famous quote inscribed on it. ($150)\n");
    printf("4.Knife - Looks like it could cut anything            ($200)\n");
    printf("5.Bobblehead - This looks exactly like the shopkeeper ($80)\n");
    printf("6.Quit.                                               ($400)\n\n");
    printf("So what do you want kid? Just the number will be fine.\n");
    int reply;
    scanf("%d", &reply);
    if(reply == 1){
      if(player.money >= 100){
        printf("Here you go!\n");
        player.tonic++;
        player.money = player.money - 100;
      }else{
        printf("not enough money");
      }
    }else if(reply == 2){
      if(player.money >= 30){
        printf("Here you go!\n");
        player.flc++;
        player.money = player.money - 30;
      }else{
        printf("not enough money");
      }
    }else if(reply == 3){
       if(player.money >= 150){
        printf("Here you go!\n");
        player.hourglass++;
        player.money = player.money - 150;
      }else{
        printf("not enough money");
      }
    }else if(reply == 4){
      if(player.money >= 200){
        printf("Here you go!\n");
        delay(1);
        printf("(As he brings the knife to you, you realise it's about the size of your pinkie)\n");
        delay(1);
        printf("(He puts it in your hand)\n");
        delay(1);
        printf("(It's actually smaller than your pinkie)\n");
        delay(1);
        printf("hmm, actually this knife has too much sentimental value\n");
        printf("you can have your money back\nThis knife is very time sensitive.\n");
      }else{
        printf("not enough money");
      }
    }else if(reply == 5){
      if(player.money >= 80){
        printf("Here you go!");
        player.bobblehead++;
        player.money = player.money - 80;
      }else{
        printf("not enough money");
      }

    }else if(reply == 6){
      printf("That'll be $400 please\n");
      delay(1);
      printf("Oh...\n");
      printf("That was the option for gamebreaking armour before\n");
      printf("Oh well see you later!\n");
    }
  }
  delay(2);
  return player;
}
Player gamesHouse(Player player){
  if(player.luckMeter == 0){
    printf("You found a 100 dollar note under the rug\n");
    delay(1);
    printf("Now that you pulled it out you realised it was only half a 100 dollar note.\n");
    printf("You pocketed the half note(Gained $50)\n");
    player.money = player.money + 50;
    player.luckMeter++;
    delay(1);
    if(player.flc > 0){
      printf("A four leaf clover shines in your pocket\n");
      printf("You lift up the whole rug and find another half of a 100 dollar note\n");
      delay(1);
      printf("...\n");
      delay(1);
      printf("It's the same half.");
      printf("You pocketed the other half note(Gained $50)");
      player.money = player.money + 50;
    }
  }
  printf("\n\n   (o  o)    \n");
  printf("   \\[  ]/     \n");
  printf("    /  \\  \n");
  printf("\n");
  printf("Ehh Hi there\n");
  printf("You want to TALK or GAME?");
  char response[20];
  scanf("%s", response);
  if(response[0] == 'T'){
    printf("Hmm you want to talk\n");
    delay(1);
    printf("I've been thinking..\n");
    delay(1);
    printf("I went to the park yesterday and all I saw was this one person\n");
    printf("here, I even took a photo.\n");
    delay(1);
    printf("\n\n");
    printf("    (o  o)    o    \n");
    printf("    \\[  ]/   /|\\  \n");
    printf("     /  \\    / \\\n");
    printf("\n");
    delay(1);
    printf("hahaha, I could even do this thing called a faceswap\n");
    printf("Look");
    delay(1);
    printf("\n\n");
    printf("      o     (o  o)    \n");
    printf("    \\[  ]/   /|\\  \n");
    printf("     /  \\    / \\\n");
    printf("\n");
    delay(1);
    printf("Havent met any other people around though..");

  }else if(response[0] == 'G'){
    printf("ALRIGHT\n");
    printf("GAME ON\n");
    printf("We have SLOTS and GUESSing game, which do you wanna play?\n");
    char reply[20];
    scanf("%s", reply);
    if(reply[0] == 'S'){
      player.money = slots(player.money, player.flc);
    }else if(reply[0] == 'G'){
      player.money = guess(player.money, player.flc);
    }else{
      printf("Aww, guess you dont wanna play");
    }
  }
  return player;
}
Player door(Player player){
  printf("A door sits on the grass");
  delay(1);
  if(player.strength < 20){
    printf("The door is sealed shut you can't open it\n");
    printf("Do you even lift?");
    delay(1);
    return player;
  }
  printf("You open the door..");
  printMan();
  printf("Hi, remember me?\nYou thought I was just another shopkeeper\nOr another gym trainer\nOr another kind face for this town\n");
  printf("I can't let you pass through this door\n");
  delay(1);
  printf("It goes somewhere, where I cannot let you see\n");
  printf("You've managed to open my door, but getting through it is another story\n");
  delay(1);
  printf("EN GARDE");
  delay(1);
  int hourglassEffect = 0;
  int flcEffect = 0;
  int bobbleheadEffect = 0;
  int manHealth = 500+70*player.day;
  int playerHealth = player.strength*40;
  int defenseEffect = 0;
  while(1==1){
    if(hourglassEffect == 0){
      printf("       \n\n\n");
      printf("      HP: %d      \n", manHealth);
      printf("         o \n");
      printf("        /|\\___    \n");
      printf("        / \\     \n");
      printf("            \n");
      printf("            \n");
      printf("It's the man,\n He's holding a knife almost double his size\n");
    }else{
      printf("\n\n\n");
      printf("      HP: %d            \n", manHealth);
      printf("         o \n");
      printf("        /|\\.    \n");
      printf("        / \\     \n");
      printf("            \n");
      printf("            \n");
      printf("It's the man,\n He's holding a knife almost 1cm long\n");
    }
    int actionTaken = 0;
    printf("You have %d Health\nWhat do you want to do?(USE, ATTACK, DEFEND, RUN)\n", playerHealth);
    char action[20];
    scanf("%s", action);
    if(action[0] == 'U'){
      printf("What do you want to use?");
      printf("\nINV\nTONIC(T): %d\nFOUR LEAF CLOVERS(FLC): %d\nHOURGLASSES(H): %d\nBOBBLEHEADS(B): %d\n", player.tonic, player.flc, player.hourglass, player.bobblehead);
      scanf("%s", action);
      if(action[0] == 'T'){
        if(player.tonic > 0){
          printf("You drink the tonic\n");
          printf("You are ready to make gains\n");
          printf("Drinking the tonic made you slightly stronger\n");
          printf("Health increased by 100!");
          delay(1);
          playerHealth = playerHealth + 100;
          actionTaken++;
        }else{
          printf("You drink the tonic that you don't have!\n");
          delay(1);
          printf("Unsurprisingly nothing happened...");
        }
      }else if(action[0] == 'F'){
        if(player.flc > 0){
          printf("You took out your four leaf clover\n");
          delay(1);
          printf("It evaporated\n");
          printf("You feel empowered");
          flcEffect++;
          actionTaken++;
          player.flc = player.flc - 1;
        }else{
          printf("You're out of four leaf clovers\n");
          delay(1);
          printf("You get a three leaf clover off the ground and rip a leaf in half\n");
          printf("It just isn't the same...\n");
        }
      }else if(action[0] == 'H'){
        if(player.hourglass > 0){
          printf("You finally read it's inscription\n");
          int quote = randomise(5);
          printf("It reads:");
          if(quote == 1){
            printf("The sky is blue");
          }else if(quote == 2){
            printf("Selfies are cool");
          }else if(quote == 3){
            printf("Maths is hard");
          }else if(quote == 4){
            printf("Fire is hot");
          }else{
            printf("Flowers are pretty");
          }
          printf("You aren't very inspired\n");
          printf("The man seems bothered with how bad the quote was\n");
          printf("It was so bad that 2 hours seem to have passed");
          hourglassEffect = hourglassEffect + 3;
          actionTaken++;
        }else{
          printf("You tried to read an inspirational quote off the hourglass\n");
          printf("There was no inspirational quote.\n");
          delay(1);
          printf("There was no hourglass either.\n");
        }
      }else if(action[0] == 'B'){
        if(player.bobblehead > 0){
          printf("You take the bobblehead out of your pocket\n");
          delay(1);
          printf("The man seems impressed at how good he looks on the bobblehead\n");
          printf("He decides to go easy on you\n");
          if(manHealth > 1000){
            if(manHealth%2 == 1){
              manHealth = manHealth + 1;
            }
            manHealth = manHealth/2;
          }
          bobbleheadEffect = bobbleheadEffect + 2;
          actionTaken++;
        }else{
          printf("There is no bobbling or heads to be had");
        }
      }else{
        printf("That is not a valid action\n");
      }
    }else if(action[0] == 'A'){
      printf("You swing at the man\n");
      int damageP = player.strength*10;
      if(flcEffect > 0){
        printf("You feel the power of luck\n");
        flcEffect = flcEffect - 1;
        damageP = damageP*3;
      }
      printf("You deal %d damage!", damageP);
      if(manHealth > damageP){
        manHealth = manHealth - damageP;
      }else{
        manHealth = 0;
      }
      actionTaken++;
    }else if(action[0] == 'D'){
      printf("You attempt to defend his oncoming attack\n");
      defenseEffect++;
      actionTaken++;
    }else if(action[0] == 'R'){
      printf("AHAHAHAHAHAHAHA, RUN YOU FOOL, THIS IS JUST A TASTE OF MY POWER\n");
      return player;
    }
    if(bobbleheadEffect > 0){
      printf("The man is so proud of his bobblehead that he accidentally stabs himself\n");
      if(manHealth > 50){
        manHealth = manHealth - 50;
      }else{
        manHealth = 0;
      }
      bobbleheadEffect = bobbleheadEffect - 1;
    }
    if(manHealth == 0){
      printf("ARRRRGGGHGHHHHH\n");
      printf("You really want to see what lies behind this door?\n");
      delay(1);
      printf("THEN SO BE IT\n");
      player.complete = 1;
      return player;
    }
    delay(1);
    if(actionTaken > 0){
      printf("MY TURN NOW\n");
      printf("TAKE THIS\n");
      int damage = 20+player.day*10;
      if(hourglassEffect > 0){
        printf("He hits you with his tiny sword\nIt tickles\n");
        damage = 1;
        hourglassEffect = hourglassEffect - 1;
        if(hourglassEffect == 0){
          printf("Both you and the man seems to have recovered from how bad the quote was");
        }
      }
      if(defenseEffect > 0){
        if(damage > 1){
          int chance = randomise(2);
          if(chance == 1){
            printf("You only managed to block half his attack\n");
            damage = damage/2;
          }else{
            printf("You managed to block his attack\n");
            damage = 0;
          }
        }else{
          printf("You tried to block the small amount of damage\n");
          printf("You blocked so much you somehow gained health\n");
          printf("You gained 100 health");
          damage = 0;
          playerHealth = playerHealth + 100;
        }
      }
      printf("(You take %d damage)\n", damage);
      if(damage >= playerHealth){
        printf("You fainted...\n");
        printf("You took one day to rest\n");
        printf("Maybe you should've taken some bobbleheads to make him go easy on you");
        printf(" or maybe some hourglasses to mess with time.");
        player.day++;
        return player;
      }else{
        playerHealth = playerHealth - damage;
      }
    }
  }
  return player;
}

