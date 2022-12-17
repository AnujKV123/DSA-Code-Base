// searching the element in sorted rotated array ********************************** V V I **********************************************

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

int BinarySearch(int arr[], int s, int e, int k){

    int start = s;
    int end = e;

//  use this way of finding mid to avoid integer out-flow. ***************
    int mid = start +(end - start)/2;

    while(start<=end){
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid]>k){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return -1;

}

int search(int arr[], int e, int k){
    int pivot = findPivot(arr, e);

    if(k >= arr[pivot] && k <= arr[e-1]){
        return BinarySearch(arr, pivot, e-1, k);
    }
    else{
        return BinarySearch(arr, 0, pivot-1, k);
    }
}

int main(){
    
    int arr[] = {4,5,6,7,0,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = search(arr, size, 0);
    if(x == -1){
        cout<<"element is not exist in an array ";
    }
    else{
    cout<<"element is at index: "<<x<<" and the element is "<<arr[x];
    }
    return 0;
}