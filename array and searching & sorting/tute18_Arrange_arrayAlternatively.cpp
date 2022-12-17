// **************************************** Rearrange Array Alternately *****************************************

// know more :- https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1?page=2&curated[]=1&sortBy=submissions

//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	
// ***************************** Approch-1 **********************************
    // 	long long  i=0, j=n-1;
    	
    // 	while(i<j){
    // 	    long long  temp = arr[i+1];
    // 	    long long  temp2 = arr[j];
    // 	    arr[i+1] = arr[i];
    // 	    arr[i] = temp2;
    // 	    i+=2;
    // 	    for(long long k=n-1; k>=i; k--){
    // 	        arr[k] = arr[k-1];
    // 	    }
    // 	    arr[i] = temp;
    // 	}
    
// *************************** Approch-2 *************************************
    
        // long long temp[n];
        // int small = 0, large = n-1;
        // int flag = true;
        
        // for(int i=0; i<n; i++){
        //     if(flag){
        //         temp[i] = arr[large--];
        //     }
        //     else{
        //         temp[i] = arr[small++];
        //     }
        //     flag = !flag;
        // }
        // for(int i=0; i<n; i++){
        //     arr[i] = temp[i];
        // }  
        
// *************************** Approch-3 *************************************
    
        int max_index = n-1;
        int min_index = 0;
        int max = arr[n-1]+1;
        
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                arr[i] = (arr[max_index]%max)*max + arr[i];
                max_index--;
            }
            else{
                arr[i] = (arr[min_index]%max)*max + arr[i];
                min_index++;
            }
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0; i<n; i++){
            arr[i] = arr[i]/max;
        }
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends