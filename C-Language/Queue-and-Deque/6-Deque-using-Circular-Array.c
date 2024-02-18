#include <stdio.h>

#define N 5
int deque[N], front = -1, rear = -1;

void enqueueFront();
void enqueueRear();
void dequeueFront();
void dequeueRear();
void peepFront();
void peepRear();
void display();


int main(){

int choice = 1;

while(choice){
    printf("\n\n");
    printf("Press 1 For Push Front\n");
    printf("Press 2 For Push Rear\n");
    printf("Press 3 For Pop Front\n");
    printf("Press 4 For Pop Rear\n");
    printf("Press 5 For Peep Front\n");
    printf("Press 6 For Peep Rear\n");
    printf("Press 7 For Display\n");
    printf("Press 0 For Exit\n");
    printf("Enter The Choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
        enqueueFront();
        break;
        case 2:
        enqueueRear();
        break;
        case 3:
        dequeueFront();
        break;
        case 4:
        dequeueRear();
        break;
        case 5:
        peepFront();
        break;
        case 6:
        peepRear();
        break;
        case 7:
        display();
        break;
    }
}

    return 0;
}

void enqueueFront(){

    int num;
    printf("\nEnter The Number: ");
    scanf("%d", &num);

    if(front == -1 && rear == -1){
        front = rear = 0;
        deque[front] = num;
        printf("%d number is Added", deque[front]);
    }
    else if(front == rear + 1 || (front == 0 && rear == N - 1)){
        printf("Deque is in OverFlow Condition");
    }
    else if(front == 0){
        front = N - 1;
        deque[front] = num;
        printf("%d number is Added", deque[front]);
    }
    else{
        front--;
        deque[front] = num;
        printf("%d number is Added", deque[front]);
    }

}

void enqueueRear(){

    int num;
    printf("\nEnter The Number: ");
    scanf("%d", &num);

    if(front == -1 && rear == -1){
        front = rear = 0;
        deque[rear] = num;
        printf("%d number is Added", deque[rear]);
    }
    else if(front == rear + 1 || (front == 0 && rear == N - 1)){
        printf("Deque is in OverFlow Condition");
    }
    else if(rear == N - 1){
        rear = 0;
        deque[rear] = num;
        printf("%d number is Added", deque[rear]);
    }
    else{
        rear++;
        deque[rear] = num;
        printf("%d number is Added", deque[rear]);
    }

}

void dequeueFront(){
    
    if(front == -1 && rear == -1){
        printf("\nDeque is in UnderFlow Condition");
    }
    else if(front == rear){
        printf("\n%d Number is Removed", deque[front]);
        front = rear = -1;
    }
    else if(front == N - 1){
        printf("\n%d Number is Removed", deque[front]);
        front = 0;
    }
    else{
        printf("\n%d Number is Removed", deque[front]);
        front++;
    }

}

void dequeueRear(){
    
    if(front == -1 && rear == -1){
        printf("\nDeque is in UnderFlow Condition");
    }
    else if(front == rear){
        printf("\n%d Number is Removed", deque[rear]);
        front = rear = -1;
    }
    else if(rear == 0){
        printf("\n%d Number is Removed", deque[rear]);
        rear = N - 1;
    }
    else{
        printf("\n%d Number is Removed", deque[rear]);
        rear--;
    }
    
}

void peepFront(){
    if(front == -1 && rear == -1){
        printf("\nDeque is Empty");
    }
    else{
    printf("\nThe First Number Added is %d", deque[front]);
    }
}

void peepRear(){
    if(front == -1 && rear == -1){
        printf("\nDeque is Empty");
    }
    else{
    printf("\nThe Last Number Added is %d", deque[rear]);
    }
}

void display(){

    if(front == -1 && rear == -1){
        printf("\nDeque is Empty");
    }
    else{
    printf("\n");
    int i = front;
    while(i != rear){
        printf("%d ", deque[i]);
        i = (i + 1)%N;
    }
    printf("%d", deque[rear]);  
}

}