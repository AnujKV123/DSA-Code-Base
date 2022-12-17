// ***************** Construct Binary Tree from String with bracket representation ********************
// Time Complexity: O(N^2)
// Auxiliary Space: O(N)

// ***************************************************************************************************
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        
        node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

int findIndex(string s, int st, int ed){
    
    if(st>ed) return -1;
    
    stack<char> bc;
    for(int i=st; i<=ed; i++){
        
        if(s[i] == '('){
            bc.push(s[i]);
        }
        else if(s[i] == ')'){
            if(bc.top() == '(')
                bc.pop();
            
            if(bc.empty()) return i;
        }
    }
    return -1;
}

node* constructTree(string s, int st, int ed){
    if(st > ed) return NULL;
    
    int data = 0;
    while(st<=ed && s[st]>='0' && s[st]<='9'){
        
        data *= 10;
        data += s[st] - '0';
        st++;
    }
    node* root = new node(data);
    int index = -1;
    
    if (st <= ed && s[st] == '(')
        index = findIndex(s, st, ed);
    
    if(index != -1){
        
        root->left = constructTree(s, st+1, index-1);
        root->right = constructTree(s, index+2, ed-1);
    }
    return root;
}
int main() {
    // Write C++ code here
    string s = "4(2(3)(1))(6(5))";
    
    node* ans = constructTree(s, 0, s.length()-1);
    
    stack<node*> q;
    
    node* curr = ans;
    
    while(!q.empty() || curr != NULL){
        
        if(curr){
            cout<<curr->data<<" ";
            q.push(curr);
            curr = curr->left;
        }
        else{
            node* front = q.top();
            q.pop();
            curr=front->right;
        }
    }cout<<endl;

    return 0;
}
// 4 2 3 1 6 5 