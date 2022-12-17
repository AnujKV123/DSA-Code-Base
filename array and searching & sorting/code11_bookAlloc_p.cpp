// solving book allocation problem by using binary search
// *********************** same strategies(code) are used to solve painter partetion problem **************************

#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){

    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int isAllocate(int arr[], int n, int m){

        int e = 0;
        for(int i=0; i<n; i++){
            e += arr[i];
        }
        int ans = -1;
        int start = 0, end = e;

        int mid = start + (end - start)/2;
        while (start<end){
        
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = isAllocate(arr, size, 2);
    cout<<"The solution of book allocation problem is: "<<x<<endl;
    return 0;
}