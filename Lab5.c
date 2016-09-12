#include<stdio.h>
#include<stdlib.h>

int lucky_seven(int, int);

void make_guess();

int throw_dice();

int check_guess(int );



int main()
{
    int num;

    int choice;


    int h=0;
    make_guess();

    printf("\n Guess is %d \n", h);

    printf("\nPlease select a option: ");
    scanf("%d", &choice);
    while(check_guess(choice)==0)
    {

	printf("\nInvalid choice");
	make_guess();
	printf("\nPlease select a option: ");
	scanf("%d", &choice);
    }


    num = throw_dice();
    printf("The sum of the thrown dice is %d",num);

    if(lucky_seven(num, choice)== 1)
    {
	printf("\nYou win your guess is correct the dices sum is %d \n",  num);
    }

    else
    {
	printf("\nYou lost your guess is incorrect the dices sum is %d \n", num);


    }

    return 0;
}

int check_guess(int x)
{

    if(x<1 || x>3)
	return 0;
    else
	return 1;

}

void make_guess()
{

    printf("\nEnter your guess (1) Lucky 7 (2) above 7 (3) below 7: ");

}


int lucky_seven(int x, int option)
{

    switch(option){


	case 1:

	    if(x == 7)
		return 1;
	    else
		return 0;
	    break;



	case 2:

	    if(x>7)
		return 1;
	    else
		return 0;
	    break;

	case 3:

	    if(x<7)
		return 1;
	    else
		return 0;
	    break;

	default:
	    return 0;
	}


}



int throw_dice()
{

    int x=1+rand()%6;

    int y=1+rand()%6;

    return(x+y);
}
