// Bubble in array

#include<iostream>
using namespace std;

int main(){
    int arr[] = {25, 30, 2, 1, 8, 15, 20, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    bool swapped = false;

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = 0;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                swapped = true;
            }
        }
        
        // optimization of bubble sort
        if(swapped == false){
            // break if alleady sorted
            break;
        }
        else{
            swapped == false;
        }
    }
     cout<<"The result of bubble sort is: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}