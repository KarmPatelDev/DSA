#include <iostream>
using namespace std;

int linearSearch(int a[], int size, int key){

    if(size == 0){
        return false;
    }
    if(key == a[size - 1]){
         return true;
    }
    else{
        bool remainingPart = linearSearch(a, size - 1, key);
        return remainingPart;
    }

}

int main(){
    
    int size = 5, key;
    int a[size];
    
    cout << "Enter The Elements: ";
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }
    
    cout << "Enter The Number, Which you want to search: ";
    cin >> key;
    
    if(linearSearch(a, size, key)){
       cout << "Element is Present in Array";
    }
    else{
       cout << "Element is not Present in Array";
    }

    return 0;
}