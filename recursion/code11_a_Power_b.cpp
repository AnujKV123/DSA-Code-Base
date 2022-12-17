// find a^b by using recursion

#include<iostream>
using namespace std;

int power(int a, int b){

    if(b == 0) return 1;
    
    if(b == 1) return a;

    // recursive call
    int ans = power(a, b/2);

    // if b is even
    if(b%2 == 0) return ans*ans;

    // if b is odd
    else return a*ans*ans;
}

int main(){
    int a, b;
    cin>>a>>b;

    cout<<endl<<"the result of "<<a<<"^"<<b<<" = "<<power(a, b)<<endl;

    return 0;
}