#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(){}

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor for deleting the node
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

int getLength(Node * &tail){

    Node * temp = tail -> next;
    int cnt = 0;
    do{
       temp = temp -> next;
       cnt++;
    }while(temp != tail -> next);
    return cnt;
}

void insertionHead(Node * &tail, int data){

    if(tail == NULL){
        Node * firstNode = new Node(data);
        tail = firstNode;
        tail->next = firstNode;
    }else{
        Node * firstNode = tail -> next;
        Node * newNode = new Node(data);
        newNode -> next = firstNode;
        tail -> next = newNode;
    }
}

void insertionTail(Node * &tail, int data){

    if(tail == NULL){
        Node * firstNode = new Node(data);
        tail = firstNode;
        tail->next = firstNode;
    }else{

        Node * firstNode = tail -> next;
        Node * newNode = new Node(data);
        tail -> next = newNode;
        newNode -> next = firstNode;
        tail = newNode;
    }
}

void insertionPos(Node * &tail, int pos, int data){
    
    if(pos == 1){
        insertionHead(tail, data);
    }else if(pos == (getLength(tail) + 1)){
        insertionTail(tail, data);
    }else{
        Node * temp = tail -> next;
        int cnt = 1;
        while(cnt < pos - 1){
            temp = temp -> next;
            cnt++;
        }
        Node * newNode = new Node(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
     
}

void deletionPos(Node * &tail, int pos){
    
    Node * temp = tail -> next;
    if(pos == 1){
        tail -> next = (tail -> next) -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
    int count = 1;
    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }
    Node * current = temp -> next;
    if(current -> next == tail -> next){tail = temp;}
    temp -> next = current -> next;
    current -> next = NULL;
    delete current;
    }

}

void print(Node * &tail){

    Node * temp = tail -> next;
    do{
    cout << temp -> data << " ";
       temp = temp -> next;
    }while(temp != tail -> next);
    cout << endl;
}

int main(){
    Node * tail = NULL;
    insertionTail(tail, 15);
    print(tail);
    insertionHead(tail, 25);
    print(tail);
    insertionTail(tail, 35);
    print(tail);
    insertionPos(tail, 3, 78);
    print(tail);
    deletionPos(tail, 4);
    print(tail);
    return 0;
}