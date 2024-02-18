#include <iostream>
using namespace std;

int main(){

    int a[5] = {1, 3, 5, 7, 9};
    int b[5] = {2, 3, 5, 8, 9};
    
    int a1 = 0, b1 = 0;
    while(a1 < 5 && b1 < 5){
        if(a[a1] == b[b1]){cout << a[a1] << " ";a1++;b1++;}
        else if(a[a1] < b[b1]){a1++;}
        else{b1++;}
    }

    return 0;
}