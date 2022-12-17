#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;

    node(int d){
        this->data = d;
        this->prev = NULL;
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

// traversing a dubly linked list
void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// gettting length of dublly linked list
int getLength(node* &head){
    int len = 0;
    node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// inserting node at head of dubbly linked list
void insertAtHead(node* &head, node* &tail , int d){
    if(head == NULL){
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else{
        node* temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// inserting node at tail of dubbly linked list
void insertAtTail(node* &head, node* &tail , int d){
    if(tail == NULL){
        node* temp = new node(d);
        tail = temp;
        head = temp;
    }
    else{
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
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
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

//  Deleting node from linked list ***************************************************************
void deleteNode(int position, node* &head, node* &tail){

    // deleting first or start node ****************
    if(position == 1){
        node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;

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

        // delete from tail
        if(curr->next == NULL){
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        }

        // delete from middle
        else{
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        }

        if(prev->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
        
    }
}


int main(){
    node* node1 = new node(10);
    node* head = NULL;
    node* tail = NULL;
    print(head);
    // cout<<getLength(head)<<endl;

    insertAtHead(head, tail, 20);
    print(head);
    insertAtHead(head, tail, 30);
    print(head);

    insertAtTail(head, tail, 40);
    print(head);
    insertAtTail(head, tail, 50);
    print(head);
    insertAtTail(head, tail, 60);
    print(head);

    insertAtPosition(tail, head, 6, 100);
    print(head);
    deleteNode(3, head, tail);
    print(head);

    return 0;
}