#include <iostream>
#include <vector>
using namespace std;

void keypadProblem(string name, string output, int index, vector<string> & ans, string mapping[]){
    
    // Base case
    if(index >= name.length()){
        ans.push_back(output);
        return; 
    }
    

    int number = name[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        keypadProblem(name, output, index + 1, ans, mapping);
        output.pop_back();
    }

} 

int main(){

    string name = "45";
    
    string output = "";
    vector<string> ans;
    int index = 0;
    
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    keypadProblem(name, output, index, ans, mapping);
    
    string i;
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}