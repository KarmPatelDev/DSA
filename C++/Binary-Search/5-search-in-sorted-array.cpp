#include <iostream>
using namespace std;

int findPivot(int arr[], int size){
    int s = 0, e = size - 1, mid = s + (e - s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }

    return s;
}

void findKey(int s, int e, int arr[], int key){
     int mid = s + (e - s)/2;

     while(s <= e){

        if(arr[mid] == key){
            cout << key << " is present in array";
            exit(0);
        }

        if(arr[mid] > key){
            e = mid - 1;
        }
        
        if(arr[mid] < key){
            s = mid + 1;
        }
        
        mid = s + (e-s)/2;
     }
     cout << key << " is not present in array";

}

int main(){
    

    int arr[] = {8, 10, 17, 1, 2, 6};
    int pivot = findPivot(arr, 6);
    int key = 20;
    if(key >= arr[0] && key <= arr[pivot - 1]){
        findKey(0, pivot - 1, arr, key);
    }else{
        findKey(pivot, 5, arr, key);
    }

    return 0;
}