#include <iostream>
#include <vector>
using namespace std;

void subset(string name, string output, int index, vector<string> & ans){
    
    // Base case
    if(index >= name.length()){
        if(output.length() != 0){
        ans.push_back(output);
        } 
        return; 
    }

    // Exclude
    subset(name, output, index + 1, ans);

    // Include
    char element = name[index];
    output.push_back(element);
    subset(name, output, index + 1, ans);

} 

int main(){

    string name = "karm";
    
    string output = "";
    vector<string> ans;
    int index = 0;

    subset(name, output, index, ans);
    
    string i;
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}