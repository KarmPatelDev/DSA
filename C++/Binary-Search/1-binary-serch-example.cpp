#include <iostream>
using namespace std;

void findKey(int arr[], int size, int key){
     int s = 0, e = size - 1;
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

    int a[] = {19, 22, 44, 57, 71, 78};
    findKey(a, 6, 22);
    return 0;
}