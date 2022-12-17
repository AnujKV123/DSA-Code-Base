// ***************** Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) ****************

/*  Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on 
    the longest path from root to leaf node.
    If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

    Example 1:

    Input: 
            4        
        / \       
        2   5      
        / \ / \     
        7  1 2  3    
        /
        6
    Output: 13
    Explanation:
            4        
        / \       
        2   5      
        / \ / \     
        7  1 2  3 
        /
        6

    The highlighted nodes (4, 2, 1, 6) above are 
    part of the longest root to leaf path having
    sum = (4 + 2 + 1 + 6) = 13
 */ 

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node* root, int len, int &maxLen, int sum, int &maxSum){
        
        if(!root){
        
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, len+1, maxLen, sum, maxSum);
        solve(root->right, len+1, maxLen, sum, maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = 0;
        
        solve(root, len, maxLen, sum, maxSum);
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends