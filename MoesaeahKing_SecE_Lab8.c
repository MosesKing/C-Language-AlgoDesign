/*****************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Lab 8 for CS1050
 * *************************************************/

#include <stdio.h>
#include <stdlib.h>

// prototypes
int length(char s[]);
int replace(char s[], int i);
void copy(char s[], char s2[]);
void merge( char s[], char s1[], char s2[]);

int main(void)
{
    char s[100];
    char s1[100];
    char s2[100];
    int replacementplace;
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("\n Length of string is %d", length (s));
    printf("\n Copy of first string is %s", s);
    printf("\nEnter a position for the replacement operation: ");
    scanf("%d", &replacementplace);
    while(replace(s, replacementplace) == 0){
	printf("Invalid, You need to enter a number with the length given above try again: ");
	scanf("%d", &replacementplace);
    }
    replace(s,replacementplace);
    printf("\nString afer replament operation is %s",s );
    printf("\n");
    printf("\nEnter second string: ");
    scanf("%s", s1);
    printf("\n Second string is %s", s1);
    copy(s,s2);
    merge( s, s1, s2);
    printf("\n Merged string is %s", s2);
    printf("\n");



    return 0;
}
// defining functions
int length( char s[])
{
    int i = 0;
    while(s[i] != '\0'){
	i++;
    }
    return i;
}
int replace(char s[], int i)
{
    if(i < 0 || i > length(s)){
	return 0;
    }
    s[i-1] = '#';
    return 1;
}
void copy( char s[], char s2[])
{
    int i;
    for( i = 0; i < length(s); i++){
	s2[i] = s[i];
    }
    i++;
    s2[i] = '\0';

}
void merge( char s[], char s1[], char s2[])
{
    int i = 0, d = 0;
    while(s[i] != '\0'){
	s2[d] = s[i];
	//d++ + '\0';
	i++;
	d++;
    }
    i=0;
    while(s1[i] != '\0'){
	s2[d] = s1[i];
	//d++ + '\0';
	i++;
	d++;
    }
	s2[d] = '\0';

}
