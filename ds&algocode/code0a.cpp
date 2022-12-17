// 1.Find pair with given sum in the array

#include<bits/stdc++.h>
using namespace std;

void func1(vector<int> arr1, int num){
    for(int i=0; i<arr1.size()-1;i++){
        int var1 = arr1[i];
        for(int j=i+1; j<arr1.size();j++){
            int var2 = arr1[j];
                if(num == var1+var2){
                    cout<<"the pair element is : "<<var1<<" "<<var2;
                    return;
                }
            }
        }
        cout<<"pair not found";
}

int main(){
    vector<int> arr;
    int n, k;
    cin>>n;
    for (int i = 0; i <n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cin>>k;func1(arr, k);
    return 0;
}