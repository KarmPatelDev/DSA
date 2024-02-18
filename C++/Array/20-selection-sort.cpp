#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout << "Enter The Number Of Elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter The Elements:\n";
    for(int i = 0; i < n; i++)cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int temp = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[temp])temp = j;
        }
        swap(arr[temp], arr[i]);
    }

    for(int i = 0; i < n; i++)cout << arr[i] << " ";
    return 0;
}

