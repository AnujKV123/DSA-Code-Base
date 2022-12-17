// ******************************* Is Binary Tree is Heap ***********************************

/* Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0
 */ 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  bool isCBT(struct Node* root, int index, int count){
      if(!root) return true;
      
      if(index>=count) return false;
      else{
          bool left = isCBT(root->left, 2*index + 1, count);
          bool right = isCBT(root->right, 2*index + 2, count);
          
          return left&&right;
      }
  }
  
  bool isMaxOrder(struct Node* root){
      
      if(!root->left && !root->right) return NULL;
      
      if(!root->right){
          return (root->data > root->left->data);
      }
      else{
          return (root->left && root->right 
          && (root->data > root->right->data && root->data > root->left->data));
      }
  }
  
  int totalCount(struct Node* root){
      if(!root) return 0;
      
      int left = totalCount(root->left);
      int right = totalCount(root->right);
      int ans = left + right + 1;
      return ans;
  }
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int count = totalCount(tree);
        
        return (isCBT(tree, index, count) && isMaxOrder(tree));
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends