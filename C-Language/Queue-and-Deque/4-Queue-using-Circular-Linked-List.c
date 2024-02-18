#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};
struct node * front = NULL, *rear = NULL;

void enqueue();
void dequeue();
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
        enqueue();
        break;
        case 2:
        dequeue();
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

void enqueue(){
    
    int num;
    printf("Enter The Number: ");
    scanf("%d", &num);
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = num;
    newNode -> link = NULL;


    if(front == NULL && rear == NULL){
        front = rear = newNode;
        newNode -> link = front;
    }
    else{
        rear -> link = newNode;
        newNode -> link = front;
        rear = newNode;
    }
}

void dequeue(){
    
    if(front == NULL && rear == NULL){
        printf("\nQueue is in UnderFlow Condition");
    }
    else if(front == rear){
        struct node * temp = front;
        printf("\n%d Number is Removed", front -> data);
        free(temp);
        front = rear = NULL;
    }
    else{
         struct node * temp = front;
         printf("\n%d Number is Removed", front -> data);
         front = front -> link;
         rear -> link = front;
         free(temp);
    }
}

void peep(){
    if(front == NULL && rear == NULL){
        printf("\nQueue is Empty");
    }
    else{
    printf("\nThe Last Number Added is %d", rear -> data);
    }
}

void display(){
    if(front == NULL && rear == NULL){
        printf("\nQueue is Empty");
    }
    else{
    struct node * temp = front;
    printf("\n");
    while(temp -> link != front){
        printf("%d ", temp -> data);
        temp = temp -> link;
    }
    printf("%d", temp -> data);
    }
}
