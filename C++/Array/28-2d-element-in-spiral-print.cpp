#include <iostream>
using namespace std;

int main(){


    int arr[4][4];
    int start_row = 0, end_row = 4, start_column = 0, end_column = 4;
    int m = end_row, n = end_column, count = 0, total = m*n;
    
    while(1){
    for(int i = start_row, j = start_column; j < end_column; j++){cin >> arr[i][j]; count++;if(count == 16)break;}
    start_row++;
    if(count == 16)break;

    for(int j = end_column - 1, i = start_row; i < end_row; i++){cin >> arr[i][j]; count++;if(count == 16)break;}
    end_column--;
    if(count == 16)break;

    for(int i = end_row - 1, j = end_column - 1; j >= start_column; j--){cin >> arr[i][j]; count++;if(count == 16)break;}
    end_row--;
    if(count == 16)break;

    for(int j = start_column, i = end_row - 1; i >= start_row; i--){cin >> arr[i][j]; count++;if(count == 16)break;}
    start_column++;
    if(count == 16)break;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}