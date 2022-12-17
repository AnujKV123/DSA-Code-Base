// finding the lowest and highest number in an array by using binary search

#include<iostream>
using namespace std;

int firstOccur(int arr[], int e, int k){

    int start = 0;
    int end = e-1;
    int ans = -1;

//  use this way of finding mid to avoid integer out-flow. ***************
    int mid = start +(end - start)/2;

    while(start<=end){
        if(arr[mid] == k){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>k){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;

}

int lastOccur(int arr[], int e, int k){

    int start = 0;
    int end = e-1;
    int ans = -1;

//  use this way of finding mid to avoid integer out-flow. ***************
    int mid = start +(end - start)/2;

    while(start<=end){
        if(arr[mid] == k){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid]>k){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;

}

int main(){
    int arr[] = {1, 1, 1, 1, 1, 1, 2, 5, 8, 10, 17, 21, 25};
    int size = sizeof(arr)/sizeof(arr[0]);

    
    cout<<"First ocuurance of 1 at index: "<<firstOccur(arr, size, 1)<<endl;
    cout<<"Last ocuurance of 1 at index: "<<lastOccur(arr, size, 1)<<endl;

    return 0;
}