#include <stdio.h>

#define N 5
int stack[N], top = -1;

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
   
    if(top == N - 1){
       printf("\nStack is in OverFlow Condition");
    }
    else{
        int num;
        printf("\nEnter The Number: ");
        scanf("%d", &num);
        top++;
        stack[top] = num;
        printf("%d Number is Added", num);
    }

}

void pop(){

    if(top == -1){
        printf("\nStack is in UnderFlow Condition");
    }
    else{
        printf("\n%d Number is Removed", stack[top]);
        top--;
    }

}

void peep(){
    
    if(top == -1){
        printf("\nStack is Empty");
    }
    else{
    printf("\nThe Last Number Added is %d", stack[top]);
    }
}

void display(){

    if(top == -1){
        printf("\nStack is Empty");
    }
    else{
    printf("\n");
    int i;
    for(i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    }
}