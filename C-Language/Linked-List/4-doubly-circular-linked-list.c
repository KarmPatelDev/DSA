#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    struct node * prev;
    int data;
    struct node * next;
};
struct node * head = NULL, * tail = NULL;

void createNodes();
void printLTR();
void printRTL();
int length();
void insertionHead();
void insertionTail();
void insertionPos();
void deletion();
void reverse();

int main(){
    
    int choice = 1;
    while(choice){

        printf("\n\nPress 1 For Create Node\n");
        printf("Press 2 For Print Left To Right\n");
        printf("Press 3 For Print Right To Left\n");
        printf("Press 4 For Length\n");
        printf("Press 5 For Insertion at Head\n");
        printf("Press 6 For Insertion at Tail\n");
        printf("Press 7 For Insertion at Pos\n");
        printf("Press 8 For Deletion\n");
        printf("Press 9 For Reverse\n");
        printf("Press 0 For Exit\n");
        printf("Enter The Number: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1: createNodes();
            break;
            case 2: printLTR();
            break;
            case 3: printRTL();
            break;
            case 4: printf("\nLength = %d\n", length());
            break;
            case 5: insertionHead();
            break;
            case 6: insertionTail();
            break;
            case 7: insertionPos();
            break;
            case 8: deletion();
            break;
            case 9: reverse();
            break;      
        }
    }

    
    return 0;
}

void createNodes(){

    int choice = 1;
    struct node * newNode, * temp;

    while(choice){

    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);
    newNode -> prev = NULL;
    newNode -> next = NULL;
    
    if(head == NULL){
       head = tail = temp = newNode;
       newNode -> prev = newNode;
       newNode -> next = newNode;
    }
    else{
       newNode -> prev = temp;
       temp -> next = newNode;
       temp = tail = newNode;
       newNode -> next = head;
       head -> prev = tail;
    }

    printf("To Continue Press 1 or Print Press 0: ");
    scanf("%d", &choice);
    }

}

int length(){

    int cnt = 0;
    struct node * temp = head;
    do{
        temp = temp -> next;
        cnt++;
    }while(temp != head);
    return cnt;
}

void printLTR(){
    
    if(head == NULL){
        printf("List is Empty");
    }
    else{
    printf("\n");
    struct node * temp = head;
    do{
        printf("%d ", temp -> data);
        temp = temp -> next;
    }while(temp != head);
    printf("\n");
    }

}

void printRTL(){
    
    if(head == NULL){
        printf("List is Empty");
    }
    else{
    printf("\n");
    struct node * temp = tail;
    do{
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }while(temp != tail);
    printf("\n");
    }

}

void insertionHead(){
    
    struct node * newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(head == NULL){
        head = tail = newNode;
        newNode -> next = head;
        newNode -> prev = tail;
    }
    else{
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
    newNode -> prev = tail;
    tail -> next = head;
    }

}

void insertionTail(){
    
    struct node * newNode, * temp = head;
    
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);
    newNode -> next = NULL;
    newNode -> prev = NULL;
    
    if(tail == NULL){
        head = tail = newNode;
        newNode -> next = head;
        newNode -> prev = tail;
    }
    else{
    newNode -> prev = tail;
    tail -> next = newNode;
    newNode -> next = head;
    head -> prev = newNode;
    tail = newNode;
    }
    
}

void insertionPos(){
    int pos;
    printf("Enter The Position: ");
    scanf("%d",&pos);

    int cnt = length();

    if(pos > cnt + 1 || pos <= 0){
        printf("The Position is Invalid");
    }
    else if(pos == 1){
       insertionHead();
    }
    else if(pos == cnt + 1){
       insertionTail();
    }
    else{

    struct node * newNode, * temp = head;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);

    int i = 1;
    while(i < pos - 1){temp = temp -> next;i++;}

    newNode -> next = temp -> next;
    newNode -> prev = temp;
    temp -> next = newNode;
    newNode -> next -> prev = newNode;

    }
    
} 

void deletion(){

    int cnt = length();
    
    if(head == NULL || tail == NULL){

    printf("List is Empty");

    }
    else{
    
    struct node * temp;
    int pos;
    printf("Enter The Position: ");
    scanf("%d",&pos);

    if(pos > cnt || pos <= 0){
        printf("The Position is Invalid");
    }  
    else if(head -> next == head){
        head = tail = NULL;
        free(temp);
    }
    else if(pos == 1){
        // Deletion at begin
        temp = head;
        head = head -> next;
        head -> prev = tail;
        tail -> next = head;
        free(temp);
    }
    else if(pos == cnt){
        // Deletion Last
        temp = tail;
        tail = tail -> prev;
        tail -> next = head;
        head -> prev = tail;
        free(temp);
    }
    else{
        // Deletion at Middle  
        temp = head;
        int i = 1;
        while(i < pos){temp = temp -> next;i++;}
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        if(temp -> next == head)tail = temp -> prev;
        free(temp);
    }

    }
    
}

void reverse(){

    struct node * current, * nextNode;

    if(head == NULL){
        printf("List is Empty");
    }
    else{
        current = head;
        while(current -> next != head){
              nextNode = current -> next;
              current -> next = current -> prev;
              current -> prev = nextNode;
              current = nextNode;
        }
        current -> next = current -> prev;
        current -> prev = head;
        head -> next = tail;
        tail = head;
        head = current;
    }
}