// ************************************** Magic Triplets *********************************************

// know more :- https://practice.geeksforgeeks.org/problems/magic-triplets4003/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    
// 	******************************* Approch-1 *************************************

	   // int ans=0;
	   // for(int i=0; i<nums.size()-2; i++){
	        
	   //     for(int j=i+1; j<nums.size()-1; j++){
	            
	   //         if(nums[i]<nums[j]){
	                
	   //             for(int k=j+1; k<nums.size(); k++){
	   //                 if(nums[i]<nums[j] && nums[j]<nums[k]){
	   //                     ans++;
	   //                 }
	   //             }
	   //         }
	   //         else{
	   //             continue;
	   //         }
	   //     }
	   // }
	   // return ans;
	   
// ************************************ Approch-2 ************************************
	   
	   int n = nums.size();

	    int count = 0;

	    for(int i = 0; i < n; i++) {

	        int left = 0;

	        int right = 0;

	        // finding the count of smallest no.
            for(int j = 0; j < i; j++) {

	            if(nums[j] < nums[i])

	                left++;

	        }

	        // finding the count of highest no.
            for(int k = n - 1; k > i; k--) {

	            if(nums[k] > nums[i])

	                right++;

	        }

	        count += left * right;

	    }

	    return count;

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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends