#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int ch, popped; // user choice, most recently popped value from stack

    printf("Press a coressponding number to interact with stack:\n");

    while(1){
        printInterface();
        if((scanf("%d", &ch) && (getchar() == '\n')) == 1){
            switch(ch){
                case 1:
                    createStack();
                    break;
                case 2:
                    checkIfEmpty();
                    break;
                case 3:
                    checkIfFull();
                    break;
                case 4:
                    push();
                    break;
                case 5:
                    popped = pop();
                    break;
                case 6:
                    display();
                    break;
                case 7:
                    howMany();
                    break;
                default:
                    printf("Enter a correct number\n");
            }
        }
        else{
            printf("Enter a correct number\n");
            while(getchar() != '\n');
        }
        
    }
    return 0;
}