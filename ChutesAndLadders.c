/* CS 153 PROGRAM ASSIGNMENT #7

Program that makes a chutes and ladders game
for a single user. If the user gets to the end 
of the game they win!

Mark Schuberth 
 
10/29/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* this generates a random number between 1-6 */
int randInt()
{
    return rand() % 6 + 1;
}

/* rolls a random dice roll */
int randRoll(int *roll)
{
 *roll = randInt();
}

int main()
{
 /* used to initiate rand() */
 srand(time(NULL));
 
 int i, position = 0, roll = 0, count = 0;
 int board[101];
 
 /*  */
 for(i = 0; i < sizeof(board)/sizeof(board[0]); i++)
    board[i] = 0;

 /*  creates 9 ladders in the array */
 /*  position is updated to integer in array */
  board[1] = 38;
  board[4] = 14;
  board[9] = 31;
  board[28] = 84;
  board[21] = 42;
  board[36] = 44;
  board[51] = 67;
  board[80] = 100;
  board[71] = 91;
    
 /*  creates 10 chutes in the array */
 /*  position is updated to integer in array */
  board[16] = 6;
  board[49] = 11;
  board[47] = 26;
  board[62] = 19;
  board[87] = 24;
  board[64] = 60;
  board[56] = 53;
  board[93] = 73;
  board[95] = 75;
  board[98] = 78;
    
 /* prompts user about the start of the program */
 printf("Let's play some Chutes and Ladders!\n");
 
 /* main loop that runs until position is 100 or above */
 while(position <= 100)
 {
  printf("Press 'enter' to roll the dice, good luck!\n");
  fgetc(stdin);
  randRoll(&roll);
  count++;
  printf("Your dice roll was: %d\n", roll);
  
  /* if the position is higher than 100 reroll! */
  if(position + roll > 100)
  {
    printf("Oh no! Your position is greater than 100, reroll!");
  }
  else
  {
	/* adds roll to new position */
    position += roll;

    printf("You advance to square: %d\n", position);
  
   /* if the board position holds 0 program continues to roll */
    if(board[position] == 0)
    {
     fgetc(stdin);
    }
    else
    {
     /* land on a chute */
      if (position > board[position])
      {
       position = board[position];
       printf("\nOh no! you land on a chute \n your new position is: %d\n", position);
       fgetc(stdin);
      }
     /* land on a ladder */
      else
      {
       position = board[position];
       printf("\nGreat! You land on a \n ladder your new position is: %d\n", position);
       fgetc(stdin);  
      }
    }
  }
  /* if position is equal to 100 then we are done! */
  /* the user wins! */
  if(position == 100)
   {
    printf("\nCongratulations you've won!");
    printf("\nYou reached the goal in %d moves!", count);
    exit(EXIT_SUCCESS);
   }
 }
 
 
 
 return 0;
}