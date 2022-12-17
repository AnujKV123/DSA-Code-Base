// finding the pivot element in an sorted rotated array

#include<iostream>
using namespace std;

int findPivot(int arr[], int e){

    int start = 0;
    int end = e-1;
    int mid = start + (end-start)/2;

    while(start<end){
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main(){
    
    int arr[] = {3, 8, 10, 17, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = findPivot(arr, size);
    cout<<"the pivot element is at index: "<<x<<" and the pivot element is "<<arr[x];
    return 0;
}