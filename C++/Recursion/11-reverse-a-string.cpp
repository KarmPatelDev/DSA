#include <iostream>
using namespace std;

void reverseString(string & name, int i, int j){
      
      if(i > j)return ;

      swap(name[i], name[j]);
      reverseString(name, i + 1, j - 1);
}

int main(){
    string name = "karm patel";
    
    int i;
    for(i = 0; name[i] != '\0'; i++){}
    reverseString(name, 0, i - 1);

    cout << "Reverse String is " << name;
}