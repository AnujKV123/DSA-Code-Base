#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            this->next = NULL;
        }

};

void insertAtHead(node* &head, node* &tail, int d){
    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(d);
        temp->next = head;
        head = temp;
    }
    
}

void insertAtTail(node* &head, node* &tail, int d){
    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else{
        node* temp = new node(d);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(node* &head, node* &tail, int position, int d){
    if(position == 1){
        insertAtHead(head, tail, d);
        return;
    }
    node* temp = head;
    int cnt=1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }
    node* newNode = new node(d);
    newNode->next = temp->next;
    temp->next = newNode;

}

void print(node* &head){
     node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
       temp =temp->next;
    }
    cout<<endl;
}

// function for reversing the linked list

void reverseList(node* &head){
    if(head == NULL || head->next == NULL){
        return;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return;
}

int main(){
    node* head = NULL;
    node* tail = NULL;

    insertAtPosition(head, tail, 1, 20);
    print(head);
    insertAtPosition(head, tail, 1, 10);
    print(head);
    insertAtPosition(head, tail, 3, 30);
    print(head);
    insertAtPosition(head, tail, 4, 40);
    print(head);
    insertAtTail(head, tail, 50);
    print(head);
    cout<<"Head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;
    reverseList(head);
    print(head);
    
    return 0;
}
