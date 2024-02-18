// Pivot means Maximum downfall in the graph we can choose its max or min for answer

#include <iostream>
using namespace std;

int getPivot(int arr[], int size){

    int s = 0, e = size - 1, mid = s + (e - s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        
        mid = s + (e - s)/2;
    }
    return s;
}

int main(){
    
    int arr[] = {8, 10, 17, 19, 22, 6};   // sorted rotated form
    cout << "Pivot Position is " << getPivot(arr, 6);
    return 0;
}