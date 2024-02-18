#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> nums, vector<int> output, int index, vector<vector<int>> & ans){
    
    // Base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // Exclude
    subset(nums, output, index + 1, ans);

    // Include
    int element = nums[index];
    output.push_back(element);
    subset(nums, output, index + 1, ans);
    
} 

int main(){

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;

    subset(nums, output, index, ans);
    
    vector<int> v1;
    int v2;

    for(auto v: ans){
        cout << "{";
        for(auto v2: v){
            cout << v2;
            if(v2 != v.back())cout << ", ";
        }
        cout << "} ";
    }

    return 0;
}