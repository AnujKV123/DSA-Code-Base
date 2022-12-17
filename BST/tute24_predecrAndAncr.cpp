// ********************************* Find Predecessor And Successor In BST **********************************

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* temp = root;
    int pred = -1;
    int suce = -1;
    
    while(temp->data != key){
        if(temp->data > key){
            suce = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }
  BinaryTreeNode<int>* leftTree = temp->left;
    while(leftTree){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    BinaryTreeNode<int>* rightTree = temp->right;
    while(rightTree){
        suce = rightTree->data;
        rightTree = rightTree->left;
    } 
    
//     pair<int,int> ans = make_pair(pred, suce);
    
    return {pred, suce};
}
