#include <iostream>
using namespace std;

void check(int a[], int n, int sum){

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++)
            if((a[i] + a[j] + a[k]) == sum){
                cout << a[i] << " " << a[j] << " " << a[k] << endl;
            }
        }
    }
}

int main(){
    
    int arr[10] = {1, 5, 6, 7, 4, 3, 10, 2, 9, 0};
    int a;
    cout << "Enter The Number: ";
    cin >> a;

    check(arr, 10, a);


    return 0;
}