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
    int pos, num;

    printf("Enter The Position Of Element in Array: ");
    scanf("%d", &pos);

    printf("Enter The Number which you want to insert at Position %d in Array: ", pos);
    scanf("%d", &num);

    printf("\nYour Array is: ");
    if(pos <= 0 || pos > size + 1){
        printf("Invalid Position");
    }
    else{
        
        /*
       // Best Algorithm for Unsorted Array is :
       // Time Complexity = Theta(1)
          a[size] = a[pos - 1];
          a[pos - 1] = num;
          size++;
       */

        if(pos != 1){
        // position = index + 1
        for(int i = size - 1; i >= pos - 1; i--){
            a[i + 1] = a[i];
            if(i == pos - 1)a[i] = num;
        }
        size++;
        }
        else{
            // When The element insert at first position
            for(int i = size - 1; i <= 0; i--){
                a[i + 1] = a[i];
                if(i == 0)a[i] = num;
            }
            size++;
        }
        
        // array print
        for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }

    }
    }
    return 0;
}

// Time Complexity = Theta(n - pos);