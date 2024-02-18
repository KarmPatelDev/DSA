#include <iostream>
using namespace std;

int main(){
    
    int size = 6, key = 0;
    int arr[size] = {25, 36, 45, 78, 12, 19};
    
    if(arr[0] < arr[size - 1]){key++;}
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i + 1]){
        key++;
        }
    }
    
    if(key == 1){
        if(arr[0] > arr[size - 1])cout << "The Array is Rotated and Sorted";
        else cout << "The Array is Only Sorted";
    }
    else{
        cout << "The Array is nither Sorted nor Rotated";
    }

    return 0;
}