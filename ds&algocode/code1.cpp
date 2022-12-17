// Write a program to read and display n numbers using an array.

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the length of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }
    for(int j=0; j<n; j++){
        cout<<"the value at index "<<j<<" is "<<arr[j]<<endl;
    }

    return 0;
}