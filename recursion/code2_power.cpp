//  find the 2^n by using recursion

#include<iostream>
using namespace std;

int power(int n){

    if(n==0) return 1;

    return 2*power(n-1);
}

int main(){

    cout<<"Enter the number: "<<endl;
    int n;
    cin>>n;
    cout<<"The result of the 2^"<<n<<" = "<<power(n);
    
    return 0;
}