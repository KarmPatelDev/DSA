#include <iostream>
using namespace std;

void moveZeroes(int arr[], int size){

    int i = 0, j = size - 1;
    
    //Approach 2
    // for(int i = 0; i <= j; i++){
    //     if(arr[i] == 0){
    //         swap(arr[i], arr[j]);
    //         j--;
    //         i--; 
    //     }
    // }

    // Approarch 1
    // while(i < j){

    //     while(arr[i] != 0 && arr[j] == 0){
    //         i++;
    //         j--;
    //     }

    //     while(arr[i] != 0 && arr[j] != 0){
    //         i++;
    //     }

    //     while(arr[i] == 0 && arr[j] != 0){
    //         swap(arr[i], arr[j]);
    //         i++;
    //         j--;
    //     }

    //     while(arr[i] == 0 && arr[j] == 0){
    //         j--;
    //     }
    // }

}

int main(){
    
    int a[] = {5, 7, 0, 6, 8, 9, 0, 7, 9,0, 1, 0};

    moveZeroes(a, 12);

    for(int i = 0; i < 12; i++)cout << a[i] << " ";

    return 0;
}