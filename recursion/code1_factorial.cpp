//  find the factorial by using recursion

#include<iostream>
using namespace std;

int fact(int n){

    if(n==1 || n==0) return 1;

    return n*fact(n-1);
}

int main(){

    cout<<"Enter the number: "<<endl;
    int n;
    cin>>n;
    cout<<"The result of the "<<n<<"! = "<<fact(n);
    
    return 0;
}