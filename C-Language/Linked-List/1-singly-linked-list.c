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
    while(choice){

        printf("\n\nPress 1 For Create Node\n");
        printf("Press 2 For Print\n");
        printf("Press 3 For Length\n");
        printf("Press 4 For Insertion at Head\n");
        printf("Press 5 For Insertion at Tail\n");
        printf("Press 6 For Insertion at Pos\n");
        printf("Press 7 For Deletion\n");
        printf("Press 8 For Reverse\n");
        printf("Press 0 For Exit\n");
        printf("Enter The Number: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1: createNodes();
            break;
            case 2: print();
            break;
            case 3: printf("\nLength = %d\n", length());
            break;
            case 4: insertionHead();
            break;
            case 5: insertionTail();
            break;
            case 6: insertionPos();
            break;
            case 7: deletion();
            break;
            case 8: reverse();
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
    newNode -> next = NULL;

    if(head == NULL){
       head = temp = newNode;
    }
    else{
       temp -> next = newNode;
       temp = newNode;   
    }

    printf("To Continue Press 1 or Print Press 0: ");
    scanf("%d", &choice);
    }

}

void print(){
    if (head == NULL){
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

int length(){

    struct node * temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp -> next;
        cnt++;
    }

    return cnt;
}

void insertionHead(){
    
    struct node * newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter The Number: ");
    scanf("%d", &newNode -> data);

    if(head == NULL){
        head = newNode;
        newNode -> next = NULL;
    }
    else{
    newNode -> next = head;
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
        newNode -> next = NULL;
    }
    else{
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = NULL;
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
         printf("List is Empty");
    }
    else{

    struct node * temp = head;
    int pos;
    printf("Enter The Position: ");
    scanf("%d",&pos);

    if(pos > cnt || pos <= 0){
        printf("The Position is Invalid");
    }  
    else if(head -> next == NULL){
        head = NULL;
        free(temp);
    }
    else if(pos == 1){
        // Deletion at begin
        head = head -> next;
        free(temp);
    }
    else{
        // Deletion at Middele or last
        int i = 1;
        while(i < pos - 1){temp = temp -> next;i++;}
        struct node *temp2 = temp -> next;
        temp -> next = temp2 -> next;
        free(temp2);
    }

    }
    
}

void reverse(){
    if(head == NULL){
      printf("List is empty");
    }
    else{
    struct node * temp = NULL;
    struct node * current = head;
    
    while(current != NULL){
    current = head -> next;
    head -> next = temp;
    temp = head;
    head = current;
    }
    head = temp;
    }
}