#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *left;
    struct node *right;
} node;

typedef struct stack {
    node *treeNode;
    struct stack *next;
} stack;

void push(stack **root, node *treeNode) {
    stack *newNode = (stack *)malloc(sizeof(stack));
    newNode->treeNode = treeNode;
    newNode->next = *root;
    *root = newNode;
}

node *pop(stack **root) {
    if (*root == NULL) return NULL;
    stack *temp = *root;
    node *treeNode = temp->treeNode;
    *root = (*root)->next;
    free(temp);
    return treeNode;
}

node *newNode(char data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Inorder traversal to print the tree
void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    char exp[] = "abc*+def+*+";
    int n = strlen(exp);

    stack *root = NULL;
    for (int i = 0; i < n; i++) {
        if (isalnum(exp[i])) {
            // Operand: create a new node and push it onto the stack
            push(&root, newNode(exp[i]));
        } else {
            // Operator: pop two nodes, make them children, and push the new node back
            node *right = pop(&root);
            node *left = pop(&root);
            node *temp = newNode(exp[i]);
            temp->left = left;
            temp->right = right;
            push(&root, temp);
        }
    }

    // The root of the expression tree is the last remaining node on the stack
    node *treeRoot = pop(&root);

    // Print the inorder traversal of the expression tree
    printf("Inorder traversal of the expression tree: ");
    inorder(treeRoot);
    printf("\n");

    return 0;
}
