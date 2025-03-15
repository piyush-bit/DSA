//write a c programm to implement simple queue using array 

#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;


void enqueue(int data){
    if(rear == 99){
        printf("Queue is full");
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {  
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];  
    front++;
    if (front > rear) {  
        front = -1;
        rear = -1;
    }
    return data;
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    return 0;
}