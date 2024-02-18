#include <iostream>
#include <math.h>
using namespace std;

int main(){
    
    int n, ans = 1, neg = 0;
    cout << "Enter The Number: ";
    cin >> n;
    
    if(n == 0){cout << "1";exit(0);}
    if(n < 0){n*=(-1);neg=1;}

    while(ans <= n){
    n = n ^ ans;
    ans = ans * 2;
    }
    
    if(neg == 1){cout << n*(-1);}
    else cout << n;

    return 0;
}