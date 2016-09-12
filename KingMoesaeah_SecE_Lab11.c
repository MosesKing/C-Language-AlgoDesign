/*****************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Lab 11
 * **************************************************/
// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//prototypes
int load_data(char*, char*,char*);
int checkAccountNumber(char*, int x);
int checkUpperLetter( char*);
int checkDigit(char*);
int checkPwdLength(char*, int x);
int checkSpecialChar(char*);
//main program
int main(int argc, char** argv){

    if (argc != 3){
	printf("Insufficent Arguments");
    }
    int n = atoi(*(argv + 2));
    char *acn = malloc(n * sizeof(char*));
    char *pwd = malloc(n * sizeof(char*));
    int size = load_data(*(argv + 1), acn, pwd);
    if(size == 0){
	printf("\n Unable to open the input file \n");
	return 0;
    }
    while( !checkAccountNumber(acn, n)){
	printf("Invalid Account Number\n");
	printf("Please Enter a Account Number with %d digit number: ", n);
	scanf("%s", acn);
    }
    while( !checkPwdLength(pwd, n)){
	printf("Invalid Password\n");
	printf("Please Enter a Password that is %d digits in length: ", n);
	scanf("%s", pwd);
    }
    while( !checkUpperLetter(pwd)){
	printf("There should be at least one upper case character in the password\n");
	printf("Enter the password again: ");
	scanf("%s", pwd);
    }
    while( !checkDigit(pwd)){
	printf("There should be at least one number in the password\n");
	printf("Enter the password again: ");
	scanf("%s", pwd);
    }
    while( !checkPwdLength(pwd, n)){
	printf("Invalid Password\n");
	printf("Please Enter a Password that is %d digits in length: ", n);
	scanf("%s", pwd);
    }
    while( !checkDigit(pwd)){
	printf("There should be at least one number in the password\n");
	printf("Enter the password again: ");
	scanf("%s", pwd);
    }

    while( !checkSpecialChar(pwd) ){
	printf("There should be at least one special character (i.e Punction Marks) in the password\n");
	printf("Enter the password again: ");
	scanf("%s", pwd);
    }
    while( !checkPwdLength(pwd, n)){
	printf("\nInvalid Password\n");
	printf("The password HAS to be %d  characters in length: ", n);
	scanf("%s", pwd);
    }
    while( !checkSpecialChar(pwd)){
	printf("\nThere should be at least one special character (i.e. Punctuation Marks) in the Password\n");
	printf("\nEnter the password again: ");
	scanf("%s", pwd);
    }

    printf("\nYour Account was successfully created!\n");
    printf("\n");
    printf("Account Number: %s\n", acn);
    printf("Password: %s\n", pwd);

    return 0;

}
//lets define our functions
int load_data(char* filename, char* acn, char* pwd){
    FILE *cfptr = fopen(filename, "r");
    if( (cfptr) == NULL){
	return 0;
    }
    while (!feof(cfptr)){
	fscanf(cfptr, "%s %s ", acn, pwd);
    }
    fclose(cfptr);
    return 1;
}
int checkAccountNumber(char* a, int x){
    int i;
    if(strlen(a) != x){
	return 0;
    }
    for(i = 0; *(a + i) != '\0'; i++){
	if( isdigit(*(a + i)) == 0){
	return 0;
	}
    }
    return 1; // account number was okay
}
int checkPwdLength(char* a, int x){
    int i;
    for(i = 0; *(a + i) != '\0'; i++);

    if (i == x) // password number was the proper length
	return 1;

    return 0;
}
int checkUpperLetter(char* a){
    int i;
    for(i = 0; *(a + i) != '\0'; i++){
	if(isupper( *(a + i)) != 0){
	    return 1;
	}
    }
    return 0;
}
int checkDigit(char* a){
    int i;
    for(i = 0; *(a + i) != '\0'; i++){
	if(isdigit( *(a + i)) != 0){
	    return 1;
	}
    }
    return 0;
}
int checkSpecialChar(char* a){
    int i;
    for(i = 0; *(a + i) != '\0'; i++){
	if(ispunct( *( a + i)) != 0){
	    return 1;
	}
    }
    return 0;
}
