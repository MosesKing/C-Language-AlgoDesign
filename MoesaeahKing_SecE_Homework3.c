/*************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Homework Assignment #3
 * **********************************************/
//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototypes 
int load_data(char*, char**, int*, float*, int);
void print_data(char**, int*,float*, int);
int check_account(char**, int*,char*,int, int);
int string_compare(char*, char*);
int highest_amount(float*, int);
int lowest_amount(float*, int);
float average_amount(float*, int);
void write_data(char*, char**, int*, float*,int,int,int,float);
// our main program
int main(int argc, char** argv) {
    
    
    if(argc != 4){
	printf("Insufficent Arguments");
    } 
    //setting our variables to the things located in the arguments 
    int *id = malloc(atoi(argv[2]) * sizeof(int));
    float *amount = malloc(atoi(argv[2]) * sizeof(float));
    int n = atoi(argv[2]); 
    char **names = malloc(atoi(argv[2]) * sizeof(char*)); 
    char *targetname = malloc(atoi(argv[2]) * sizeof(char*));
    int i, d;
    i = 0;
    for(i = 0; i < atoi(argv[2]); i++)
    {
	names[i] = malloc(atoi(argv[2])+1 * sizeof(char));
    }
    // calling check
    int size = load_data(argv[1], names, id, amount, n);
    if(size == 0){
	printf("\n Unable to open the input file \n");
	return 0;
    }
    print_data(names, id, amount, n);

    printf("\n Enter a name: ");
    scanf("%s", targetname);
    
    printf("\n Enter a account number: ");
    scanf("%d",&d);

   if(check_account(names, id, targetname, d, n) == -1){
       printf("Unable to find account\n");
    }
    int high = highest_amount(amount,7);
    int low = lowest_amount(amount,7);
    float average = average_amount(amount,7);
    print_data(names, id, amount, size);
    printf("\n %s, has the highest amount $%.2f in the account number %d \n",*(names + high), *(amount + high), *(id + high));
    printf("\n %s has the lowest amount $%.2f in the account number %d \n", *(names + low), *(amount + low), *(id + low));
    printf("\n The average amount is $%.2f in the account number \n", average);
    printf("\n");
    printf("Do you want to: \n"); 
    printf(" 1.  Withdraw \n");
    printf(" 2. Deposit  \n ");
    int choice;
    scanf("%d", &choice);
    printf("\nEnter the amount: ");
    int wd;
    scanf("%d", &wd);
    if(choice == 1){
	(*(amount - i) -= wd);
	if( wd > *(amount + i)){
	    printf("Not Enough Funds\n");
	}
    }
    if(choice == 2){
	(*(amount + i) +=  wd);
    }

    write_data(targetname, names, id, amount, 7, high, low, average);
    free(amount);
    free(names);
    free(targetname);
    free(id);
    return 0; 
}
int load_data(char* fname, char** names, int* id, float* amount, int size)/*this function will open the file -> if unable return 0 /--> otherwise will load the account information from text file*/{
    FILE *cfptr = fopen(fname, "r");
    if( (cfptr) == NULL){
	return 0;
    }
    int i = 0;
    for(i = 0; i< size; i++){
	fscanf(cfptr, "%s %d %f", *(names + i), &(*(id + i)), &(*(amount + i)));
    }
    fclose(cfptr);
    return 1;
}
void print_data(char** names, int* id, float* amount, int size){
    int i; 

    for( i = 0; i < size; i++){
	printf("%s %d %.2f\n", *(names + i),*(id + i), *(amount+ i));
    }
    
}

int highest_amount(float* amount, int size)/* function takes the float pointer and number of accounts, if finds highest amount and returns the index correspoinding to the highest number*/{
    int i=0;
    float largest;
    int max_index = 0;
    largest = *(amount + 0);
    for(i = 0; i < size; i++){
	if(*(amount+i) > largest){
	    largest = *(amount+i);
	    max_index = i;
	}
    }
    return max_index;
}
int lowest_amount(float* amount, int size)/* function takes the float pointer and number of accounts, if it finds lowest amount => returns the indez corresponding to the lowest number*/{
    int i=0;
    float smallest;
    int min_index = 0;
    smallest = *(amount + 0);
    for(i = 0; i < size; i++){
	if(*(amount+i) < smallest){
	    smallest = *(amount + i);
	    min_index = i;
	}
    }
    return min_index;
}
float average_amount(float *amount, int size)/* function takes the float pointer and number of accounts, if it summing them all up => returning the average for all the accounts*/{
    int i=0;
    float average;
    int sum = 0;
    for(i = 0; i < size; i++){
	sum += *(amount+i);
    }
    average = (float)sum / size;
    return average;
}


void write_data(char* fname, char** names, int* id, float* amount, int size, int high, int low, float average)/* this function writes the account information(name, account numbers, and amounts), the highest, the lowest and the average amount information into a text */{
    FILE *cfptr = fopen(fname, "w");
    int i = 0; 
    for(i = 0; i< size; i++){
	fprintf(cfptr, "%s %d  %.2f", *(names + i), *(id +i), *(amount +i));
	fprintf(cfptr, "the highest amount %.2f in the account number %d", *(amount + i), *(id + i));
	fprintf(cfptr, "the lowest amount %.2f in the account number %d", *(amount + i), *(id + i));
	fprintf(cfptr, "The average amount is %.2f", average);
    }
    fclose(cfptr);
}
int check_account( char** names, int *id, char* targetname, int tar, int size)/* searches for the given account number and name and if it finds then return the index of the name and account number otherwise returns -1 */{
    int i;
    for(i = 0; i < size; i++){
	if(string_compare(targetname, *(names + i)) && *(id + i) == tar)
	{
	    return i;
	}

    }
    return -1;

}
int string_compare(char* s1, char* s2){
    
    while(*s1 != '\0'){
	if(*s1 != *s2){
	    return 0;
	}
    s1++;
    s2++;
    }
    return 1;
}
