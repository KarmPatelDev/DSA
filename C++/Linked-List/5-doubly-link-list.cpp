#include <iostream>
using namespace std;

class Node{
     public: 
     Node * prev;
     int data;
     Node * next;

     Node(){}

     Node(int data){
        this -> prev = NULL;
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

int getLength(Node * &head){
    
    Node * temp = head;
    int cnt = 0;
    do{
    temp = temp -> next;
    cnt++;
    }while(temp != head);

    return cnt;
}

void insertionHead(Node * &head, Node * &tail, int data){
     
     if(head == NULL){
        Node * firstNode = new Node(data);
        head = firstNode;
        tail = firstNode;
        firstNode -> prev = tail;
        firstNode -> next = head;
        
     }else{
        Node * newNode = new Node(data);
        newNode -> next = head;
        head -> prev = newNode;
        tail -> next = newNode;
        newNode -> prev = tail;
        head = newNode;
     }
}

void insertionTail(Node * &head, Node * &tail, int data){
    
    if(tail == NULL){
        Node * firstNode = new Node(data);
        head = firstNode;
        tail = firstNode;
        firstNode -> prev = tail;
        firstNode -> next = head;
    }
    else{
        Node * newNode = new Node(data);
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
        tail -> next = head;
        head -> prev = tail;
    }
}

void insertionPos(Node * &head, Node * &tail, int pos, int data){

    if(pos == 1){
        insertionHead(head, tail, data);
    }
    else if(pos == (getLength(head)+1)){
        insertionTail(head, tail, data);
    }
    else{

        Node * temp = head;
        int cnt = 1;
        while(cnt < pos - 1){
            temp = temp -> next;
            cnt++;
        }
        Node * newNode = new Node(data);
        newNode -> next = temp -> next;
        newNode -> prev = temp;
        (temp -> next) -> prev = newNode;
        temp -> next = newNode;

    }
}

void deletionPos(Node * &head, Node * &tail, int pos){
     
     if(pos == 1){
        Node * temp = head;
        tail -> next = head -> next;
        (head -> next) -> prev = tail;
        head = head -> next;
        temp -> prev = NULL;
        temp -> prev = NULL;
        delete temp;
     }
     else{
        Node * temp = head;
        int cnt = 1;
        while(cnt < pos - 1){
            temp = temp -> next;
            cnt++;
        }
        Node * current = temp -> next;
        temp -> next = current -> next;
        current -> next -> prev = current -> prev;
        current -> next = NULL;
        current -> prev = NULL;
        delete current;
     }
}

void printLTR(Node * &head){
    
    Node * temp = head;
    do{
    cout << temp -> data << " ";
    temp = temp -> next;
    }while(temp != head);
    cout << endl;
}

void printRTL(Node * &tail){

    Node * temp = tail;
    do{
        cout << temp -> data << " ";
        temp = temp -> prev;
    }while(temp != tail);
    cout << endl;
}


int main(){
    
    Node * tail = NULL;
    Node * head = NULL;
    insertionHead(head, tail, 25);
    printLTR(head);
    insertionHead(head, tail, 50);
    printLTR(head);
    insertionHead(head, tail, 25);
    printLTR(head);
    insertionHead(head, tail, 50);
    printLTR(head);
    insertionPos(head, tail, 5, 85);
    printRTL(tail);
    deletionPos(head, tail, 5);
    printLTR(head);

    return 0;
}