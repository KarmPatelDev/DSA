#include <stdio.h>

#define N 5 
int s1[N], s2[N], top1 = -1, top2 = -1, count = 0;

void push1(int);
void push2(int);
int pop1();
int pop2();
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

void push1(int num){
    
    if(top1 == N - 1){
        printf("\nQueue is in OverFlow Condition");
    }
    else{
    
    top1++;
    s1[top1] = num;
    }

}

int pop1(){  
    return s1[top1--];
}

void push2(int num){
    
    if(top2 == N - 1){
        printf("\nQueue is in OverFlow Condition");
    }
    else{
    
    top2++;
    s2[top2] = num;
    }

}

int pop2(){
    return s2[top2--];
}
 
void enqueue(){
     int num;
    printf("Enter The Number: ");
    scanf("%d", &num);
    push1(num);
    count++;
}

void dequeue(){ 
    if(top1 == -1){
        printf("\nQueue is in UnderFlow Condition");
    }
    else{
        int i;
        for(i = 0; i < count; i++){
            push2(pop1());
        }
    
        count--;

        for(i = 0; i < count; i++){
             push1(pop2());
        }
    
    }
}

void peep(){
    if(top1 == -1){
      printf("\nQueue is Empty");
    }
    else{
    printf("\nThe Last Number is %d", s1[top1]);
    }
}

void display(){
    if(top1 == -1){
      printf("\nQueue is Empty");
    }
    else{
    int i;
    for(i = 0; i <= top1; i++){
        printf("%d ", s1[i]);
    }
    }
}