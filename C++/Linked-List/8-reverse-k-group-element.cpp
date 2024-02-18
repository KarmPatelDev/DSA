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
};

void printLL(Node * &head){
    
    Node * temp = head;
    while(temp != NULL){
    cout << temp -> data << " ";
    temp = temp -> next;
    }
    cout << endl;
}

Node * kGroupReverse(Node * head, int k){
       
       if(head == NULL){
        return NULL;
       }
    
       Node * next = NULL;
       Node * prev = NULL;
       Node * curr = head;
       int count = 0;

       if(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
       }
       
       if(next != NULL){
          head -> next = kGroupReverse(next, k);
       }
       
       return prev;
}

int main(){
    
    int data = 0;
    Node * head = NULL;
    Node * temp = head;

    while(1){
        cout << "Enter The Data: ";
        cin >> data;
        if(data == -1)break;
        Node * newNode = new Node(data);
        newNode -> next = temp;
        head = newNode;
        temp = head;
    }
    
    int k;
    cout << "Enter The K Number For Grouping: ";
    cin >> k;
    head = kGroupReverse(head, k);
    printLL(head);

    return 0;
}

