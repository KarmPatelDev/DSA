#include <iostream>
using namespace std;

#define N 5

bool isPossibleSolution(int a[], int mid, int cows){

    for(int i = 0; i < N; i++){
        for(int j = i + 1;j < N; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    int cowsCount = 1;
    int lastPos = a[0];

    for(int i = 0; i < N; i++){

        if((a[i] - lastPos) >= mid){
           cowsCount++;
           if(cowsCount == cows){
            return true;
           }
           lastPos = a[i];
        }
    }
    return false;
}

int cowsAggressive(int a[], int cows){
    
    int max = -1;
    for(int i = 0; i < N;i++){
        if(max < a[i])max = a[i];
    }

    int s = 0, e = max, mid = s + (e - s)/2, result;

    while(s <= e){

        if(isPossibleSolution(a, mid, cows)){
            result = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e - s)/2;
    }

    return result;
}

int main(){
    
    int a[N], cows;
    
    cout << "Enter The Number Of Cows: ";
    cin >> cows;

    cout << "Enter The Elements: ";
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    cout << "Maximum Distance: " << cowsAggressive(a, cows);

    return 0;
}