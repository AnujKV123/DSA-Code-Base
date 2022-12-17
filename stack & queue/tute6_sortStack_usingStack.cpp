// ******************************** sort stack using stack ***********************************

#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &stack, int num){
    if(stack.empty() || (!stack.empty() && stack.top()<num)){
        stack.push(num);
        return;
    }
    
    int numx = stack.top();
    stack.pop();
    insertSorted(stack, num);
    stack.push(numx);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack, num);
}