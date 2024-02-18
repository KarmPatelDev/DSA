#include <iostream>
#include <vector>

using namespace std;

void permutation(string name, vector<string> & ans, int index){
    
    if(index >= name.length()){
       ans.push_back(name);
       return;
    }

    for(int i = index; i < name.length(); i++){
        swap(name[i], name[index]);
        permutation(name, ans, index + 1);
        swap(name[i], name[index]);
    }

}

int main(){
    
    string name = "abc";
    vector<string> ans;
    int index = 0;

    permutation(name, ans, index);
    
    string i;
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}