#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack{
    int data;
    struct stack *ptr;
} *Top, *Temp;

void printInterface(){
    printf("1 To create an empty stack / clear stack\n");
    printf("2 To cheack if stack is empty\n");
    printf("3 To check if stack is full\n");
    printf("4 To push (integer)\n");
    printf("5 To pop\n");
    printf("6 To display\n");
    printf("7 To show how many elements there is in the stack\n");
}

void deleteStack(){     // deletes tack form top to bottom
    if(Top != NULL){
        while(Top != NULL){
            Temp = Top;
            Top = Top->ptr;
            free(Temp);
        }
    }
    else{
        printf("The stack is already empty\n");
    }
}

void createStack(){
    if(Top != NULL){    // if there are saved elements inside the stack
        printf("The stack is not empty, do you want to delete it? Press Y/N\n");
        char ch;
        if((scanf("%c", &ch) == 1) && (getchar() == '\n')){
            ch = tolower(ch);
            switch(ch){
                case 'y':
                    deleteStack();
                    if(Top == NULL){
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

void checkIfEmpty(){        // if the top element does not exist, the stack is empty
    if(Top == NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
}

void checkIfFull(){         // tries to allocate memory for an element - if it is allocated successfully, the stack is not full.
    Temp = (struct stack *) malloc(sizeof(struct stack));
    if(Temp == NULL){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
    free(Temp);
}

void push(){
    printf("Enter an integer\n");
    int input;
    if((scanf("%d", &input) && (getchar() == '\n')) == 1){
        if(Top == NULL){    // if stack is empty, create first element
            Top = (struct stack *) malloc(sizeof(struct stack));
            Top->data = input;
            Top->ptr = NULL;
        }
        else{               // if stack is not empty
            Temp = (struct stack *) malloc(sizeof(struct stack));
            Temp->data = input;
            Temp->ptr = Top;
            Top = Temp;
        }
    }
}

int pop(){
    int x = 0;
    if (Top != NULL){   // if stack is not empty, take the top value and delete it from stack
        x = Top->data;
        Temp = Top;
        Top = Top->ptr;
        free(Temp);
        printf("Popped value is %d\n", x);
    }
    else{
        printf("The stack is empty, nothing to pop\n");
    }
    return x;
}

void display(){
    printf("The stack from top to bottom is:");
    if(Top != NULL){
        Temp = Top;
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

void howMany(){
    if(Top == NULL){
        printf("There are 0 elements in the stack\n");
    }
    else{
        int n = 0;
        Temp = Top;
        while(Temp != NULL){
            ++n;
            Temp = Temp->ptr;
        }
        printf("There are %d elements in the stack\n", n);

    }
}