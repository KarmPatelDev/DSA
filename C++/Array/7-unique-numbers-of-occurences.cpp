#include <iostream>
#include <vector>
using namespace std;

void uniqueOccurence(int arr[], int size){
    
    int b[2001] = {0};
    for(int i = 0; i < size; i++){
        
        if(arr[i] < 0){
           b[(-1)*arr[i] + 1000]++;
        }
        else{
            b[arr[i]]++;
        }

    }
    
    vector<int> num;
    int j = 0;
    for(int i = 0; i < 2001; i++){
        if(b[i] != 0){
          num.push_back(b[i]);
          j++;
        }
    }

    for(int i = 0; i < j; i++){
        for(int k = i + 1; k < j; k++){
            if(num[i] == num[k]){
                cout << "There is not a unique number occurances";
                exit(0);
            }
        }
    }
    
    cout << "There is a unique number occurances";
}

int main(){
    
    int a[6] = {1, -1000, -1000, -1000, 2, 2};  //element value is between 0 to 1000
    uniqueOccurence(a, 6);
    return 0;
}