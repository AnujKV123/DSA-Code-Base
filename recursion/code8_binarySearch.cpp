//  binary search by using recursion

#include<iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){

    if(s>e) return false;

    int mid = s+(e-s)/2;
    
    if(arr[mid] == k) return true;
    else if(arr[mid] > k) return binarySearch(arr,s ,mid-1, k);
    else  return binarySearch(arr, mid+1, e, k);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    if(binarySearch(arr, 0, size-1, 5)) cout<<endl<<"element is present at array: "<<endl;

    else cout<<endl<<"element is not present at array: "<<endl;

    return 0;
}