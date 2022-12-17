#include<iostream>
#include<queue>
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

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp= temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}


Node* deleteFromBST(Node* root, int val){

    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        
        // 0 chils
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // for left child
        if(root->left != NULL && root ->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // for right child
        if(root->right != NULL && root ->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){

            int mini = minValue(root->right) ->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > val){
        // going to the left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        // going to the right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main(){
    
    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    tekeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing the Inorder"<<endl;
    inorder(root);

    cout<<endl<<"Printing the preorder"<<endl;
    preorder(root);

    cout<<endl<<"Printing the postorder"<<endl;
    postorder(root);

    cout<<"Minimum value of Tree : "<<minValue(root)->data<<endl;

    cout<<"Maximum value of Tree : "<<maxValue(root)->data<<endl;

    root = deleteFromBST(root, 21);

        cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing the Inorder"<<endl;
    inorder(root);

    cout<<endl<<"Printing the preorder"<<endl;
    preorder(root);

    cout<<endl<<"Printing the postorder"<<endl;
    postorder(root);

    cout<<"Minimum value of Tree : "<<minValue(root)->data<<endl;

    cout<<"Maximum value of Tree : "<<maxValue(root)->data<<endl;

    return 0;

    // 10 8 21 7 27 5 4 3 -1
}