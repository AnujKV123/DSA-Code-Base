// ***************** check given string have redundent bracket(extra bracket(faltu ka bracket)) or not *******************

#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>st;
    
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool redundent = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top=='+'||top=='-'||top=='*'||top=='/'){
                        redundent = false;
                    }
                    st.pop();
                }
                if(redundent == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}