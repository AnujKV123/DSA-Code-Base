//  Linear search by using recursion

#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int k){

    if(size == 0) return false;
    
    if(arr[0] == k) return true;
    else return linearSearch(arr+1, size-1, k);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    if(linearSearch(arr, size, 10)) cout<<endl<<"element is present at array: "<<endl;

    else cout<<endl<<"element is not present at array: "<<endl;

    return 0;
}