#include <iostream>
using namespace std;

void altSwap(int arr[], int size){

    for(int i = 1; i < size; i+=2){
         int temp = arr[i - 1];
         arr[i - 1] = arr[i];
         arr[i] = temp;
    }
}

int main(){
    
    int a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    altSwap(a, 11);
    for(int i = 0; i < 11; i++){
        cout << a[i] << " ";
    }
    return 0;
}

// Time Complexity -  O(1)
// if we take n number then - O(n)