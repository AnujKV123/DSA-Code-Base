// ********************************* Normal BST To Balanced BST  **********************************

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, vector<int>&in){
    
    if(!root) return;
    solve(root->left, in);
    in.push_back(root->data);
    solve(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> inorder;
    solve(root, inorder);
    TreeNode<int>* ans = new TreeNode<int>(inorder[0]);
    TreeNode<int>* curr = ans;
    
    for(int i=1;i<inorder.size(); i++){
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return ans;
}
