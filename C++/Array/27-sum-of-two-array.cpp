#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n1 = 5, n2 = 4;
    int a1[n1] = {1, 3, 5, 7, 9};
    int a2[n2] = {2,4, 6, 8};
    
    //Approach 2
    vector<int> v;

    int i = n1 - 1, j = n2 - 1, carry = 0;
    
    while( i >= 0 && j >= 0){
        int val1 = a1[i];
        int val2 = a2[j];

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum %10;
        v.push_back(sum);
        i--; j--;
    }

    while(i >= 0){
        int sum = a1[i] + carry;
        carry = sum / 10;
        sum = sum %10;
        v.push_back(sum);
        i--;
    }

    while(j >= 0){
        int sum = a2[j] + carry;
        carry = sum / 10;
        sum = sum %10;
        v.push_back(sum);
        j--;
    }

    while(carry != 0){
        int sum = carry;
        carry = sum / 10;
        sum = sum %10;
        v.push_back(sum);
    }
    
    int s = 0, e = v.size() - 1;
    while(s < e){
        swap(v[s++], v[e--]);
    } 
    for(int k = 0; k < v.size(); k++)cout << v[k];


    // Approach 1
    // int num1 = 0, num2  = 0;
    // for(int i = 0; i < n1; i++){
    //     num1 = num1 + a1[i];
    //     num1 *= 10;
    // }
    // for(int i = 0; i < n2; i++){
    //     num2 = num2 + a2[i];
    //     num2 *= 10;
    // }
    // int ans = (num1 + num2) / 10;
    // cout << ans << endl;

    return 0;
}