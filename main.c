// ADT stekas, Jostautas Sakas

// padaryt kad butu 3 stekai, istrinti "To"

#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int ch, popped, currentStack = 0; // user choice,   most recently popped value from stack,  number of the current stack

    printInterface();

    while(1){
        if((scanf("%d", &ch) && (getchar() == '\n')) == 1){
            switch(ch){
                case 0:
                    createStack(currentStack);
                    break;
                case 1:
                    checkIfEmpty(currentStack);
                    break;
                case 2:
                    checkIfFull(currentStack);
                    break;
                case 3:
                    push(currentStack);
                    break;
                case 4:
                    popped = pop(currentStack);
                    break;
                case 5:
                    display(currentStack);
                    break;
                case 6:
                    howMany(currentStack);
                    break;
                case 7:
                    currentStack = 0;
                    printf("Switched to stack 1\n");
                    break;
                case 8:
                    currentStack = 1;
                    printf("Switched to stack 2\n");
                    break;
                case 9:
                    currentStack = 2;
                    printf("Switched to stack 3\n");
                    break;
                case 10:
                    printInterface();
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