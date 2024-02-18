#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * left;
    int data;
    struct node * right;
};

struct node * create();
void preOrder(struct node *);
void postOrder(struct node *);
void inOrder(struct node *);

int main(){
    
    struct node * root = NULL;
    root = create();

    printf("Pre-Order is : ");
    preOrder(root);

    printf("Post-Order is : ");
    postOrder(root);

    printf("In-Order is : ");
    inOrder(root);

    return 0;
}

struct node * create(){

    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("\nEnter The Number(-1 for no node): ");
    scanf("%d", &num);

    if(num == -1){
        return NULL;
    }

    newNode -> data = num;
    
    printf("Enter Left Child of %d\n", num);
    newNode -> left = create();
    
    printf("Enter Right Child of %d\n", num);
    newNode -> right = create();

}

void preOrder(struct node * root){
     
    if(root == NULL)return;

    printf("%d ", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);

}

void postOrder(struct node * root){

    if(root == NULL)return;

    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ", root -> data);
    
}

void inOrder(struct node * root){

    if(root == NULL)return;

    inOrder(root -> left);
    printf("%d ", root -> data);
    inOrder(root -> right);

}