#include <iostream>
using namespace std;

int main(){
    int n = 6;
    int arr[n] = {25, 35, 47, 81, 75, 12}; 
    int temp[n], key = 2;

    for(int i = 0; i < 6; i++){

        temp[(i + key)%n] = arr[i];

    }

    for(int i = 0; i < n; i++)cout << temp[i] << " ";
    
    return 0;
}