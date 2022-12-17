// inserting new node at Head in linked list

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        // costructor ***************************
        node(int data){
            this->data = data;
            this->next = NULL;
        }
        //  Distructor **************************
        ~node(){
            int value = this->data;
            // memory free ***********************
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory is free for node for node with data "<<value<<endl;
        }
};

// inserting new node at Head *********************************************************
void insertAtHead(node* &head, node* &tail, int d){
    //  create new node
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

// inserting new node at Tail **********************************************************
void insertAtTail(node* &head, node* &tail, int d){
    //  create new node
    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    node* temp = new node(d);
    tail->next = temp;
    // tail = tail->next;
    tail = temp;
}

// inserting new node at Position ********************************************************
void insertAtPosition(node* &tail ,node* &head, int position, int d){

    // insert at start *************************
    if(position==1){
        insertAtHead(head, tail, d);
        return;
    }
    node* temp = head;
    int cnt = 1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    // insetr at Tail(Last Position) ************
    if(temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    //  create a new node for d ******************
    node* newNode = new node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

//  Deleting node from linked list ***************************************************************
void deleteNode(int position, node* &head, node* &tail){

    // deleting first or start node ****************
    if(position == 1){
        node* temp = head;
        head = head->next;

        // memory free for start node ***************
        temp->next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node or last node ******
        node* curr = head;
        node* prev = NULL;
        int cnt = 1;
        while (cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;

        if(prev->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
        
    }
}


// traversing the node inside linked list *****************************************************
void Print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    // node* node1 = new node(10);

    // head pointed to node1
    node* head = NULL;
    node* tail = NULL;
    Print(head);
    insertAtHead(head, tail, 12);
    Print(head);
    insertAtHead(head, tail, 15);
    Print(head);

    insertAtTail(head ,tail, 12);
    Print(head);
    insertAtTail(head ,tail, 15);
    Print(head);
    
    insertAtPosition(tail,head, 5, 25);
    Print(head);
    cout<<"Head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    deleteNode(5, head, tail);
    Print(head);
    cout<<"Head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    return 0;
}