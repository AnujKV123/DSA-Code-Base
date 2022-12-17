//  check array is sorted or not by using recursion 

#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){

    if(size == 0 || size == 1) return true;

    if(arr[0] > arr[1]) return false;

    else return isSorted(arr+1, size-1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    if(isSorted(arr, size)) cout<<endl<<"the given array is sorted: "<<endl;

    else cout<<endl<<"the given array is not sorted: "<<endl;
    return 0;
}