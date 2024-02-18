#include <iostream>
using namespace std;

int findPower(int a, int b){
    
    // For Big Value use Long long int

    if(b == 0)return 1;
    
    if(b == 1)return a;

    if(b % 2 == 0){
        return findPower(a, b/2) * findPower(a, b/2);
    }
    else{
        return a * findPower(a, b/2) * findPower(a, b/2);
    }      

}
int main(){
    
    int a, b;

    cout << "Enter The Base and Power, Respectively: ";
    cin >> a >> b;

    cout << "Answer is " << findPower(a, b);

    return 0;
}