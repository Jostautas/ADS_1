#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack{
    int data;
    struct stack *ptr;
} *Top[3], *Temp;

void printInterface(int i){
    printf("This Is a program for creating and manipulating a stack of integers\n");
    printf("Press a coressponding number to interact with stack:\n");

    printf("0 - Create an empty stack / clear stack\n");
    printf("1 - Check if stack is empty\n");
    printf("2 - Check if stack is full\n");
    printf("3 - Push\n");
    printf("4 - Pop\n");
    printf("5 - Display\n");
    printf("6 - Show how many elements there is in the stack\n");
    printf("7 - Switch to stack 1\n");
    printf("8 - Switch to stack 2\n");
    printf("9 - Switch to stack 3\n");
    printf("10 - Help\n");
}

void deleteStack(int i){     // deletes stack form top to bottom
    if(Top[i] != NULL){
        while(Top[i] != NULL){
            Temp = Top[i];
            Top[i] = Top[i]->ptr;
            free(Temp);
        }
    }
    else{
        printf("The stack is already empty\n");
    }
}

void createStack(int i){
    if(Top[i] != NULL){    // if there are saved elements inside the stack
        printf("The stack is not empty, do you want to delete it? Press Y/N\n");
        char ch;
        if((scanf("%c", &ch) == 1) && (getchar() == '\n')){
            ch = tolower(ch);
            switch(ch){
                case 'y':
                    deleteStack(i);
                    if(Top[i] == NULL){
                        printf("Stack deleted successfully\n");
                    }
                    break;
                case 'n':
                    printf("The stack was not changed\n");
                    break;
                default:
                    printf("Incorrect input\n");
            }
        }
        else{
            printf("Incorrect input\n");
        }
    }
    else{
        printf("The stack is already empty\n");
    }
}

void checkIfEmpty(int i){        // if the top element does not exist, the stack is empty
    if(Top[i] == NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
}

void checkIfFull(int i){         // tries to allocate memory for an element - if it is allocated successfully, the stack is not full.
    Temp = (struct stack *) malloc(sizeof(struct stack));
    if(Temp == NULL){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
    free(Temp);
}

void push(int i){
    printf("Enter an integer\n");
    int input;
    if((scanf("%d", &input) == 1) && (getchar() == '\n')){
        if(Top[i] == NULL){    // if stack is empty, create first element
            Top[i] = (struct stack *) malloc(sizeof(struct stack));
            Top[i]->data = input;
            Top[i]->ptr = NULL;
        }
        else{               // if stack is not empty
            Temp = (struct stack *) malloc(sizeof(struct stack));
            Temp->data = input;
            Temp->ptr = Top[i];
            Top[i] = Temp;
        }
    }
}

int pop(int i){
    int x = 0;
    if (Top[i] != NULL){   // if stack is not empty, take the  value and delete it from stack
        x = Top[i]->data;
        Temp = Top[i];
        Top[i] = Top[i]->ptr;
        free(Temp);
        printf("Popped value is %d\n", x);
    }
    else{
        printf("The stack is empty, nothing to pop\n");
    }
    return x;
}

void display(int i){
    printf("The stack from top to bottom is:");
    if(Top[i] != NULL){
        Temp = Top[i];
        while(Temp != NULL){
            printf(" %d", Temp->data);
            Temp = Temp->ptr;
        }
        printf("\n");
    }
    else{
        printf(" The stack is empty\n");
    }
    
}

void howMany(int i){
    if(Top[i] == NULL){
        printf("There are 0 elements in the stack\n");
    }
    else{
        int n = 0;
        Temp = Top[i];
        while(Temp != NULL){
            ++n;
            Temp = Temp->ptr;
        }
        printf("There are %d elements in the stack\n", n);

    }
}