#include <iostream>
using namespace std;

void bubbleSort(int a[], int size){
     
     if(size == 0 || size == 1){
        return ;
     }

     for(int i = 0; i < size - 1; i++){
        if(a[i] > a[i + 1]){
            swap(a[i], a[i + 1]);
        }
     }

     bubbleSort(a, size - 1);
}

int main(){
    
    int size = 5;
    int a[size];
    
    cout << "Enter The Elements: ";
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }

    bubbleSort(a, size);
    
    cout << "Sorted Elements: ";
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    return 0;
}