#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main(){
    string s = "Anuj";
    cout<<s<<endl;
    string ans = "";
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        st.push(ch);
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    cout<<ans<<endl;
    
    return 0;
}