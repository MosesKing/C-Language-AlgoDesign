/************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Lab 9 w/ Pointers use.
 ***********************************************/
// libraries //
#include <stdio.h>
#include <stdlib.h>
// prototypes //

int length(char *s); //returns length of the string
char* copy(char *s); // will copy te function of string into another
char* reverse(char *s); // reverse the contents
void clear(char *s); // free the memory that was allocated
int search(char *s, char c); // takes users input and searches the ptr
int prefix(char *s1, char *s2); // checks if the second string is a prefix of the first

// let's begin //
int main(void)
{
    printf("Enter first string: ");
    char *s = malloc(sizeof(char) * 100);
    scanf("%s", s);
    printf("Length is %d\n", length(s));

    char *copyS = copy(s);

    printf("Copy of the string is %s\n", copyS);

    char *reverseS = reverse(s);
    printf("Reverse of the string %s is %s\n", s, reverseS);

    printf("Enter a character for the search operation: ");
    char c = fgetc(stdin);
    scanf("%c", &c);
    search( s, c);
    if(search(s,c) == -1){
	printf("Character %c is not present in the string %s\n",c, s);
    }
    else{
	printf("Character %c is present in the string at the index %d in the string %s\n", c,search(s,c),s);
    }
    char *s1 = malloc(sizeof(char) * 100);
    printf("Enter a string for the prefix operation: ");
    scanf("%s", s1);

    printf("\n");
    char *s2 = malloc(sizeof(char) *100);
    printf("Enter a string to check for prefix: ");
    scanf("%s", s2);

    if(prefix(s1,s2) == 0){
	printf("%s is not a prefix of %s\n", s2, s1);
    }
    else{
	printf("%s is a prefix of the string %s\n", s2, s1);
    }

    // free storage
    clear(s);
    clear(copyS);
    clear(reverseS);
    clear(s1);
    clear(s2);

    return 0;
}
// define our functions //
int length(char *s){
    int i = 0;
    while( *s != '\0')
    {
	i++;
	s++;
    }
    return i;
}
char* reverse(char *s){
    char *rvs = malloc((length(s) +1) * sizeof(char));
    int i = 0, j =0;
    for( i = length(s) - 1; i >= 0; i--){
	*(rvs + j) = *(s + i);
	j++;
    }
    *(rvs + j) = '\0';
    return rvs;
}
char* copy(char *s){
    char *cpy = malloc((length(s) + 1) * sizeof(char));
    int i;


    for( i = 0; i < length(s); i++){
	*(cpy + i) = *(s + i);
    }
    *(cpy + i) = '\0';

    return cpy;
}
int search(char *s, char c){
    int i;
    for (i = 0; i < length(s); i++){
	if( c ==  *(s + i)){
	    return i;
	}
    }
    *(s + i) = '\0';
    return -1;
}
int prefix(char *s1, char *s2){
    int i;
    for(i = 0; i < length(s2); i++){
	if( *(s2 + i) != *(s1 + i)){
	    return 0;
	}
    }
	return 1;
}
void clear( char *s){
    free(s);
}
