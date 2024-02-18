#include <iostream>
using namespace std;

void print(int arr[], int size){
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}

void mergeArr(int arr1[], int size1, int arr2[], int size2){
    
    int size3 = size1 + size2;
    int arr3[size3];

    // for(int i = 0; i < size1; i++){
    //   arr3[i] = arr1[i];
    // }

    // for(int i = 0; i < size2; i++){
    //     arr3[size1 + i] = arr2[i];
    // }

    int i = 0, j = 0, k = 0;
    while(i < size1 && j < size2 && k < size3){
        
        if(arr1[i] > arr2[j]){
           arr3[k] = arr2[j];
           j++;
        }
        else if(arr1[i] < arr2[j]){
           arr3[k] = arr1[i];
           i++;
        }
        else{
            arr3[k] = arr1[i];
            arr3[k] = arr2[j];
            i++;
            j++;
            k++;

        }
        k++;
    }

    while(i < size1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
    print(arr3, size3);
}

int main(){
    
    int a1[] = {1, 3, 5, 7, 9};
    int a2[] = {2,4, 6, 8};

    mergeArr(a1, 5, a2, 4);

    return 0;
}