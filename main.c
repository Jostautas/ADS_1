// ADT stekas, Jostautas Sakas

#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    int ch, popped, currentStack = 0, limit = 3, temp, numOfStacks = 1; // user choice,   most recently popped value from stack,  number of the current stack

    init(&limit, &numOfStacks);

    while(1){
        printInterface();
        if((scanf("%d", &ch) && (getchar() == '\n')) == 1){
            switch(ch){
                case 1:
                    createStack(currentStack);
                    break;
                case 2:
                    checkIfEmpty(currentStack);
                    break;
                case 3:
                    checkIfFull(currentStack, limit);
                    break;
                case 4:
                    push(currentStack, limit);
                    break;
                case 5:
                    popped = pop(currentStack);
                    break;
                case 6:
                    display(currentStack);
                    break;
                case 7:
                    howMany(currentStack);
                    break;
                case 8:
                    temp = 0;
                    checkIfExists(numOfStacks, temp, &currentStack);
                    break;
                case 9:
                    temp = 1;
                    checkIfExists(numOfStacks, temp, &currentStack);
                    break;
                case 10:
                    temp = 2;
                    checkIfExists(numOfStacks, temp, &currentStack);
                    break;
                case 11:
                    temp = 3;
                    checkIfExists(numOfStacks, temp, &currentStack);
                    break;
                case 12:
                    temp = 4;
                    checkIfExists(numOfStacks, temp, &currentStack);
                    break;
                case 13:
                    printInterface();
                    break;
                case 14:
                    printf("The limit is %d elements\n", limit);
                    break;
                case 15:
                    printf("Enter the new limit\n");
                    temp = getInt();
                    if(temp != -1){
                        limit = temp;
                        printf("The new limit is %d\n", limit);
                    }
                    else{
                        printf("Wrong input. Enter an int above 0\n");
                    }
                    break;
                case 16:
                    printf("Enter a number of stacks, between 1 and 5\n");
                    temp = getInt();
                    if(temp > 0 && temp <= 5){
                        if(numOfStacks > temp){
                            delOldStacks(temp);
                        }
                        numOfStacks = temp;
                        printf("The are now %d stacks\n", numOfStacks);
                    }
                    else{
                        printf("Wrong input. Enter an int above 0\n");
                    }
                    break;
                case 17:
                    printf("There are %d stack(s)\n", numOfStacks);
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