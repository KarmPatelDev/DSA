#include <iostream>
using namespace std;

int main(){

    int n, ans;
    cout << "Enter The Element: ";
    cin >> n;

    if(n < INT_MIN || n > INT_MAX)return 0;

    while(n != 0){
        int rem = n % 10;
        ans = (ans * 10) + rem;
        n = n/10;
    }

    cout << "Reverse Number is " << ans;

    return 0;
}