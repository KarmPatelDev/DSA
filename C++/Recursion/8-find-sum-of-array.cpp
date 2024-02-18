#include <iostream>
using namespace std;

int sum(int a[], int size){
    
    if(size == 0){
        return 0;
    }
    
    if(size == 1){
        return a[0];
    }
    

    int remainingPart = a[size - 1] + sum(a, size - 1);
    
    return remainingPart;
}

int main(){
    int size = 5;
    int a[size];
    
    cout << "Enter The Elements: ";
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }

    cout << "The Sum Of Array is " << sum(a, size);
    return 0;
}