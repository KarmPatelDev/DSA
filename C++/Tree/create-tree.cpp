#include <iostream>
#include <queue>
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

node* buildTreeLevelOrder(node * root){
      
      queue<node*> q;
      int data;
      cout << "Enter The Root Data" << endl;
      cin >> data;
      root = new node(data);
      q.push(root);

      while(!q.empty()){
            node * temp = q.front();
            q.pop();

            cout << "Enter Left Node For: " << temp -> data << endl;
            int leftData;
            cin >> leftData;

            if(leftData != -1){
                  temp -> left = new node(leftData);
                  q.push(temp -> left);
            }

            cout << "Enter Right Node For: " << temp -> data << endl;
            int rightData;
            cin >> rightData;

            if(rightData != -1){
                  temp -> right = new node(rightData);
                  q.push(temp -> right);
            }
      }
      
      return root;
}

void treeLevelOrederTraversal(node *root){

      queue<node*> q;
      q.push(root);
      q.push(NULL); // For Separator

      while(!q.empty()){

            node * temp = q.front();
            q.pop();

            if(temp == NULL){
                  cout << endl;  // level wise order
                  if(!q.empty()){
                        q.push(NULL);   // For Separator
                  }
            }
            else{
                  
                  cout << temp -> data << " ";  //print the value

                  // store left chile in queue
                  if(temp -> left != NULL){
                         q.push(temp -> left);
                  }
                  
                  // store a right chile in a queue
                  if(temp -> right != NULL){
                        q.push(temp -> right);
                  }

            }

      }

}


void preOrder(node * root){
     
    if(root == NULL)return;

    cout <<  root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);

}

void postOrder(node * root){

    if(root == NULL)return;

    postOrder(root -> left);
    postOrder(root -> right);
    cout <<  root -> data << " ";
    
}

void inOrder(node * root){

    if(root == NULL)return;

    inOrder(root -> left);
    cout <<  root -> data << " ";
    inOrder(root -> right);

}


int main(){
    
    node* root = NULL;
    root = buildTreeLevelOrder(root);
    treeLevelOrederTraversal(root);
    return 0;
}