// ********************************* Partial BST (check the given tree  is valid binary search tree or not) *************************

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool solve(BinaryTreeNode<int> *root, int min, int max){
    
    if(!root) return true;
    
    if(min <= root->data && max >= root->data){
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);
        
        return left&&right;
    }
    else return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return solve(root, INT_MIN, INT_MAX);
}