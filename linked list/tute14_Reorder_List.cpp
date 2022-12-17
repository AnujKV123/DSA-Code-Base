// ********************************** Reorder List **************************************

// know more :- https://leetcode.com/problems/reorder-list/description/


#include<bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {

    // ******************************* Approch-1 ******************************

        // ListNode* fast = head;
        // ListNode* slow = head;
        // ListNode* first = head;

        // while(fast && fast->next){
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }

        // ListNode* curr = slow->next;
        // ListNode* prev = NULL;
        // ListNode* Next = NULL;
        // while(curr){
        //     Next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr=Next;
        // }
        // slow->next = NULL;
        // ListNode* second = prev;

        // while(second){
        //     ListNode* temp1 = first->next;
        //     ListNode* temp2 = second->next;
        //     first->next = second;
        //     second->next = temp1;
        //     first = temp1;
        //     second = temp2;
        // }

    // ******************************* Approch-2 ******************************

        if(!head || !head->next || !head->next->next) return;

        ListNode* end = head;

        while(end->next->next){
            end = end->next;
        }

        end->next->next = head->next;
        head->next = end->next;
        end->next = NULL;
        reorderList(head->next->next);

    }
};