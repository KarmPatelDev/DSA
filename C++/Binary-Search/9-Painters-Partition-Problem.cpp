#include <iostream>
using namespace std;

#define N 4

bool isPossibleSolution(int a[], int painters, int mid){
     
     int painterCount = 1;
     int blockSum = 0;

     for(int i = 0; i < N; i++){
         
         if(blockSum + a[i] <= mid){
            blockSum+=a[i];
         }
         else{
            painterCount++;
            if(painterCount > painters || a[i] > mid){
                return false;
            }
            blockSum = a[i];
         }
     }

     return true;
}

int painterPartition(int a[], int painters){
    
    int sum = 0;
    for(int i = 0; i < N; i++){
       sum+=a[i];
    }
    

    int s = 0, e = sum, mid = s + (e - s)/2, result = -1;

    while(s <= e){

        if(isPossibleSolution(a, painters, mid)){
           result = mid;
           e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }

    return result;
}

int main(){
    
    int a[N], painters;
    
    cout << "Enter The Number Of Painters: ";
    cin >> painters;
    
    cout << "Enter The Elements: ";
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    cout << painterPartition(a, painters);
    
    return 0;
}