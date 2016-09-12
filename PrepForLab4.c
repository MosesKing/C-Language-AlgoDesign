#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_option()
{
    printf("Please select an operation\n");
    printf("1 : Cube\n");
    printf("2 : Division\n");
}

int check_option(int)
{
    int choice;
	while(choice < 1 || choice > 2){
	    return 0;
	}
	while(choice = 1 || choice = 2){
	    return 1;
	}
}
int generate_number(void)
{
    int x;
    x = rand() % 10;
    return x;
}
int cube (int x)
{
    return(x*x*x);
}

int division (int x, int y)
{
    int biggernumber;
    int smallernumber;
    if (x > y){
	biggernumber = x;
	smallernumber = y;
    }
    if (y > x){
	biggernumber = y;
	smallernumber = x;
    }
    return (biggernumber / smallernumber);
}
int main(void)
{

    srand(time(NULL));
    int x,y;
    x = generate_number();
    display_option();

return 0;

}
