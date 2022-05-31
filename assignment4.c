//  Program:    reversed-words-with-stack
//  Purpose:    reverse the string taken from the command line with stack
//  Author:     Akif Artun
//  Date:       25/05/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char letter;
    struct node *next;
};

struct node* stack_create();
//  Creates head node for empty stack
//  Parameters:     - (nothing)
//  Return:         pointer of head node

void stack_push(char l);
//  takes a character to insert a new element on top of the stack
//  Parameters:     l - character to insert into stack
//  Return:         void (nothing)

char stack_pop();
//  returns the value stored at the top of the stack.
//  Parameters:     - (nothing)
//  Return:         char letter

char stack_top();
//  returns the value stored at the top of the stack without removing it.
//  Parameters:     - (nothing)
//  Return:         char letter

int stack_isempty();
//  returns 1 if the stack is not empty and 0 otherwise. 
//  Parameters:     - (nothing)
//  Return:         1 or 0

void print_stack();
//  prints the elements stored on the stack.
//  Parameters:     - (nothing)
//  Return:         void (nothing)

struct node* head;

void main(int argc, char **argv) {

    if(argc != 2) {
        printf("Please use correct format.");
        exit(0);
    }

    int length = strlen(argv[1]);
    char revstr[length];

    struct node* head = stack_create();

    for(int i = 0;i < length;i++) {

        stack_push(argv[1][i]);

    }

    print_stack();

}

struct node* stack_create() {
    head = NULL;
    return head;
}

void stack_push(char l) {

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> letter = l;

    if(stack_isempty() == 0) {
        newNode -> next = NULL;
    } else {
        newNode -> next = head;
    }

    head = newNode;

}

char stack_pop() {

    if(stack_isempty() == 1) {

        struct node *temp = head;

        char tempdata = head -> letter;
        head = head -> next;

        free(temp);

        return tempdata;

    } else {
        printf("Stack is empty. Stack Underflow!");
        exit(0);
    }
        

}

char stack_top() {

    if(stack_isempty() == 1) {
        return head -> letter;
    } else {
        printf("Stack is empty. I can not show top of the stack to you. Fix it :)");
        exit(0);
    }

}

int stack_isempty() {
    if(head == NULL) {
        return 0;
    } else {
        return 1;
    }
}

void print_stack() {

    while(head != NULL) {
        printf("%c",stack_pop());
    }
    printf("\n");

}
