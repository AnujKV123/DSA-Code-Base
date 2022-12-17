// how to delete an element from an array from any position

#include<iostream>
using namespace std;

int main(){
    int n, pos;

    cout<<"enter the size of an array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"enter the value at podition "<<i+1<<endl;
        cin>>arr[i];
    }
    cout<<"enter the position where will be delete the element"<<endl;
    cin>>pos;
    for(int i = pos-1; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
    for(int i=0; i<n;i++){
        cout<<"the element at position "<<i+1<<" is "<<arr[i]<<endl;
    }
    return 0;
}