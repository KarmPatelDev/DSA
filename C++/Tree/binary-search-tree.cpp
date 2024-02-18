#include <iostream>
#include <queue>

using namespace std;

class node{
      public:
      node* left;
      int data;
      node* right;

      node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
      }
};

node* buildBST(node* root, int data){

      if(root == NULL){
            root = new node(data);
            return root;
      }

      if(root -> data > data){
            root -> left = buildBST(root -> left, data);
      }
      else{
            root -> right = buildBST(root -> right, data);
      }
      return root;
}

void buildBSTTree(node* &root){
      
      int data;
      cout << "Enter The Data: ";
      cin >> data;

      while(data != -1){
           root = buildBST(root, data);
           cin >> data;
      }
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

void inordertraversal(node* root){
      if(root== NULL){
            return;
      }
      inordertraversal(root -> left);
      cout<<root -> data<< " ";
      inordertraversal(root -> right);
}
node* deletion(node* &root, int data){
       
       if(root == NULL){
            return root;
       }

       if(root -> data == data){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                  delete root;
                  return NULL;
            }
            else if(root -> left != NULL && root -> right == NULL){
                  node* temp = root -> left;
                  delete root;
                  return temp;
            }
            else if(root -> left == NULL && root -> right != NULL){
                  node* temp = root -> right;
                  delete root;
                  return temp;
            }
            else if(root -> left != NULL && root -> right != NULL){
                  node* temp ;
                  temp = root -> left;
                  while(temp -> right != NULL){temp = temp -> right;}
                  int max = temp -> data;
                  root -> data = max;
                  root -> left = deletion(root -> left, max);
                  // delete temp;
                  // if((root -> left) -> data == max )
                  // {
                  //       root -> left = NULL; return root;
                  // }
                  // temp = root -> left;
                  // while((temp -> right) -> data != max){temp = temp -> right;}
                  // temp -> right = NULL;
                  return root;
            }
       }
       else if(root -> data > data){
            root -> left = deletion(root -> left, data);
            return root;
       }
       else{
            root -> right = deletion(root -> right, data);
            return root;
       }
}

int main(){
      node * root = NULL;
      buildBSTTree(root);
      inordertraversal(root);
      cout<<endl;
      treeLevelOrederTraversal(root); 
      cout<<"deletion"<<endl;
      root = deletion(root, 80);
      treeLevelOrederTraversal(root); 
      cout<<endl;
      root = deletion(root, 70);
      treeLevelOrederTraversal(root); 
      cout<<endl;
      root = deletion(root, 30);
      treeLevelOrederTraversal(root);
      cout<<endl;
      inordertraversal(root);
      return 0;
}