#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;

    int i = 1;
    while(i <= n){
        int count = i-1;
        while(count){
            cout << " ";
            count--;
        }
        int j = 1, count2 = i;
        while(j <= n-i+1){
            cout << count2;
            count2++;
            j++;

        }
        cout << endl;
        i++;
    }
    return 0;
}