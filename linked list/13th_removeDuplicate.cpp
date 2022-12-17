// ********************************** Remove Duplicates from Sorted List II *************************************

 /* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

    Example 1:

    Input: head = [1,2,3,3,4,4,5]
    Output: [1,2,5]

    Example 2:

    Input: head = [1,1,1,2,3]
    Output: [2,3]
 */

#include<iostream>
using namespace std;


/**
 * Definition for singly-linked list.*/
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 /*********************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* curr = head;
        ListNode* ans = curr;
        ListNode* prev = NULL;
        
        while(curr && curr->next){
            
            if(curr->val == curr->next->val){
                
                curr->next = curr->next->next;
                if(curr && curr->next && (curr->val != curr->next->val)){
                    if(prev == NULL){
                        ListNode* del = curr;
                        curr = curr->next;
                        ans = curr;
                        del = NULL;
                    }
                    else{
                        prev->next = curr->next;
                        curr = prev->next;
                    }
                    
                }
                else if(!curr->next){
                    if(prev == NULL){
                        curr = NULL;
                        ans = NULL;
                    }
                    else{
                        prev->next = NULL;
                    }
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return ans;
    }
};