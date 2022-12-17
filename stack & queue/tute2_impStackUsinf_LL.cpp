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

void push(Node* &top, int data){
    if(!top){
        Node* temp = new Node(data);
        top = temp;
    }
    else{
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
    }
}

void pop(Node* &top){
    if(top){
        Node* ptr = top;
        top = top->next;
        ptr = NULL;
        delete ptr;
    }
    else{
        cout<<"Stack is empty: "<<endl;
    }
}

void peek(Node* top){
    if(top){
        cout<<endl<<"Tpo is: "<<top->data<<endl;
    }
    else{
        cout<<"Stack is empty: "<<endl;
    }
}

void print(Node* top){
    if(top){
        while(top){
            cout<<top->data<<" ";
            top = top->next;
        }
    }
    else{
        cout<<"Stack is empty: "<<endl;
    }
}

int main(){
    Node* top = NULL;

    push(top, 5);
    // peek(top);
    // push(top, 10);
    // push(top, 11);
    // push(top, 12);
    // push(top, 13);
    // peek(top);
    print(top);
    pop(top);
    peek(top);
    
    return 0;
}