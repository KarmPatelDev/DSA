#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter The Number Of Elements: ";
    cin >> n;
    
    int arr[n];
    bool result = false;

    cout << "Enter The Elements:\n";
    for(int i = 0; i < n; i++)cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){swap(arr[j], arr[j+1]);result = true;}
        }
        if(result == false)break;
    }

    for(int i = 0; i < n; i++)cout << arr[i] << " ";
    return 0;
}