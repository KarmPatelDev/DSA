#include <iostream>
using namespace std;

bool palindrome(string & name, int i, int j){
      
      if(i > j)return true;

      if(name[i] != name[j]){
        return false;
      }
      else{
        return palindrome(name, i + 1, j - 1);
      }
      
}

int main(){
    string name = "karm patel";
    
    int i;
    for(i = 0; name[i] != '\0'; i++){}

    if(palindrome(name, 0, i - 1)){  
       cout << "String is Palindrome" << endl;
    }
    else{
       cout << "String is not a Palindrome" << endl;
    }
}