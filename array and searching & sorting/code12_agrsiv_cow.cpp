// aggressive cow problem :- find the maximum diatance between two cow stall

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, int mid){

    int cowCount = 1;
    int lastPos = arr[0];

    for(int i=0; i<arr.size(); i++){
        if(arr[i]-lastPos >= mid){
           cowCount++;
           if(cowCount == k){
            return true;
           }
           lastPos = arr[i];
        }
    }
    return false;
}

int AllocateCowStall(vector<int> &arr, int k){

        sort(arr.begin(), arr.end());
        int s = 0;
        int maxi = -1;
        for(int i=0; i<arr.size(); i++){
           maxi = max(maxi, arr[i]);
        }
        int start = 0, end = maxi;
        int ans = -1;
        int mid = start + (end - start)/2;
        while (start<end){
        
        if(isPossible(arr, k, mid)){
            ans = mid;
            start = mid+1;
            
        }
        else{
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 6};
    int x = AllocateCowStall(arr, 2);
    cout<<"The maximum distance between tw cow is: "<<x<<endl;
    return 0;
}