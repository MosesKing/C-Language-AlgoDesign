/*********************************
* Name: Moesaeah King
	Pawprint: MKC42
	ID: 16150318

* Description: Lab 3
********************************/
#include <stdio.h>
#include <math.h>

//beginning program//
int main(void){

//variables will go in this area for the program to make it much easier to read//
int accounttype;
float amount;
float year;
float compoundinterest;
float interestearned;
float interest;

// end of the variable that'll be used for the following program//

printf("Bank Account Type\n");
printf("\n");
printf("(1) Checking\n");
printf("(2) Saving\n");
printf("(3) Fixed Deposit\n");
printf("\n");

// now we begin to ask for user input //
printf("Please make a selection: ");
scanf("%d", &accounttype);
// error checking the user's imput //
while( accounttype < 1 ||  accounttype > 3){
	printf("Incorrect Choice, please make a choice again: ");
	scanf("%d", &accounttype);
}
// cases for the inputted account type, we will now set the account type to their prospective interest rates //
switch (accounttype){

    case 1:
	accounttype == .01;
	break;
    case 2:
	accounttype == .03;
	break;
    case 3:
	accounttype == .07;
	break;
}
// now we will get user input for the amount  //
printf("\n");

printf("Please Enter the Amount: ");
scanf("%.02f", &amount);
// error checking the user's input //
while (amount <= 0){
    printf("We cannot calculate your compound interest with an outstanding balance( -$) or a balance of $0! Enter a New Valid Amount: ");
    scanf("%.02f", &amount);
}
// Here, we will ask for the user's input for the year//
printf("\n");
printf("Enter a Year: ");
scanf("%d", &year);
// error checking the amount for the year //
while (year < 1 || year > 10){
    printf("Incorrect value, year should be between 1-10! Please Re-Enter the Year:");
    scanf("%d", &year);
}
//formulas!!//
 compoundinterest = (amount * pow((1+(accounttype/100)),year));
 interestearned = compoundinterest - amount;
 //print final statements //

printf(" Total Amount after %d is $%.02f", &year, &compoundinterest);
printf("\n");
printf("Total Interest earned on the amount %.02f is %.02f", &amount, &interestearned);

return 0;
}
