// ***************************** Kth smallest element *******************************

/*  Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

    Example 1:

    Input:
    N = 6
    arr[] = 7 10 4 3 20 15
    K = 3
    Output : 7
    Explanation :
    3rd smallest element in the given 
    array is 7.

    Example 2:

    Input:
    N = 5
    arr[] = 7 10 4 20 15
    K = 4
    Output : 15
    Explanation :
    4th smallest element in the given 
    array is 15.
 */ 


//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        for(int i=k; i<=r; i++){
            if(pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends