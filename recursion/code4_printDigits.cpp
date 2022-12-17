//  print the digits of a given numbers

#include<iostream>
using namespace std;

void printDigit(int n, string arr[]){

    if(n==0) return ;

    int digit = n%10;
    n = n/10;

    printDigit(n,  arr);

    // head recursive
    cout<<arr[digit]<<" ";
}

int main(){
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout<<"Enter the number: "<<endl;
    int n;
    cin>>n;
    printDigit(n, arr);
    return 0;
}