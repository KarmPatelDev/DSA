#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    
    // Arrays
    array<int, 5> a = {1, 5, 3, 9, 7};
    for(int i = 0; i < a.size(); i++)cout << a[i] << " ";
    cout << endl << "Element at 2nd position is " << a.at(2) << endl;
    cout << "Array empty or not --> " << a.empty() << endl;
    cout << "first element - " << a.front() << endl;
    cout << "last element - " << a.back() << endl;


    // Vector  // Time Complexity - O(n)
    vector<int> v;
    cout << "Capacity - " << v.capacity() << endl;
    v.push_back(1);
    cout << "Capacity - " << v.capacity() << endl;
    v.push_back(5);
    cout << "Capacity - " << v.capacity() << endl;
    v.push_back(3);
    cout << "Capacity - " << v.capacity() << endl;
    v.push_back(9);
    cout << "Capacity - " << v.capacity() << endl;
    v.push_back(7);
    cout << "Capacity - " << v.capacity() << endl;
    // when vector is full then it increase the capacity double at new location also copy all elements there and dump the old location
    cout << "size - " << v.size() << endl;
    cout << endl << "Element at 2nd position is " << v.at(2) << endl;
    cout << "first element - " << v.front() << endl;
    cout << "last element - " << v.back() << endl;
    for(int i : v){
        cout << i << " ";
    }cout << endl;
    v.pop_back();
    for(int i : v){
        cout << i << " ";
    }cout << endl;
    cout << "Capacity - " << v.capacity() << endl;
    cout << "size - " << v.size() << endl;
    v.clear();
    cout << "Capacity - " << v.capacity() << endl;
    cout << "size - " << v.size() << endl;
    vector<int> b(5, 1);
    for(int i : b){
        cout << i << " ";
    }cout << endl;
    vector<int> last(b);
    for(int i : last){
        cout << i << " ";
    }cout << endl;

    
    // Deque
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
     for(int i : d){
        cout << i << " ";
    }cout << endl;
    //d.pop_back();
    //d.pop_front();
     for(int i : d){
        cout << i << " ";
    }cout << endl;
    cout << "Element at first index --> " << d.at(1) << endl;
    cout << "first element - " << d.front() << endl;
    cout << "last element - " << d.back() << endl;
    cout << "Deque empty or not --> " << d.empty() << endl;
    cout << "size - " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "size - " << d.size() << endl;
    for(int i : d){
        cout << i << " ";
    }cout << endl;


    // List(use of doubly linklist)

    list<int> l;
    l.push_back(1);
    l.push_front(2);
    for(int i : l){
        cout << i << " ";
    }cout << endl;
    l.erase(l.begin());
     for(int i : l){
        cout << i << " ";
    }cout << endl;
    cout << "size - " << l.size() << endl;
    list<int> l1(5, 100);
    for(int i : l1){
        cout << i << " ";
    }cout << endl;
    list<int> l2(l1);
    for(int i : l2){
        cout << i << " ";
    }cout << endl;


    // Stack LIFO structure
    stack<string> s;
    s.push("Patel");
    s.push("Karm");
    s.push("Shaileshkumar");
    
    cout << "Top element - " << s.top() << endl;
    s.pop();
    cout << "Top element - " << s.top() << endl;
    cout << "size - " << s.size() << endl;
    cout << "Empty - " << s.empty() << endl;


    // Queue Time Complexity O(1)
    queue<string> q;
    q.push("Patel");
    q.push("Karm");
    q.push("Shaileshkumar");
    cout << "Top element - " << q.front() << endl;
    q.pop();
    cout << "Top element - " << q.front() << endl;
    cout << "size - " << q.size() << endl;
    cout << "Empty - " << q.empty() << endl;


    // Priority_Queue

    // Max Heap
    priority_queue<int> maxi;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(5);
    maxi.push(0);
    int maxi_size = maxi.size();
    for(int i = 0; i < maxi_size; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    mini.push(1);
    mini.push(3);
    mini.push(5);
    mini.push(0);   
    int mini_size = mini.size();
    for(int i = 0; i < mini_size; i++){
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;
    cout << "Mini Empty - " << mini.empty() << endl;
    cout << "Maxi Empty - " << maxi.empty() << endl;
    
    // Set

    set<int> set_s;
    set_s.insert(1);    // Time Complexity Of Insert, find, erase, count = O(logn)
                        // Time Complexity Of size, begin, end = O(1)
    set_s.insert(1);
    set_s.insert(1);
    set_s.insert(5);
    set_s.insert(5);
    set_s.insert(5);
    set_s.insert(6);
    set_s.insert(6);
    set_s.insert(9);
    set_s.insert(9);
    set_s.insert(9);
    for(auto i : set_s){
        cout << i << endl;
    }
    set<int> :: iterator it = set_s.begin();
    it++;
    set_s.erase(it);
    for(auto i : set_s){
        cout << i << endl;
    }
    cout << "5 present - " << set_s.count(5) << endl;
    cout << "6 present - " << set_s.count(6) << endl;

    set<int> :: iterator itr = set_s.find(6);
    for(auto it = itr; it != set_s.end(); it++)cout << *it << " ";
    cout << endl;


    // Map     // Un-order - O(1)
    map<int, string> m;
    m[1] = "patel";           // Time Complexity Of Insert, find, erase, count = O(logn)
                              // Time Complexity Of size, begin, end = O(1)
    m[5] = "karm";
    m[13] = "shaileshkumar";
    m.insert({8, "bheem"});
    for(auto i : m){
        cout << i.first << " ";
    }cout << endl;
    cout << "5 present - " << m.count(5) << endl;
    cout << "6 present - " << m.count(6) << endl;
    m.erase(13);
    for(auto i : m){
        cout << i.first << " ";
    }cout << endl;
    auto itr2 = m.find(5);
    for(auto i = itr2; i != m.end(); i++){
        cout << (*i).first << " ";
    }cout << endl;


    // Algorithm
     vector<int> v1;
     v1.push_back(5);
     v1.push_back(9);
     v1.push_back(1);
     v1.push_back(3);
     v1.push_back(15);

     cout << binary_search(v1.begin(), v1.end(), 15) << endl;
     cout << "lower bound - " << lower_bound(v1.begin(), v1.end(), 5) - v.begin() << endl;
     cout << "upper bound - " << upper_bound(v1.begin(), v1.end(), 4) - v.begin() << endl;

     int a1 = 3, b1 = 8;
     cout << "max = " << max(a1, b1) << endl;
     cout << "min = " << min(a1, b1) << endl;
     swap(a1, b1);
     cout << a1 << " " << b1 << endl;
    
    string str = "karmpatel";
    reverse(str.begin(), str.end());
    cout << str << endl;

    rotate(v1.begin(), v1.begin()+1, v1.end());
    for(int i : v1){
        cout << i << " ";
    }cout << endl;

    sort(v1.begin(), v1.end());   // It use intro sort = quick + heap + selection
    for(int i : v1){
        cout << i << " ";
    }cout << endl;

    return 0;
}