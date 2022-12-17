//  selection sort in array

#include<iostream>
using namespace std;

int main(){
    int arr[] = {25, 30, 2, 1, 8, 15, 20, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<size-1; i++){
        int minIndex = i;

        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        int temp = 0;
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    cout<<"Array after sorting is: "<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}