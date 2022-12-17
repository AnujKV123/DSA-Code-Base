// binary search in array

#include<iostream>
using namespace std;

// by using iterative approch

// int BinarySearch(int arr[], int e, int k){

//     int start = 0;
//     int end = e-1;

//  use this way of finding mid to avoid integer out-flow. ***************
//     int mid = start +(end - start)/2;

//     while(start<=end){
//         if(arr[mid] == k){
//             return mid;
//         }
//         else if(arr[mid]>k){
//             end = mid-1;
//         }
//         else{
//             start = mid+1;
//         }
//         mid = start + (end - start)/2;
//     }
//     return -1;

// }

// by using recursive approch

int BinarySearch(int arr[], int s, int e, int k){

    int start = s;
    int end = e;
    //  use this way of finding mid to avoid integer out-flow. ***************
    int mid = start +(end - start)/2;

    if( arr[mid] == k) return mid;

    if(start>end) return -1;

    if(arr[mid]>k) return BinarySearch(arr, start, mid-1, k);

    if(arr[mid]<k) return BinarySearch(arr, mid+1, end, k);


}

int main(){
    int arr[] = {1, 2, 5, 8, 10, 17, 21, 25};
    int size = sizeof(arr)/sizeof(arr[0]);

    // iterative approch
    // int result  = BinarySearch(arr, size, 2);
    // cout<<"Element 2 at index: "<<result<<endl;

    // recursive approch
    int result  = BinarySearch(arr, 0, size, 25);
    cout<<"Element 25 at index: "<<result<<endl;

    return 0;
}