// implementation of stack and queue in c++ stl

#include<bits/stdc++.h>
using namespace std;

int main(){
    //  implementation of stack
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    //  implementation of queue
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}