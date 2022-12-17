// Move all negative numbers to beginning and positive to end with constant extra space

#include <iostream>
using namespace std;

void check(int arr[], int s){
    int high = s-1;
    int low = 0;
    while(high>low){
        if(arr[low]>0 && arr[high]<0){
            int temp = 0;
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            high--;
            low++;
        }
        else if(arr[high]>0){
            high--;
        }
        else{
            low++;
        }
    }
}

int main() {
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int size = sizeof(arr)/sizeof(arr[0]);
    check(arr, size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}