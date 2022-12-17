// sort an array in c++

#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,5,7,2,4,10,15,9,11};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = 0; i<size-1; i++){
        for(int j = i+1; j<size;j++){
            if(arr[i]>arr[j]){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}