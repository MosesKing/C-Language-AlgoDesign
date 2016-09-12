/************************************************************
 *
 * Name: Moesaeah King
 *
 * Student ID: 16150318
 *
 * Description: Calculating the Compound Interest for Three Different Bank Accounts
 * *********************************************************/
#include <stdio.h>
#include <stdlib.h>
void display_option();
int check_option(int x);
int check_year(int x);
int check_amount(float x);
float compute_power(float x, int y);

int main(void)
{
// variables!! //
    float interestearned;
    float interest;
    float newamount;

//formulas//


    display_option();
    int choice;
    printf("Please make a selection: ");
    scanf("%d", &choice);
    while(check_option(choice) == 0){
	printf("Incorrect Choice, Please select from the menu:\n");
	display_option();
	scanf("%d", &choice);
    }
    switch (choice){

	case 1:
	    interest = .01;
	    break;
	case 2:
	    interest = .03;
	    break;
	case 3:
	    interest = .07;
	    break;
	default:
	    interest = 0;
    }

    printf("\nEnter a year:");
    int year;
    scanf("%d", &year);
    while(check_year(year) == 0){
	printf("Incorrect Valoe of year, enter the a Year value between 1-10: ");
	scanf("%d", &year);
    }

    printf("\nEnter the amount:");
    float amount;
    scanf("%f", &amount);
    while(check_amount(amount)== 0){
	printf("Incorrect amount, please enter a value above zero: ");
	scanf("%f",&amount);
    }
    float piece;
    piece = (1 + (interest));
    newamount = (amount * (compute_power(piece, year)));
    interestearned = newamount - amount;
    printf("\nTotal amount after %d years is $%.2f", year, newamount);
    printf("\nTotal Interest earned on the amount $%.2f is $%.2f", amount, interestearned);
    printf("\n");






 return 0;
}


void display_option(){
    printf("Bank Account Type\n");
    printf("\n");
    printf("(1) : Checking\n");
    printf("(2) : Saving\n");
    printf("(3) : Fixed Deposit\n");
    printf("\n");
}

int check_option(choice){
    if(choice < 1 || choice > 3){
	return 0;
    }
    return 1;
}

int check_year(year){
    if(year < 1 || year > 10){
	return 0;
    }
    return 1;
}

int check_amount(float amount){
    if(amount <= 0){
	return 0;
    }
    return 1;
}

float compute_power(float base, int exponent){
   int i;
   float y = 1;
   if(exponent == 0){
       return 1;
    }
   else if(exponent == 1){
       return base;
    }
   else if(exponent == 2){
       return (base * base);
    }
   else{
       y = base;
       for(i = 1; i < exponent; i++){
	   y = y * base;
       }
   }
   return (y);


}
