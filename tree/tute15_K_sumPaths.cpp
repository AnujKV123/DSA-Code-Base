// ************************************ K Sum Paths ******************************************

/*  Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
    A path may start from any node and end at any node in the downward direction.


    Example 1:

    Input:      
    Tree = 
              1                               
            /   \                          
           2     3
    K = 3
    Output: 2
    Explanation:
    Path 1 : 1 + 2 = 3
    Path 2 : only leaf node 3

    Example 2:

    Input: 
    Tree = 
                1
            /     \
          3        -1
        /   \     /   \
       2     1   4     5                        
            /   / \     \                    
           1   1   2     6    
    K = 5                    
    Output: 8
    Explanation:
    The following paths sum to K.  
    3 2 
    3 1 1 
    1 3 1 
    4 1 
    1 -1 4 1 
    -1 4 2 
    5 
    1 -1 5  
*/ 


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
    void solve(Node* root, int k, vector<int> path, int &ans){
        
        if(!root) return;
        
        path.push_back(root->data);
        
        solve(root->left, k, path, ans);
        solve(root->right, k, path, ans);
        
        int sum = 0;
        for(int i = path.size()-1; i>=0; i--){
            sum = sum + path[i];
            if(sum == k){
                ans++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int ans = 0;
        
        solve(root, k, path, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends

