#include<iostream>
using namespace std;

/********************************/
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

/********************************/
void insertAtTail(Node* &tail, Node* temp){
    tail->next = temp;
    tail = temp;
}
Node* sortList(Node *head)
{
    // Write your code here.
//     Node* temp = head;
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;
    
//     while(temp){
//         if(temp->data == 0) zeroCount++;
//         if(temp->data == 1) oneCount++;
//         if(temp->data == 2) twoCount++;
        
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp){
//         if(zeroCount !=0){
//             temp ->data = 0;
//             zeroCount--;
//         }
//         else if(oneCount !=0){
//             temp ->data = 1;
//             oneCount--;
//         }
//         else if(twoCount !=0){
//             temp ->data = 2;
//             twoCount--;
//         }
//         temp = temp->next;
//     }
//     return head;
    
    Node* zeroN = new Node(-1);
    Node* zeroT = zeroN;
    Node* oneN = new Node(-1);
    Node* oneT = oneN;
    Node* twoN = new Node(-1);
    Node* twoT = twoN;
    
    Node* temp = head;
    while(temp != NULL){
        int value = temp->data;
        if(value == 0){
            insertAtTail(zeroT, temp);
        }
        else if(value == 1){
            insertAtTail(oneT, temp);
        }
        else if(value == 2){
            insertAtTail(twoT, temp);
        }
        temp = temp->next;
    }
    
    if(oneN->next != NULL){
        zeroT->next = oneN->next;
    }
    else{
        zeroT->next = twoN->next;
    }
    oneT->next = twoN->next;
    twoT->next = NULL;
    head = zeroN->next;
    
    delete zeroN;
    delete oneN;
    delete twoN;
    
    return head;
    
}
