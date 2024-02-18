#include <iostream>
using namespace std;

int main(){
    int rows;
    cout << "Enter Number Of Rows: ";
    cin >> rows;

    int ** arr = new int*[rows];
   
    int * m = new int[rows];
    
    cout << endl << "Enter Number Of Elements in Each Rows: ";
    for(int i = 0; i < rows; i++){
    cin >> m[i];
    arr[i] = new int[m[i]];
    }
    
    cout << endl << "Enter The Elements: ";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < m[i]; j++){
            cin >> arr[i][j];
        }
    }

    cout << endl << endl << "Your Output: \n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < m[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // free the space
    for(int i = 0; i < rows; i++)delete [] arr[i];
    delete [] m;
    delete [] arr;
    return 0;
}