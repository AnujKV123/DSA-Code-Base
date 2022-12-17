#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
        next = NULL;
        this->data = d;
    }

    ~Node() {
        if (next != NULL) {
        delete next;
        }
    }

};

void push(Node* &front, Node* &rear, int data){
    if(!front && !rear){
        Node* temp = new Node(data);
        front = temp;
        rear = temp;
    }
    else{
        Node* temp = new Node(data);
        rear->next = temp;
        rear = rear->next;
    }
}

void pop(Node* &front, Node* &rear){
    if(front != rear->next){
        Node* ptr = front;
        front = front->next;
        
        if(front == rear->next){
            front = NULL;
            rear = NULL;
        }
        ptr = NULL;
        delete ptr;
    }
    else{
        cout<<"Queue is empty: "<<endl;
    }
}

void peek(Node* &front, Node* &rear){
    if(front){
        cout<<endl<<"front is: "<<front->data<<endl;
    }
    else{
        cout<<"Queue is empty: "<<endl;
    }
}

void print(Node* &front, Node* &rear){
    if(front){
        Node* temp = front;
        while(temp != rear->next){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    else{
        cout<<"Queue is empty: "<<endl;
    }
}

int main(){
    Node* front = NULL;
    Node* rear = NULL;

    push(front, rear, 5);
    peek(front, rear);
    push(front, rear, 10);
    push(front, rear, 11);
    push(front, rear, 12);
    push(front, rear, 13);
    peek(front, rear);
    print(front, rear);
    pop(front, rear);
    peek(front, rear);
    pop(front, rear);
    peek(front, rear);
    pop(front, rear);
    peek(front, rear);
    pop(front, rear);
    peek(front, rear);
    pop(front, rear);
    peek(front, rear);
    push(front, rear, 50);
    push(front, rear, 100);
    peek(front, rear);
    print(front, rear);
    return 0;
}