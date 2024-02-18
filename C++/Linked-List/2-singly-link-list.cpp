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

void insertionHead(Node * &head, Node * &tail, int data){
    
    if(head == NULL){
        Node * firstNode = new Node(data);
        head = firstNode;
        tail = firstNode;
    }
    else{
    Node * temp = new Node(data);
    temp -> next = head;
    head = temp;
    }
}

void insertionTail(Node * &head, Node * &tail, int data){

    if(tail == NULL){
        Node * firstNode = new Node(data);
        head = firstNode;
        tail = firstNode;
    }
    else{
    Node * temp = new Node(data);
    tail -> next = temp;
    tail = temp;
    }
}

void insertionPos(Node * &head, Node * &tail, int pos, int data){
    
    if(pos == 1){
        insertionHead(head, tail, data);
        return;
    }

    Node * temp = head;
    int count = 1;
    
    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL){
        insertionTail(head, tail, data);
        return;
    }

    Node * newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;

}

void deletionPos(Node * &head, Node * &tail, int pos){
    
    
    Node * temp = head;
    //delete start node
    if(pos == 1){
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
    //delete any middle or last nodes
    int count = 1;
    while(count < pos - 1){
        temp = temp -> next;
        count++;
    }
    Node * current = temp -> next;
    if(current -> next == NULL){tail = temp;}
    temp -> next = current -> next;
    current -> next = NULL;
    delete current;
    }

}

void printLL(Node * &head){
    
    Node * temp = head;
    while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
    }
    cout << endl;
}

int main(){
    
    
    Node * head = NULL, * tail = NULL;

    insertionHead(head, tail, 15);
    printLL(head); 
    insertionTail(head, tail, 25);
    printLL(head);
    insertionPos(head, tail, 3, 22);
    printLL(head);
    deletionPos(head, tail, 1);
    printLL(head);

    return 0;
}