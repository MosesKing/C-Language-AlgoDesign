/****************************************************************
 *
 * Name: Moesaeah King
 *
 * ID: 16150318
 *
 * Description: Lab for Lab10
 *
 * *************************************************************/
// libraries
#include <stdio.h>
#include <stdlib.h>
//prototypes//

// let's begin the main program
int main(int argc, char** argv) {
    if(argc != 6){
	printf("Insuffient Arguments");
    }
    char letter;
    int x, x1, x2;
    x = atoi(argv[3]);
    x1 = atoi(argv[4]);
    x2 = atoi(argv[5]);
    float average = (x + x1 + x2) / 3.00;
    if(average >= 90){
	letter = 'A';
    }
    else if (average < 90 && average > 80){
	letter = 'B';
    }
    else if
	(average < 80 && average >= 70){
	    letter = 'C';
	}
    else if
	(average < 70 && average >= 60){
	    letter = 'D';
	}
    else if
	(average < 50){
	    letter = 'F';
	}

    printf("The total score for student %s %s id is %.2f and the overall grade is %c in the course\n", argv[1], argv[2], average, letter);
    return 0;
}
