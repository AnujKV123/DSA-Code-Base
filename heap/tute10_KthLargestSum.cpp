// ********************************** K-th Largest Sum Subarray  **************************************

#include<bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.\
//     Approch: 1 **********************
//     tc = O(n^2), sc = O(n^2)
    
//     vector<int> ans;
//     for(int i=0; i<arr.size(); i++){
//         int sum=0;
//         for(int j=i; j<arr.size(); j++){
//             sum += arr[j];
//             ans.push_back(sum);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     int n = ans.size();
//     return ans[n-k];
    
//     Approch: 2 *************************
//     tc = O(n^2logn), sc = O(k)
    priority_queue<int, vector<int>, greater<int>> mini;
    
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum += arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}