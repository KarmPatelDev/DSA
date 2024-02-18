#include <iostream>
using namespace std;

int fact(int n){
    
    //Base Condition
    if(n == 1){
        return 1;
    }

    //Recursive Relation
    return n * fact(n - 1);
}

int main(){

    int n;
    cout << "Enter The Number: ";
    cin >> n;
    cout << "The Factorial is " << fact(n);

}