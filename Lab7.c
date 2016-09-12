/*************************************************
 *
 * Name: Moesaeah King
 *
 * Student ID: 16150318
 *
 * Description Lab 7
 * *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//function prototypes //

int check_error(int x);
void intialize_array(int c[], int x);
void print_array(int c[], int x);
float average(int c[], int x);
int count_numbers( int c[], int x, int y);
int common_numbers( int c[], int d[], int x);

// our main program //
int main(void){
    srand(time(NULL));
    int c[100];
    int d[100];
    printf("Enter the size of the input: ");
    int check;
    scanf("%d", &check);
    while(check_error(check) == 0){
	printf("\nInvalid Input, enter the size of the input again: ");
	scanf("%d", &check);
    }
    printf("\n Input Array \n");
    intialize_array(c, check);
    intialize_array(d, check);
    printf("The first input of array: \n");
    print_array(c, check);
    printf("\n");
    printf("The second input array: \n");
    print_array(d, check);
    printf("\n");
    printf("The average of the first array is: %f",average( c, check));
    printf("\n");
    printf("The average of the second array is %f",average( d, check));
    printf("\n");

    printf("\n Enter a number: ");
    int value;
    scanf("%d", &value);
    printf("\n the count of %d in the first array is %d", value,count_numbers(c, 10, value));
    printf("\n the count of %d in the second array is %d", value, count_numbers(d, 10, value));
    printf("\n");
    printf("\nThe number of common numbers in the two arrays are %d", common_numbers(c,d, 10));
    printf("\n");
    return 0;


}

// defining functions //

int check_error(int check){
    if(check < 0 || check > 100){
	return 0;
    }
    return 1;
}
void intialize_array(int c[], int length){
    int i;
    for(i = 0; i < length; i++){
	c[i] = rand() % 10;
    }
}
void print_array( int c[], int length){
    int i;
    for(i = 0; i < length; i++){
	printf("%d ", c[i]);
    }
}
float average( int c[], int length){
    int i;
    float average;
    int sum = 0;
    for(i = 0; i < length; i++){
	sum += c[i];
    }

    average  = (float)sum / length;

    return average;
}
int count_numbers(int c[], int length, int value){
    int i;
    int count = 0;
    for(i = 0; i < length; i++){
	if ( c[i] == value){
	   ++count;
	}
    }
    return count;
}
int common_numbers(int c[], int d[], int length){
    int i;
    int a = 0;
    for(i = 0; i < length; i++){
	    if(c[i] == d[i]){
		a++;
	    }
	}
    return a;
}
