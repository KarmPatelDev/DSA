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

int getLength(Node * &head){
    
    Node * temp = head;
    int cnt = 0;
    while(temp != NULL){
    temp = temp -> next;
    cnt++;
    }

    return cnt;
}


// Approach 1 using iteration
void reverseHead(Node * &head){

    Node * temp = NULL;
    Node * current = head;

    while(current != NULL){
    current = head -> next;
    head -> next = temp;
    temp = head;
    head = current;
    }
    head = temp;
    
}


/*
// Approach 2 using recursion
void reverse(Node * &head, Node * &temp, Node * &current){
    if(current == NULL){
        head = temp;
        return;
    }

    Node * forward = current -> next;
    reverse(head, current, forward);
    current -> next = temp;

}

void reverseHead(Node * &head){
    Node * temp = NULL;
    Node * current = head;

    reverse(head, temp, current);
}
*/

/*
Approach 3 using recursion
Node* reverse(Node * &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node * newNode = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;


    return newNode;
}

void reverseHead(Node * &head){head = reverse(head);}
*/

void print(Node * &head){
    
    Node * temp = head;
    while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
    }
    cout << endl;
}

int main(){
    
    Node * tail = NULL;
    Node * head = NULL;

    insertionHead(head, tail, 50);
    insertionHead(head, tail, 60);
    insertionHead(head, tail, 70);
    insertionHead(head, tail, 80);
    insertionHead(head, tail, 90);
    print(head);
    cout << head -> data << " " << getLength(head) << endl;
    reverseHead(head);
    print(head);


    return 0;
}