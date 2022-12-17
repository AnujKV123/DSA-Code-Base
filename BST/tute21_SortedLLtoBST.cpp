// ***************************************** Sorted Link List to BST *****************************************

// know More :- https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1?page=1&curated[]=6&sortBy=submissions

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
//   ************************************ Approch-1 ******************************

    // TNode* sortedListToBST(LNode *head) {
    //     //code here
    //     if(!head) return NULL;
        
    //     if(!head->next){
    //         TNode* node = new TNode(head->data);
    //         return node;
    //     }
        
    //     if(!head->next->next){
    //         TNode* r = new TNode(head->next->data);
    //         r->right = new TNode(head->data);
    //         return r;
    //     }
        
    //     LNode* fast = head;
    //     LNode* mid = head;
    //     LNode* prev = NULL;
        
    //     while(fast && fast->next){
    //         fast = fast->next->next;
    //         prev = mid;
    //         mid = mid->next;
    //     }
        
    //     TNode* root = new TNode(mid->data);
    //     prev->next = NULL;
    //     root->left = sortedListToBST(head);
    //     root->right = sortedListToBST(mid->next);
        
    //     return root;
        
    // }
    
// *********************************** Approch-2 *************************************** 

    LNode* findMid(LNode* start, LNode* end){
        LNode* fast = start;
        LNode* mid = start;
        
        while(fast!=end && fast->next!=end){
            fast = fast->next->next;
            mid = mid->next;
        }
        
        return mid;
    }

    TNode* findTree(LNode* start, LNode* end){
        
        if(start == end) return NULL;
        
        LNode* mid = findMid(start, end);
        
        TNode* root = new TNode(mid->data);
        root->left = findTree(start, mid);
        root->right = findTree(mid->next, end);
        
        return root;
    }
    
    TNode* sortedListToBST(LNode *head) {
        //code here
        return findTree(head, NULL);
        
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

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends