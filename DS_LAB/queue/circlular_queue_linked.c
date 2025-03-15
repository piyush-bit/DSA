#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

struct Node
{
    int data;
    struct Node *next;
};


struct Node *front = NULL;
struct Node *rear = NULL;
int count = 0 ;

void initLinkedList(){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = -1;
    temp->next = NULL;
    front = temp;
    rear = temp;

    for(int i =0 ; i<SIZE ; i++){
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = -1;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }

    rear->next = front;
    rear = front ; 
}


void enqueue(int data){
    if(count==SIZE){
        printf("Queue is full\n");
        return;
    }
    rear->data = data;
    rear = rear->next;
    count++;
}

int dequeue(){
    if(count==0){
        printf("Queue is empty\n");
        return -1;
    }
    int data = front->data;
    front->data = -1;
    front = front->next;
    count--;
    return data;
}


int main(){
    initLinkedList();
    int choice,data;

    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if(data==-1)
                    printf("Queue is empty\n");
                else
                    printf("Dequeued data : %d\n",data);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

