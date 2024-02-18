#include <iostream>
using namespace std;

void duplicateFind(int arr[], int size){
    
    // WE CAN ALSO USE XOR OPERATION IN THAT ALL NUMBER 2 TIMES BUT DUPLICATE IS 3 TIMES


    int sum1 = 0, sum2 = 0;
    for(int i = 1; i < size; i++)sum1 += i;
    for(int i = 0; i < size; i++)sum2 += arr[i];

    cout << "The Number is " << sum2 - sum1;
}

int main(){
    
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 7};

    duplicateFind(a, 10);

    return 0;
}