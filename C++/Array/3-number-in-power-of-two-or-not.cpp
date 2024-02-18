#include <iostream>
using namespace std;

 int main(){
    
    int n;
    cout << "Enter The Number: ";
    cin >> n;

    if((n & (n - 1)) == 0)cout << "The number is in power of 2";
    else cout << "The number is not in power of 2";

    return 0;
 }

 // Time Complexity = O(1)