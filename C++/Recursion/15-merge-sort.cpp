#include <iostream>
using namespace std;

void merge(int* arr, int s, int e){

    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int * first = new int[len1];
    int * second = new int[len2];
    
    // copy the values
    int index = s;
    for(int i = 0; i < len1; i++)first[i] = arr[index++];
    for(int i = 0; i < len2; i++)second[i] = arr[index++];


    //Merge and Sorted Arrays
    index = s;
    int index1 = 0, index2 = 0;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[index++] = first[index1++];
        }
        else{
            arr[index++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[index++] = first[index1++];
    }

    while(index2 < len2){
        arr[index++] = second[index2++];
    }


}

void mergeSort(int* arr, int s, int e){

     // base case
     if(s >= e)return;
     
     //make partitions
     int mid = s + (e-s)/2;
     
     // left part sort
     mergeSort(arr, s, mid);
     
     // right part sort
     mergeSort(arr, mid + 1, e);
     
     //merge
     merge(arr, s, e);

}

int main(){
    
    int arr[] = {4, 6, 5, 8, 1, 7};
    mergeSort(arr, 0, 5);
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    return 0;
}