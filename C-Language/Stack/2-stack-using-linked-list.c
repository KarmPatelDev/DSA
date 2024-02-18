#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};
struct node * top = NULL;

void push();
void pop();
void peep();
void display();

int main(){
    
int choice = 1;
while(choice){
    printf("\n\n");
    printf("Press 1 For Push\n");
    printf("Press 2 For Pop\n");
    printf("Press 3 For Peep\n");
    printf("Press 4 For Display\n");
    printf("Press 0 For Exit\n");
    printf("Enter The Choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peep();
        break;
        case 4:
        display();
        break;
    }
}

    return 0;
}

void push(){

    struct node * newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter The Number: ");
    scanf("%d", &newNode -> data);

    if(top == NULL){
        top = newNode;
        newNode -> link = NULL;
        printf("%d Number is Added", top -> data);
    }
    else{
    newNode -> link = top;
    top = newNode;
    printf("%d Number is Added", top -> data);
    }

}

void pop(){
    
    if(top == NULL){
        printf("\nStack is in UnderFlow Condition");
    }
    else{
    struct node * temp = top;
    top = top -> link;
    printf("\n%d is Removed", temp -> data);
    free(temp);
    }

}

void peep(){
    
    if(top == NULL){
        printf("\nStack is Empty");
    }
    else{
    printf("\nThe Last Number Added is %d", top -> data);
    }

}

void display(){
    
    if(top == NULL){
        printf("\nStack is Empty");
    }
    else{
    printf("\n");
    struct node * temp = top;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> link;
    }
    }
    
}