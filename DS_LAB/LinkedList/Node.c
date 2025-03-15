#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

int main() {
    //1
    struct Node node1 = {10, NULL};

    printf("Node 1 data: %d\n", node1.data);
    // 2
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = 40;
    newNode->link = NULL;

    printf("New node data: %d\n", newNode->data);

     // 3.a) Create two nodes and initialize them
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));

    first->data = 50;
    first->link = second;

    second->data = 60;
    second->link = NULL;

    // 3.b) Create a pointer named head and initialize it with the address of the first node
    struct Node* head = first;
    printf("First node data using head: %d\n", head->data);

    // c) Create a second pointer named ptr, initialize it with head, and display the data
    struct Node* ptr = head;
    printf("First node data using ptr: %d\n", ptr->data);
    // Increment the pointer ptr
    ptr = ptr->link;

    // 3.d) Display the data part of each node by incrementing ptr
    while (ptr != NULL) {
        printf("Next node data: %d\n", ptr->data);
        ptr = ptr->link;
    }

    // Free the allocated memory
    free(first);
    free(second);
    // Free the allocated memory
    free(newNode);

    return 0;
}
