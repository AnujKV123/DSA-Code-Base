#include<iostream>
using namespace std;

// converting to lowercase ************************ Important for interview ***************************
char toLowercase(char ch){
    
    if(ch>='a' && ch<= 'z'){
        return ch;
    }
    else{
         // for lowercase
        char temp = ch - 'A' + 'a';

        // for uppercase
        // char temp = ch - 'a' + 'A';

        return temp;
    }
}

bool checkPalindrom(char name[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(toLowercase(name[s]) != toLowercase(name[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;

}

int main(){

    char name[20];
    cin>>name;
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){

        count++;
    }
    checkPalindrom(name, count);
    cout<<"Result of checkPalindrom: "<<checkPalindrom(name, count);
    
    return 0;
}