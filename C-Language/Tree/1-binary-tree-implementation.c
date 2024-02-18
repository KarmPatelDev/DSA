#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * left;
    int data;
    struct node * right;
};

struct node * create();

int main(){
    
    struct node * root = NULL;
    root = create();
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