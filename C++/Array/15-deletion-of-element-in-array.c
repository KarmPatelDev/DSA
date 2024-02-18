#include <stdio.h>

int main(){

    int a[50], size;

    printf("Enter The Size Of Array: ");
    scanf("%d", &size);

    // first check overflow and underflow condition
    if(size > 50){
        printf("OverFlow Condition, Please Enter The Number Less or equal to 50");
    }

    else if(size < 1){
        printf("UnderFlow Condition, Please Enter The Number Greater or equal to 1");
    }

    else{

    // array making
    printf("Enter The Elements Of Array\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }

    // element insertion
    int pos;

    printf("Enter The Position Of Element in Array: ");
    scanf("%d", &pos);

    printf("\nYour Array is: ");
    if(pos <= 0 || pos > size){
        printf("Invalid Position");
    }
    else{
        
        /*
       // Best Algorithm for Unsorted Array is :
       // Time Complexity = Theta(1)
          a[pos - 1] = a[size - 1];
          size--;
       */

        if(pos != 1){
        // position = index + 1
        for(int i = pos - 1; i <  size - 1; i++){
            a[i] = a[i + 1];
        }
        size--;
        }
        else{
            // When The element insert at first position
            for(int i = 0; i <  size - 1; i++){
                a[i] = a[i + 1];
            }
            size--;
        }
        
        // array print
        for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }

    }
    }
    return 0;
}

// Time Complexity = Theta(n);