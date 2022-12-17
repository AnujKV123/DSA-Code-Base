#include<iostream>
using namespace std;

// int insertionSort(int arr[], int n){
//     for(int i = 1; i<n; i++){
//         int temp = arr[i];
//         int j = i-1;
//         for(;  j>=0; j--){
//             if(arr[j]>temp){
//                 // shift
//                 arr[j+1] = arr[j];
//             }
//             else{
//                 break;
//             }
//         }
//         arr[j+1] = temp;
//     }

// }

int insertionSort(int arr[], int n){
    int i=1;
    while(i<n){
       int j=i-1;
        int temp=arr[i];
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
             
            j--;
        }
        i++;
        arr[j+1]=temp;
    }
}

// int insertionSort(int arr[], int n){
//     int i=1;
//     while(i<n){
//        int j=i-1;
//         int temp=arr[i];
//         while(j>=0 && arr[j]>temp)
//         {
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=temp;
//     }
// }

int main(){
    int arr[] = {25, 30, 2, 1, 8, 15, 20, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);

    cout<<"The result of insertion sort is:"<<endl;
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}