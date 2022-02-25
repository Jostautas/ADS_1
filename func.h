#ifndef HEADER
#define HEADER

struct stack;

void init(int *limit, int *numOfStacks);
void printInterface();
void deleteStack(int i);
void createStack(int i);
void checkIfEmpty(int i);
void checkIfFull(int i, int limit);
void push(int i, int limit);
int pop(int i);
void display(int i);
void howMany(int i);
int howMany2(int i);
int getInt();
void checkIfExists(int numOfStacks, int temp, int *currentStack);
void delOldStacks(int n);

#endif