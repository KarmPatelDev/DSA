#include <iostream>
using namespace std;

void checkDouble(int arr[], int size){
    
    int ans = 0;
    for(int i = 0; i < size; i++){
        ans = ans ^ arr[i];
    }

    cout << "The Single Element in Array is " << ans;

}

int main(){

    int a[7] = {1, 2, 4, 2, 1, 4, 8};
    checkDouble(a, 7);

    return 0;
}