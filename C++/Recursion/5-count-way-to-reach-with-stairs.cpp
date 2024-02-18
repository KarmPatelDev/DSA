#include <iostream>
using namespace std;

int wayOfreach(int stairs){
    
    if(stairs == 0)return  1;
    if(stairs < 0)return 0;

    return (wayOfreach(stairs - 1) + wayOfreach(stairs - 2));
}

int main(){

    int stairs = 5;
    cout << "The Number Of Ways is " << wayOfreach(stairs);
    return 0;
}