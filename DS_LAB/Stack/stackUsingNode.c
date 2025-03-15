// implement stack usingn linked list 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop(){
    if(top==NULL){
        printf("Stack is empty");
        return -1;
    }
    int data = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return data;
}

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}

int peek(){
    if(top==NULL){
        printf("Stack is empty");
        return -1;
    }
    return top->data;
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix) {
    int i = 0, j = 0;
    char postfix[100];

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            
            push(infix[i]);
        } else if (infix[i] == ')') {
            
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else {
            
            while (!isEmpty() && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate the postfix expression
    printf("Postfix expression: %s\n", postfix);
}


// Main function
int main() {
    char infix[100]; // Assume the infix expression will not exceed 100 characters
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}