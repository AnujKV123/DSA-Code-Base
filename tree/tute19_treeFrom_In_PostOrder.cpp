// ************************** Tree from Postorder and Inorder *******************************

/*  Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct 
    the binary tree from these traversals.

    

    Example 1:

    Input:
    N = 8
    in[] = 4 8 2 5 1 6 3 7
    post[] =8 4 5 2 6 7 3 1
    Output: 1 2 4 8 5 3 6 7
    Explanation: For the given postorder and
    inorder traversal of tree the  resultant
    binary tree will be
            1
        /      \
      2         3
    /  \      /  \
   4    5    6    7
    \
     8

    

    Example 2:

    Input:
    N = 5
    in[] = 9 5 2 3 4
    post[] = 5 9 3 4 2
    Output: 2 9 5 4 3
    Explanation:  
    the  resultant binary tree will be
               2
            /     \
           9       4
            \     /
             5   3 
*/ 

//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void findNodeToIndex(int in[], int n, map<int, int> &nodeToIndex){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int n, int &index, int inorderStart, int inorderEnd,
map<int, int> &nodeToIndex){
    if(index < 0 || inorderStart>inorderEnd){
        return NULL;
    }
    
    int element = post[index--];
    Node* root = new Node(element);
    int position = nodeToIndex[element];
    
    // recursive calls
    // in case of inOrder and postOrder we first build right sub tree.
    root->right = solve(in, post, n, index, position+1, inorderEnd, nodeToIndex);
    root->left = solve(in, post, n, index, inorderStart, position-1, nodeToIndex);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int, int> nodeToIndex;
    int index = n-1;
    
    findNodeToIndex(in, n, nodeToIndex);
    
    Node* ans = solve(in, post, n, index, 0, n-1, nodeToIndex);
    return ans;
}
