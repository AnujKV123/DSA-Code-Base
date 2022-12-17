//  find the counting of n numbers by using recursion

#include<iostream>
using namespace std;

void printCounting(int n){

    if(n==0) return ;

    // tail recursive
    // cout<<n<<endl;

    printCounting(n-1);

    // head recursive
    cout<<n<<endl;
}

int main(){

    cout<<"Enter the number: "<<endl;
    int n;
    cin>>n;
    printCounting(n);
    return 0;
}