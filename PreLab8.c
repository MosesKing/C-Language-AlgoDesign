/****************************************************
 *
 * Name: Moesaeah King 
 *
 * ID: 16150318 
 *
 * Description: Pre-Lab for Lab 8
 * ************************************************/

// libraries //
#include <stdio.h>
#include <stdlib.h>

// prototypes!  // 

int length(char s[]);

int replace(char s[], int i);

// main program now begins // 

int main(void){
    char s[25];
    int replacementplace;
    printf("Enter a string: ");
    scanf("%s", s);
    printf("\nInput string is %s", s);
    printf("\n");
    printf("Length of string is %d", length(s));
    printf("\n");
    printf("Enter a position for the replacement operation: ");
    scanf("%d", replacementplace);
    while(replace(s,replacementplace) == 0){
	printf("Invalid, You need to enter a number within the length given above try again: ");
	scanf("%d", replacementplace);
    }

    printf("\n String after replacement operation is %d", replace(s, replacementplace));
    printf("\n");



    
    return 0;
}

int length(char s[]){
   int i = 0; 
    while(s[i] != '\0'){
	i++;

    }
    return i;
}

int replace(char s[], int i){
    if(i < 0 || i > length(s)){
    return 0;
    }
    s[i] = '#';
    return 1;
}

