#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    int i = 1;
    while(i <= n){
         int j = 1;
         while(j <= n - i + 1){
            cout << j;
            j++;
         }
         int star1 = j;
         while(star1 <= n){
            cout << "*";
            star1++;
         }
         int star2 = j;
         while(star2 <= n){
            cout << "*";
            star2++;
         }
         int k = j - 1;
         while(k){
            cout << k;
            k--;
         }

         i++;
         cout << endl;
    }
    return 0;
}