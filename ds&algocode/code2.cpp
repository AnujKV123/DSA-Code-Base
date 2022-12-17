// Write a program to find the mean of n numbers using arrays

#include<iostream>
using namespace std;

int main(){
    int arr[50], sum=0, n;
    float mean;

    cout<<"enter the length of an array"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"enter the number at location "<<i+1<<endl;
        cin>>arr[i];
    }
    for(int j=0; j<n; j++){
        sum = sum + arr[j];
    }

    mean = sum/n;
    cout<<"the sum of "<<n<<" number is "<<sum<<endl;
    cout<<"the mean of "<<n<<" number is "<<mean<<endl;
    return 0;
}