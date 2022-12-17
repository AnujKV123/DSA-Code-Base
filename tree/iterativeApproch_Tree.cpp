#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root){
    cout<<"Enter the data :  "<<endl;
    int data;
    cin>>data;

    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(Node* root){
    queue<Node*> q;
    stack<int> st;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            st.push(-1);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            st.push(temp->data);

            if(temp->right){
                q.push(temp->right);
            }

            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    while(!st.empty()){
        int elem = st.top();
        st.pop();
        if(elem == -1){
            cout<<endl;
        }
        else{
            cout<<elem<<" ";
        }
    }
}

void buildeFromlevelorder(Node* &root){
    queue<Node*> q;
    cout<<"Enter the root Node : "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter in left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter in right of "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void inorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}

void preorderIterative(Node* root)
{
    // create an empty stack
    stack<Node*> stack;
 
    // start from the root node (set current node to the root node)
    Node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            // print it, and finally set the current node to its right child
            cout << curr->data << " ";
            
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack
            curr = stack.top();
            stack.pop();
 
            curr = curr->right;
        }
    }
}

void postorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
 
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}

int main(){
    Node* root = NULL;
    // root = buildTree(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildeFromlevelorder(root);
    levelOrderTraversal(root);
    cout<<"Reversen levele order: ";
    reverseLevelOrderTraversal(root);
    // inorderIterative(root);
    // preorderIterative(root);
    // postorderIterative(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1