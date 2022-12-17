#include<bits\stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            if(arr[i] == arr[j]){
                cout<<"The Duplicate Element is : "<<arr[i]<<endl;
                break;
            }
        }
    }
    // cout<<"No Duplicate Element is Exist:";
    return 0;
}