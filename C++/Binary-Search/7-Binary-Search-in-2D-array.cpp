#include <iostream>
using namespace std;

void binarySearch(int m, int n, int arr[][4],int key){

    int s = 0, e = (m * n) - 1, mid = s + (e - s) / 2;

    while(s <= e){
          
          if(arr[mid/n][mid%n] == key){
                 cout << key << " is present in 2D Array";
                 exit(0);
          }

          if(arr[mid/n][mid%n] > key){
                 e = mid - 1;
          }

          if(arr[mid/n][mid%n] < key){
                 s = mid + 1;
          }
          mid = s + (e - s) / 2;
    }
    
    cout << key << " is not present in 2D Array";

}

int main(){
    
    int a[4][4];
    cout << "Enter The Elements: ";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            // write as a sorted array
            cin >> a[i][j];
        }
    }
    int key;
    cout << endl << endl << "Enter The Number with You Want To Search: ";
    cin >> key;
    cout << endl;
    binarySearch(4, 4, a, key);

    return 0;
}


// Time Complexity : 0(log(m*n))