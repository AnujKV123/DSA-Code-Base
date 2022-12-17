// ******************************************** merge two BST *******************************************

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
// less optimal approch tc = O(m+n), and sc = O(m+n)

void solve(TreeNode<int> *root, vector<int> &in){
    if(!root) return;
    
    solve(root->left, in);
    in.push_back(root->data);
    solve(root->right, in);
}

vector<int> mergeArray(vector<int> &a, vector<int> &b){
    
    vector<int> ans(a.size() + b.size());
    int i=0, j=0, k = 0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
             ans[k++] = b[j];
            j++;
        }
    }
    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j < b.size()){
         ans[k++] = b[j];
        j++;
    }
    return ans;
}

TreeNode<int> *createBst(vector<int> &in, int s, int e){
    if(s>e) return NULL;
    
    int mid = s+(e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = createBst(in, s, mid-1);
    root->right = createBst(in, mid+1, e);
    return root;
}

/****************************************************************/ 

/***************************************************************/
// optimal approch tc = O(m+n) ans sc = O(h1+h2)

// converting a bst int Doubly Linked List
void convertInToDLL(TreeNode<int> *root, TreeNode<int>* &head){
//     base case 
    if(root == NULL) return;
    
    convertInToDLL(root->right, head);
    
    root->right = head;
    if(head) head->left = root;
    head = root;
    
    convertInToDLL(root->left, head);
}

// merging two doubly linked list
TreeNode<int>* mergeLL(TreeNode<int>* head1, TreeNode<int>* head2){
    
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    
    while(head1 && head2){
        if(head1->data <head2->data){
            if(!head){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(!head){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

// count nodes
int countNodes(TreeNode<int>* head){
    TreeNode<int>* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->right;
    }
    return count;
}

// create BST from sorted linked list
TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n){
    if(n <=0 || !head) return NULL;
    
    TreeNode<int>* left = sortedLLToBST(head, n/2);
    
    TreeNode<int>* root = head;
    root->left = left;
    head = head->right;
    
    root->right = sortedLLToBST(head, n-n/2-1);
    
    return root;
}

/************************************************************/

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    /*vector<int> node1, node2;
    solve(root1, node1);
    solve(root2, node2);
    
    vector<int>ans = mergeArray(node1, node2);
    int s = 0, e = ans.size()-1;
    return createBst(ans, s, e);*/
    
    TreeNode<int>* head1 = NULL;
    convertInToDLL(root1, head1);
    head1->left = NULL;
    
    TreeNode<int>* head2 = NULL;
    convertInToDLL(root2, head2);
    head2->left = NULL;
    
    TreeNode<int>* head = mergeLL(head1, head2);
    return sortedLLToBST(head, countNodes(head));
    
}