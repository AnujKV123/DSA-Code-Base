// Write a program to reverse an array ************

#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // finding the size of an array************
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = size;
    
    for(int i=0; i<size;i++){
        
        // swap(arr[i], arr[size-1]);

        // or

        int temp = arr[i];
        arr[i] = arr[size-1];
        arr[size-1] = temp;
        size--;
    }
    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}