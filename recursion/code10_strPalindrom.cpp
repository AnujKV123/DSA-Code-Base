// check the string is palindrom or not

#include<iostream>
using namespace std;

bool checkPalindrom(int i, int j, string& s){

    if(i > j) return true;

    if(s[i] == s[j]) return checkPalindrom(i+1, j-1, s);

    else return false;
}

int main(){
    string s = "books";
    int size = s.length();

    if(checkPalindrom(0, size-1, s)) cout<<endl<<"strinng is palindrom : "<<s<<endl;

    else cout<<endl<<"strinng is not palindrom : "<<s<<endl;

    return 0;
}