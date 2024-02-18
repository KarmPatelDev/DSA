#include <iostream>
using namespace std;

int main(){

    int row, column;
    cin >> row >> column;

    //creation
    int** arr = new int*[row];  
    for(int i = 0; i < row; i++)arr[i] = new int[column];
    
    //taking input
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> arr[row][column];
        }
    }

    cout << endl;
    
    // output
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << arr[row][column] << " ";
        }
        cout << endl;
    }
    

    // releasing memory
    for(int i = 0; i < row; i++)delete [] arr[i];
    delete [] arr; // if we delete this first then memory leak problem occur

    return 0;
}