#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node * head = NULL;

void createNodes();
void print();
int length();
void insertionHead();
void insertionTail();
void insertionPos();
void deletion();
void reverse();


int main(){
    
    int choice = 1;

        printf("Press 1 For Print\n");
        printf("Press 2 For Length\n");
        printf("Press 3 For Insertion at Head\n");
        printf("Press 4 For Insertion at Tail\n");
        printf("Press 5 For Insertion at Pos\n");
        printf("Press 6 For Deletion\n");
        printf("Press 7 For Reverse\n");
        printf("Press 0 For Exit\n");
        
    while(choice){

        printf("Enter The Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: print();
            break;
            case 2: printf("\nLength = %d\n", length());
            break;
            case 3: insertionHead();
            break;
            case 4: insertionTail();
            break;
            case 5: insertionPos();
            break;
            case 6: deletion();
            break;
            case 7: reverse();
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

    if(head == NULL){
       head = temp = newNode;
       newNode -> next = head;
    }
    else{
       temp -> next = newNode;
       temp = newNode; 
       newNode -> next = head;  
    }

    printf("To Continue Press 1 or Print Press 0: ");
    scanf("%d", &choice);
    }

}

int length(){

    struct node * temp = head;
    int cnt = 0;
    do{
        temp = temp -> next;
        cnt++;
    }while(temp != head);

    return cnt;
}

void print(){
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

void insertionHead(){
    
    struct node * newNode, * temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);

    if(head == NULL){
       head = newNode;
       newNode -> next = head;
    }
    else{
    newNode -> next = head;
    do{
        temp = head -> next;
    }while(temp -> next != head);
    temp -> next = newNode;
    head = newNode;
    }
}

void insertionTail(){
    
    struct node * newNode, * temp = head;
    
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);
    
    if(head == NULL){
        head = newNode;
        newNode -> next = head;
    }
    else{
    do{
        temp = temp -> next;
    }while(temp -> next != head);
    temp -> next = newNode;
    newNode -> next = head;
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
    temp -> next = newNode;

    }
    
} 

void deletion(){

    int cnt = length();
    
    if(head == NULL){
    printf("Sorry, The List is Empty\n");
    }
    else{
    
    struct node * temp = head;
    int pos;
    printf("Enter The Position: ");
    scanf("%d",&pos);

    if(pos > cnt || pos <= 0){
        printf("The Position is Invalid");
    }
    else if(head -> next == head){
        head = NULL;
        free(temp);
    }   
    else if(pos == 1){
        // Deletion at begin
        head = head -> next;
        struct node *temp2 = head;
        do{
        temp2 = temp2 -> next;
        }while(temp2 -> next != temp);
        temp2 -> next = head;
        free(temp);
    }
    else{
        // Deletion at Middle or last  
        int i = 1;
        while(i < pos - 1){temp = temp -> next;i++;}
        struct node *temp2 = temp -> next;
        temp -> next = temp2 -> next;
        free(temp2);
    }
    }
    
    
}

void reverse(){

    struct node * temp = NULL;
    struct node * current = head, * nextNode;
    
    if(head == NULL){
        printf("List is Empty");
    }
    else{

    do{
    nextNode = current -> next;
    current -> next = temp;
    temp = current;
    current = nextNode;
    }while(nextNode != head);
    head -> next = temp;
    head = temp;
    
    }
}