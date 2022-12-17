//  find the sum if all element of array 

#include<iostream>
using namespace std;

int isSorted(int arr[], int size){

    if(size == 0) return 0;
    
    return arr[0] + isSorted(arr+1, size-1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<endl<<"the sum of all elements of an array: "<<isSorted(arr, size)<<endl;

    return 0;
}