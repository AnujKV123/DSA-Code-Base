#include<iostream>
using namespace std;

struct pairx
{
    int min;
    int max;
};

pairx check(int arr[], int l){

    struct pairx minmax ;
    if(arr[0]>arr[1]){
        minmax.min = arr[1];
        minmax.max = arr[0];
    }
    else{
        minmax.min = arr[0];
        minmax.max = arr[1];
    }

    for(int i=2; i<l; i++){
        if(arr[i] > minmax.max){
            minmax.max = arr[i];
        }
        if(arr[i] <  minmax.min){
             minmax.min = arr[i];
        }
    }
    return minmax;


}



int main(){
    int arr[] = {1,5,7,2,4,10,15,9,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct pairx minmax = check(arr, size);

    cout<<"Minimum no of array: "<<minmax.min<<endl;
    cout<<"Maximum no of array: "<<minmax.max<<endl;

    return 0;
}