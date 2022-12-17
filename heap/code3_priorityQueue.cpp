#include<iostream>
#include<queue>
using namespace std;

int main(){

    // max heap
    priority_queue<int> q;

    q.push(1);
    q.push(5);
    q.push(3);
    q.push(4);
    cout<<"size of the queue is : "<<q.size()<<endl;

    cout<<"Top of the queue is : "<<q.top()<<endl;
    q.pop();
    cout<<"size of the queue is : "<<q.size()<<endl;
    cout<<"Top of the queue is : "<<q.top()<<endl;

    if(q.empty()){
        cout<<"queue is empty :"<<endl;
    }
    else{
        cout<<"queue is not empty :"<<endl;
    }

    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(4);
    cout<<"size of the queue is : "<<minHeap.size()<<endl;

    cout<<"Top of the queue is : "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"size of the queue is : "<<minHeap.size()<<endl;
    cout<<"Top of the queue is : "<<minHeap.top()<<endl;

    if(minHeap.empty()){
        cout<<"queue is empty :"<<endl;
    }
    else{
        cout<<"queue is not empty :"<<endl;
    }
    return 0;
}