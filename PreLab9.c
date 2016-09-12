/********************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Pre-Lab for Lab 9 
 * *****************************************/
// libraries // 
#include <stdio.h>
#include <stdlib.h>
// prototypes //
int length( char *s);
char *copy(char *s);
char *reverse(char *s);
void clear(char *s);
// let's start the program! //
int main(void)
{
    char *s;
    s = int



}

// defining our functions from above //
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
    char *rvs = malloc(length(s) *(sizeof char));
    int i = 0, j = 0;
    for(i = length(s) - 1; i >= 0; i--){
	*(rvs + j) = *(s + i);
	j++;
    }
 return rvs;
}


char *copy(char *s){
    char *cpy;
    int i;

    for( i = 0; i < length(s); i++){
    *cpy == (s + i);
    }
    return cpy;
}


void clear( char *s){
    free(s);
}

