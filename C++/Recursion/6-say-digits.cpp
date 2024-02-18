#include <iostream>
using namespace std;

void sayDigit(string arr[], int n){
    if(n == 0)return ;
    int digit = n%10;
    n /= 10;
    // cout << arr[digit] << " "; Shows Reverse Answer in Tail 
    sayDigit(arr, n);   
    cout << arr[digit] << " ";   
}

int main(){
    int n;
    string arr[10]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout << "Enter The Number: ";
    cin >> n;
    cout << endl << endl << endl;
    sayDigit(arr, n);
    cout << endl << endl << endl;
    return 0;
}