#include<iostream>
using namespace std;

/********************************************************************/

    // Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
/********************************************************************/
node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* mergeList(node* left, node* right){
    if(!left) return right;
    if(!right) return left;
    
    node* ans = new node(-1);
    node* newAns = ans;
    while(left && right){
        if(left->data < right->data){
            newAns->next = left;
            newAns = left;
            left = left->next;
        }
        else{
            newAns->next = right;
            newAns = right;
            right = right->next;
        }
    }
    while(left){
        newAns->next = left;
        newAns = left;
        left = left->next;
    }
    while(right){
        newAns->next = right;
        newAns = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    // Write your code here.
    if(!head || !head->next) return head;
    
    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return mergeList(left, right);
}
