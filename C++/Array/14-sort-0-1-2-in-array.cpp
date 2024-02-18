#include <iostream>
using namespace std;

int main(){
    
    int arr[10] = {0, 1, 0, 2, 1, 1, 2, 1, 2, 0};
    int i = 0, j = 9;

    while(i < j){
        
        while(arr[i] == 0 && i < j)i++;
        while(arr[j] == 2 && i < j)j--;
        while(arr[i] == 2 && arr[j] == 0 && i < j){swap(arr[i], arr[j]);i++;j--;}
        while(arr[i] == 2 && arr[j] == 1 && i < j){swap(arr[i], arr[j]);j--;}
        while(arr[i] == 1 && arr[j] == 0 && i < j){swap(arr[i], arr[j]);i++;}

    }

    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    return 0;
}