// ************************************************** Longest Bitonic subsequence *************************************************

// know more :- https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> right(n, 1);
	    vector<int> left(n, 1);
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(nums[j]<nums[i]){
	                right[i] = max(right[i], 1+right[j]);
	            }
	        }
	    }
	    
	    for(int i=n-1; i>=0; i--){
	        for(int j=n-1; j>i; j--){
	            if(nums[j]<nums[i]){
	                left[i] = max(left[i], 1+left[j]);
	            }
	        }
	    }
	    int maxi = 0;
	    for(int i=0; i<n; i++){
	        int sum = (right[i] + left[i]) -1;
	        maxi = max(maxi, sum);
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends