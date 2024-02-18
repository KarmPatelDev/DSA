#include <iostream>
using namespace std;

int checkDouble(int arr[], int n){
    
    if(n % 2 == 1)return 0;

    int ans = 0;

    for(int i = 0; i < n; i++){
    ans = ans ^ arr[i];
    }

    if(ans == 0)return 1;
    else return 0;

}

int main(){

    int a[10] = {1, 5, 3, 6, 4, 3, 6, 5, 4, 1};

    if(checkDouble(a, 10))cout << "All The Elements Are Two Times";
    else cout << "All The Elements Are Not Two Times";

    return 0;
}