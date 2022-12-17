// ****************************** Construct Tree from Inorder & Preorder *******************************

/*  Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

    Example 1:

    Input:
    N = 4
    inorder[] = {1 6 8 7}
    preorder[] = {1 6 7 8}
    Output: 8 7 6 1

    Example 2:

    Input:
    N = 6
    inorder[] = {3 1 4 0 5 2}
    preorder[] = {0 1 3 4 2 5}
    Output: 3 4 1 5 2 0
    Explanation: The tree will look like
           0
        /     \
       1       2
    /   \    /
   3    4   5
 */ 

//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    void findNodeToIndex(int in[], int n, map<int, int> &nodeToIndex){
        for(int i=0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int pre[], int n, int &index, int inorderStart, int inorderEnd,
    map<int, int> &nodeToIndex){
        if(index >= n || inorderStart>inorderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->left = solve(in, pre, n, index, inorderStart, position-1, nodeToIndex);
        root->right = solve(in, pre, n, index, position+1, inorderEnd, nodeToIndex);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int, int> nodeToIndex;
        int index = 0;
        
        findNodeToIndex(in, n, nodeToIndex);
        
        Node* ans = solve(in, pre, n, index, 0, n-1, nodeToIndex);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends