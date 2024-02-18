#include <iostream>
using namespace std;

class node{
      public: 
      int data;
      node *left;
      node *right;

      node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
      }
};

node* buildTree(node* root){
      
      int data;
      cout << "Enter The Root Data" << endl;
      cin >> data;
      root = new node(data);

      if(data == -1){return NULL;}

      cout << "Enter The Data For Left Node of " << data << endl;
      root -> left = buildTree(root -> left);
      cout << "Enter The Data For Right Node of " << data << endl;
      root -> right = buildTree(root -> right);

      return root;
}

void morrisTraversal(node* root){
     
     node* curr = root;

     while(curr != NULL){

        if(curr -> left == NULL){
            cout << curr -> data << " ";
            curr = curr -> right;
        }
        else{
            node* pred = curr -> left;
            while(pred -> right != NULL && pred -> right != curr)pred= pred -> right;

            if(pred -> right == NULL){
                pred -> right = curr;
                curr = curr -> left;
            }
            else{
                pred -> right = NULL;
                cout << curr -> data << " ";
                curr = curr -> right;
            }
        }
     }
}

// 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
int main(){
    
    node* root = NULL;
    root = buildTree(root);
    morrisTraversal(root);
    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)