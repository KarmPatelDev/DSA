#include <iostream>
using namespace std;

class kQueue{
    
    public:

    int n, k, freespot;
    int *front, *rear, *arr, *next;

    kQueue(int n, int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k; i++){front[i] = -1;rear[i] = -1;}
        next = new int[n];
        for(int i = 0; i < n; i++){next[i] = i+1;}
        freespot = 0;
    }

    void enqueue(int data, int qn){

        // OverFlow
        if(freespot == -1){
            cout << "No space is available" << endl;
            return;
        } 
        
        //find first index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //check whether first element
        if(front[qn - 1] == -1){front[qn - 1] = index;}
        else{
            //link new element to the prev element
            next[rear[qn - 1]] = index;
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qn - 1] = index;

        //push element
        arr[index] = data;

    }

    int dequeue(int qn){
        
        //underflow condition
        if(front[qn - 1] == -1){
            cout << "Queue UnderFlow" << endl;
            return -1;
        }

        //find index to pop
        int index = front[qn - 1];
        
        //front chqange to next element
        front[qn - 1] = next[index];

        //freeslot changing and linking
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

};

int main(){
    
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    return 0;
}