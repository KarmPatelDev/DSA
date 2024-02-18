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
    }
    else{
       newNode -> prev = tail;
       temp -> next = newNode;
       temp = tail = newNode;
    }

    printf("To Continue Press 1 or Print Press 0: ");
    scanf("%d", &choice);
    }

}

int length(){

    int cnt = 0;
    struct node * temp = head;
    while(temp != NULL){
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

void printLTR(){
    if(head == NULL){
        printf("List is Empty");
    }
    else{
    printf("\n");
    struct node * temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    }

}

void printRTL(){
    if(tail == NULL){
        printf("List is Empty");
    }
    else{
    printf("\n");
    struct node * temp = tail;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }
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
    }
    else{
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
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
    }
    else{
    tail -> next = newNode;
    newNode -> prev = tail;
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
    else if(head == tail){
        temp = head;
        head = NULL;
        free(temp);
    }
    else if(pos == 1){
        // Deletion at begin
        temp = head;
        head = head -> next;
        head -> prev = NULL;
        free(temp);
    }
    else if(pos == length()){
        // Deletion last
        temp = tail;  
        tail = tail -> prev;
        tail -> next = NULL;
        free(temp);
    }
    else{
        // Deletion Middle
        temp = head;
        int i = 1;
        while(i < pos){temp = temp -> next;i++;}
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
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
        while(current != NULL){
              nextNode = current -> next;
              current -> next = current -> prev;
              current -> prev = nextNode;
              current = nextNode;
        }
        current = head;
        head = tail;
        tail = current;
    }
}