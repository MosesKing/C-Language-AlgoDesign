/********************************************************
 *
 *  Name: Moesaeah King
 *
 *  ID: 16150318
 *
 *  Description: Pre Lab for Lab 11
 *  ****************************************************/
// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototypes
int load_data(char*, char*, char*, int x);
int checkAccountNumber(char* int x);

// main program
int main(int argc, char** argv) {

    if(argc != 3){
	print("Insufficent Arguments");
    }
    int n = atoi(argv[2]);
    char *acn = malloc(n * sizeof(char*));
    char *pwd = malloc(n * sizeof(char*));
    int i, d;
    i = 0; 
    for(i = 0; i < atoi(argv[2]); i++)
    {
	names[i] = malloc( (n + 1) * sizeof(char));
    }
    // calling check 
    int size = load_data( argv[1], acn, pwd);
    if(size == 0)
	printf("\n Unable to open the input file \n");
	return 0;
    }
}

int load_data(char* filename, char* acn, char* pwd, int size){
    FILE *cfptr = fopen(fname, "r");
    if( (cfptr) == NULL){
	return 0;
    }
    int i = 0;
    for( i = 0; i < (size - 1); i++){
	fscanf(cfptr, "%s %s ", *(acn + i), *(pwd + i));
    }
    fclose(cfptr);
    return 1;
}

int checkAccountNumber(char* a, int size){
    int i;
    for(i = 0; i < (size - 1); i++){
	
