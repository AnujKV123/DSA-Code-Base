// find the peak in mountain array

#include<iostream>
using namespace std;

int mountainPeak(int arr[], int s){

    int start = 0;
    int end = s-1;
    int mid = start + (end-start)/2;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;

}

int main(){
    int arr[] = {2, 3, 4, 5, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Peak of the mountain is: "<<mountainPeak(arr, size)<<endl;
    
    return 0;
}