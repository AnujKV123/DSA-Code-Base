// *********************************** converting complete binary tree to min/max heap *******************************

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    
    if(d > root -> data){
        // inserting at right part
        root->right = insertIntoBST(root->right, d);
    }
    else{
        // inserting at left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void tekeInput(Node* &root){

    int data;
    cin>>data;
    while(data != -1){
       root = insertIntoBST(root, data);
        cin>>data;
    }
}

void inorder(Node* root, vector<int> &in) {
    //base case
    if(!root)  return ;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);

}

// process of ctrating min heap
void minHeap(Node* root, vector<int> in, int &i){
    if(!root) return;

    root->data = in[i++];
    minHeap(root->left, in, i);
    minHeap(root->right, in, i);

}

// process of ctrating max heap
void maxHeap(Node* root, vector<int> in, int &i){
    if(!root) return;

    maxHeap(root->left, in, i);
    maxHeap(root->right, in, i);
    root->data = in[i++];

}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
int main(){
    Node* root = NULL;
    vector<int> in;
    int i = 0;
    cout<<"Input elements for creating BST :"<<endl;
    tekeInput(root);

    cout<<"before converting to min heap :"<<endl;
    levelOrderTraversal(root);

    // converting to min heap
    inorder(root, in);
    minHeap(root, in, i);

    // converting to max heap
    // inorder(root, in);
    // maxHeap(root, in, i);

    cout<<"after converting to min heap :"<<endl;
    levelOrderTraversal(root);
    
    return 0;
}
// 5 3 2 4 7 6 8 -1