#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack{
    int data;
    struct stack *ptr;
} *Top, *Temp;

void print_interface(){
    printf("1 To create an empty stack / clear stack\n");
    printf("2 To cheack if stack is empty\n");
    printf("3 To check if stack is full\n");
    printf("4 To push (integer)\n");
    printf("5 To pop\n");
    printf("6 To display\n");
    printf("7 To clear\n");
}

void createStack(){
    if(Top != NULL){
        printf("The stack is not empty, do you want to delete it? Press Y/N\n");
        char ch;
        if(scanf("%c", &ch) == 1){
            ch = tolower(ch);
            switch(ch){
                case 'y':
                    printf("Deleting\n");
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

void checkIfEmpty(){
    
}

void push(){
    printf("Enter an integer\n");
    int input;
    if(scanf("%d", &input) == 1){
        if(Top == NULL){
            Top = (struct stack *) malloc(sizeof(struct stack));
            Top->data = input;
            Top->ptr = NULL;
        }
        else{
            Temp = (struct stack *) malloc(sizeof(struct stack));
            Temp->data = input;
            Temp->ptr = Top;
            Top = Temp;
        }
    }
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
        printf("The stack is empty");
    }
    
}

int main(){
    int ch, x;

    printf("Press a coressponding number to interact with stack:\n");

    while(1){
        print_interface();
        if(scanf("%d", &ch) == 1){
            switch(ch){
                case 1:
                    createStack();
                    break;
                case 2:
                    checkIfEmpty();
                    break;
                case 4:
                    push();
                    break;
                case 6:
                    display();
                    break;
                default:
                    printf("Enter a correct number\n");
            }
        }
        else{
            printf("ERROR1\n");
            return 0;
        }
        
    }
    return 0;
}