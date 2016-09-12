/*************************************************************
*
* Name: Moesaeah King
*
* Student ID: 16150318
*
* Description: Lucky 7
*
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// functions prototype's //
void display_option();
int check_guess(int guess);
int throw_dice();
int lucky_seven(int sum, int guess);
// calling the main functions to begin the program //
int main(void){
    srand(time(NULL));
    int guess;
    int sum;
    int seeifyouwin = throw_dice();
// variables above //

    display_option();
    printf("Please select an option: ");
    scanf("%d", &guess);
    check_guess(guess);

return 0;
}
void display_option()
{
    printf("Enter your guess (1) Lucky 7 (2) Above 7 (3) Below 7\n");
}
int check_guess(int guess)
{
    if(guess < 1 || guess > 3){
	printf("invalid choice");
	return 0;
    }
    if(guess == 1 || guess == 2 || guess == 3){
	return 1;
    }
}

int throw_dice()
{
    int die1 = 1 + (rand() % 6); //pick random die1 value
    int die2 = 1 + (rand() % 6); //pick random die2 value

    // display results //

    return die1 + die2;
}
int lucky_seven(int sum, int guess)
{

    switch (guess){
	case 1:
	    guess = 7;
	    break;
	case 2:
	    guess > 7;
	    break;
	case 3:
	    guess < 7;
	    break;
    }
  if(check_guess(guess) != /*seeifyouwi*/){
	printf("You lost your guess is incorrect the dices sum is %d"/*,&seeifyouwin*/);
	return 0;
 }
 if(check_guess(guess) == /*seeifyouwin*/){
    printf("You Won your guess the correct the dices sum is %d",/*seeifyouwin*/);
	return 1;
}
return 0;
}
