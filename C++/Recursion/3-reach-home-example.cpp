#include <iostream>
using namespace std;

void reachHome(int dest, int src){
    
    if(src == dest)cout << "Mummy Hu Aavi Gyo, Nasto Banay";

    return reachHome(dest, src+1);
}

int main(){
    
    int dest = 50;
    int src = 1;
    reachHome(dest, src);
    return 0;
}