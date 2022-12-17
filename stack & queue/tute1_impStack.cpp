#include<iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int top;
        int size;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    
    stack st(5);

    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);

    cout<<st.peek()<<endl;

    st.pop();
    
    cout<<st.peek()<<endl;
    return 0;
}