#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){

    int pivot = arr[s];

    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    // placed pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // handling left and right part
    int i = s, j = e;
    while (i<pivotIndex && j>pivotIndex){

        while(arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j++]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){

    if(s >= e){
        return ;
    }
    
    // partition
    int p = partition(arr, s, e);

    // sorting left part
    quickSort(arr, s, p-1);

    // sorting right part
    quickSort(arr, p+1, e); 
}

int main(){
    int arr[] = {25, 30, 2, 1, 8, 15, 20, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0,  size-1);

    cout<<"The result of quick sort is:"<<endl;
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}