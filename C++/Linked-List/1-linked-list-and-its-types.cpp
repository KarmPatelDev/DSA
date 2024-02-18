#include <iostream>
using namespace std;

class Node{
      public:

      int data;
      Node * next;

};

int main(){
    
    Node * newNode, *head = NULL, * temp;
    int choice = 1;

    while(choice){
    
    newNode = new Node();

    cout << "Enter The Number :";
    cin >> newNode -> data;
    newNode -> next = NULL;

    if(head == NULL){
        head = temp = newNode;
    }
    else{
        temp -> next = newNode;
        temp = newNode;
    }
    
    cout << "To Enter Another Number Press 1 else 0: ";
    cin >> choice;

    }

    temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    return 0;
}