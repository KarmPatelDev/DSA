#include <iostream>
using namespace std;

int peakIndex(int arr[], int size){
    int s = 0, e = size - 1, mid = s + (e - s)/2;
    
    while(s < e){
        if(arr[mid] < arr[mid + 1]){s = mid + 1;}
        else{e = mid;}
        mid = s + (e - s)/2;
    }
    
    return s;
}

int main(){
    
    int a[] = {12, 23, 45, 57, 66, 57, 43, 23};
    int ans = peakIndex(a, 8);
    cout << "Peak Index is " << ans << " and value is " << a[ans];
    return 0;
}