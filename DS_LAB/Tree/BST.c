// implement bst 

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *newNode(int data){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(node **root, int data) {
    if (*root == NULL) {
        *root = newNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}


void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    node *root = NULL;
    int arr[]= {30 , 20 , 40 , 70, 60 , 80, 5 , 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        insert(&root, arr[i]);
    }
    inorder(root);
    return 0;
}