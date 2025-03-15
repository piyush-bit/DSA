//1.implement stack using array
#include<stdio.h>
#include<string.h>

char stack[100];

int top = -1;


void push(int data){
    
    if(top==100){
        printf("Stack is full");
        return; 
    }

    stack[++top] = data;
}

int pop(){
    if(top==-1){
        printf("Stack is empty");
        return -1;
    }
    return stack[top--];
}

int main(){
    int size = 6;
    char str [6] = "Happy";
    

    printf("before inversion %s /n",str);

    for(int i=0;i<size-1;i++){
        push(str[i]);
    }

    for(int i=0;i<size-1;i++){
        str[i]=pop();
    }

    printf("after inversion %s",str);
}

