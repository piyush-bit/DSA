// write a c programm to implement simple queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue(){
    if(front == NULL){
        printf("Queue is empty");
        return -1;
    }
    struct Node *temp = front;
    int data = temp->data;
    front = front->next;
    free(temp);
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