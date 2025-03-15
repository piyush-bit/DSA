#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

int main() {
    // Allocate memory dynamically for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Initialize the node with an integer value
    newNode->data = 40;
    newNode->link = NULL;

    // Display the data value of the new node
    printf("New node data: %d\n", newNode->data);

    // Free the allocated memory
    free(newNode);


}
