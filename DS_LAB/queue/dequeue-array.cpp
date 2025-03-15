//wap to implememnt circular dequeue using array

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = 0;

void insertFront(int data){
    if((rear+1)%SIZE == front){
        printf("Queue is full\n");
        return;
    }
    front = (front-1+SIZE)%SIZE;
    queue[front] = data;
}

void insertRear(int data){
    if((rear+1)%SIZE == front){
        printf("Queue is full\n");
        return;
    }
    queue[rear] = data;
    rear = (rear+1)%SIZE;
}

int deleteFront(){
    if(front == rear){
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    front = (front+1)%SIZE;
    return data;
}

int deleteRear(){
    if(front == rear){
        printf("Queue is empty\n");
        return -1;
    }
    rear = (rear-1+SIZE)%SIZE;
    return queue[rear];
}

void display (){
    printf("Queue : ");
    int i = front;
    while(i != rear){
        printf("%d ->",queue[i]);
        i = (i+1)%SIZE;
    }
    printf("x\n");
}

int main(){
    int choice;
    printf("1. Insert front\n2. Insert rear\n3. Delete front\n4. Delete rear\n5. Display\n6. Exit\n");
    while(1){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                {
                    int data;
                    printf("Enter data: ");
                    scanf("%d",&data);
                    insertFront(data);
                    display();
                }
                break;
            case 2:
                {
                    int data;
                    printf("Enter data: ");
                    scanf("%d",&data);
                    insertRear(data);
                    display();
                }
                break;
            case 3:
                printf("%d\n",deleteFront());
                display();
                break;
            case 4:
                printf("%d\n",deleteRear());
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}