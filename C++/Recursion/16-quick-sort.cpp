#include <iostream>
using namespace std;

int partition(int* arr, int s, int e){

    int pivot = arr[s], count = 0;

    for(int i = s + 1; i <= e; i++){if(arr[i] <= pivot)count++;}
    
    //place pivot at right side
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);
    
    // left and right respectively less then and greater than part check and if not then exchange values
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){

        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(arr[i] > arr[j]){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    return pivotIndex;
}

void quickSort(int* arr, int s, int e){
     
     // base case
     if(s >= e)return;

     //make partitions
     int p = partition(arr, s, e);
     
     // left part sort
     quickSort(arr, s, p-1);
     
     // right part sort
     quickSort(arr, p+1, e);
}

int main(){
    int arr[] = {4, 6, 5, 8, 1, 7};
    quickSort(arr, 0, 5);
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}