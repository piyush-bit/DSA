#define SIZE 2

// write a c program to implememnt circular queue using array

#include <stdio.h>

int queue[SIZE];
int front = 0;
int rear = 0;
int count = 0;


void enqueue(int data){
    if(count == SIZE){
        printf("Queue is full");
        return;
    }
    queue[rear] = data;
    rear = (rear+1)%SIZE;
    count++;
}


int dequeue(){
    if(count == 0){
        printf("Queue is empty");
        return -1;
    }
    int data = queue[front];
    front = (front+1)%SIZE;
    count--;
    return data;
}


int main(){
    enqueue(10);
    enqueue(20);
    printf("%d\n",dequeue());
    enqueue(30);
    printf("%d\n",dequeue());
    enqueue(40);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    return 0;
}

