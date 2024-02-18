#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){}

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertionHead(Node * &head,Node * &tail, int data){
    if(tail == NULL){
        Node * newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else{
        Node * newNode = new Node(data);
        tail -> next = newNode;
        tail = newNode;
    }
}

int midValue(Node * &head){

    Node * temp = head;
    Node * mid = head;

    while(temp != NULL){
        temp = temp -> next;
        if(temp != NULL){
            temp = temp -> next;
            mid = mid -> next;
        }
        
        
    }

    return mid -> data;
}

int main(){
    
    Node * tail = NULL;
    Node * head = NULL;

    insertionHead(head, tail, 50);
    insertionHead(head, tail, 60);
    insertionHead(head, tail, 70);
    insertionHead(head, tail, 80);
    insertionHead(head, tail, 90);
    int mid = midValue(head);
    cout << "The Mid Value is " << mid << endl;

    return 0;
}