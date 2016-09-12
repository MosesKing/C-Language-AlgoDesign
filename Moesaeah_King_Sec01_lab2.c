//MOESAAEAH KING'S PROGRAM FOR LAB2 CS1050 -- This program will perform and give information about the integers that a user will put in!
#include <stdio.h>

int main(void) {
	int integer1;
	int integer2;
		printf("Enter the first number: ");
		scanf("%d", &integer1);
 		printf("Enter the second number: ");
		scanf("%d",&integer2);

	// now to perform our simple arithmetic //
	int sum;
	sum = integer1 + integer2;
		printf("The sum of %d and %d is %d\n", integer1, integer2,  sum);

	int multipulcation;
		multipulcation = integer1 * integer2;
		printf("The product of %d and %d  is %d\n",integer1, integer2, multipulcation);
	int divisiontheotherway;
		divisiontheotherway = integer2 / integer1;
// didn't know what you were really meaning about how to get the division to be the other way around, so i thought for me this would be easier aha help?!//
	int division;
		division =  integer1 / integer2;
	int remainder;
		remainder = integer1 % integer2;
	int remaindertheotherway = integer2 % integer1;

		printf("For %d divided by %d quotient is %d and a remainder is %d\n", integer1, integer2, division, remainder);
		printf("For %d divided by %d quotient is %d and a remainder is %d\n", integer2, integer1, divisiontheotherway, remaindertheotherway);
	int remainderofinteger1;
	int remainderofinteger2;
		remainderofinteger1 = integer1 % 2;
		remainderofinteger2 = integer2 % 2;
	// gunna make the program now tell me information about the inputted integers //
	if (integer1 > integer2){
		printf("%d is the bigger number\n",integer1);
	}
	if (integer2 > integer1){
		printf("%d is the bigger number\n", integer2);
	}
	if (remainderofinteger1 == 1){
		printf("%d is an odd number\n", integer2);
	}
	else{
		printf("%d is an even number\n", integer1);
	}
	if (remainderofinteger2 == 1){
		printf("%d is an odd number\n", integer2);
	}
	else {
		printf("%d is a even number\n", integer2);
	}
	return 0;

}
