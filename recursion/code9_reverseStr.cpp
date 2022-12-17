// reversing string by using recursion

#include<iostream>
using namespace std;

void reverseStr(int i, int j, string& s){

    if(i>j) return ;
    swap(s[i], s[j]);
    i++;
    j--;
    return reverseStr(i, j, s);
}

int main(){
    string s = "jasimaranja";
    int size = s.length();

    reverseStr(0, size-1, s);
    cout<<endl<<"the reverse of string is: "<<s<<endl;

    return 0;
}