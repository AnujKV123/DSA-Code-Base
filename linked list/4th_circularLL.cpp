// initializing new node in linked list

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int d){
        this->data = d;
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

void insertNode(node* &tail, int element, int d){
    
    
    // empty list
    if(tail == NULL){
        node* newNode = new node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    // non-empty list
    else{
        // assuming that the element is present in the list
        node* curr = tail;

        while (curr->data != element){
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        node* temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
        
    }
    
}

// traversing in dubbly linked list
void print(node* tail){
    node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while (tail != temp);
    cout<<endl;
}

// deleting node in dubbly linked list
void deleteNode(node* &tail, int value){
    // if list is empty
    if(tail == NULL){
        cout<<"List is empty, please check again"<<endl;
        return;
    }
    else{
        // if list is non-empty

        // assuming that "value" is present in list
        node* prev = tail;
        node* curr = prev->next;

        while (curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1 node linked list
        if(curr == prev){
            tail = NULL;
        }

        // >=2 node linked list
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
        
    }
}

int main(){
    node* tail = NULL;

    // inserting element in empty list
    // insertNode(tail, 5, 3);
    // print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    deleteNode(tail, 7);
    print(tail);

    return 0;
}