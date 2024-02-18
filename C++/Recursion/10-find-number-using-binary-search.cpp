#include <iostream>
using namespace std;

bool binarySearch(int a[], int s, int e, int key){
    
    int mid = s + (e - s)/2;

    if(s > e)return false;

    if(a[mid] == key)return false;

    if(key > a[mid]){
        binarySearch(a, mid + 1, e, key);
    }
    else{
        binarySearch(a, s, mid - 1, key);
    }
    
}

int main(){
    
    int size = 5, key;
    int a[size], s = 0, e = size - 1;
    
    cout << "Enter The Elements: ";
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }
    
    cout << "Enter The Number, Which you want to search: ";
    cin >> key;
    
    if(binarySearch(a, s, e, key)){
       cout << "Element is Present in Array";
    }
    else{
       cout << "Element is not Present in Array";
    }

    return 0;
}