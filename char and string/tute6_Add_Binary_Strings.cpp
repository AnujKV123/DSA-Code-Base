// ******************************************************* Add Binary Strings **************************************************

// know more :- https://practice.geeksforgeeks.org/problems/add-binary-strings3805/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    
// 	 **************************************** Approch-1 **************************************************

	   // reverse(A.begin(), A.end());
	   // reverse(B.begin(), B.end());
	    
	   // int maxi = max(A.length(), B.length());
	   // string ans = " ";
	   // char carry = '0';
	    
	   // for(int i=0; i<maxi; i++){
	   //     char chA, chB;
	        
	   //     if(A.length()-1>=i) chA = A[i];
	   //     else chA = '0';
	        
	   //     if(B.length()-1>=i) chB = B[i];
	   //     else chB = '0';
	        
	   //     if(chA=='0'&& chB=='0' && carry=='0'){
	   //         ans += '0';
	   //     }
	   //     else if((chA=='1'&&chB=='1'&&carry=='0') || (chA=='1'&&chB=='0'&&carry=='1') || (chA=='0'&&chB=='1'&&carry=='1')){
	   //         ans += '0';
	   //         carry = '1';
	   //     }
	   //     else if((chA=='1'&&chB=='0'&&carry=='0') || (chA=='0'&&chB=='1'&&carry=='0') || (chA=='0'&&chB=='0'&&carry=='1')){
	   //         ans += '1';
	   //         carry = '0';
	   //     }
	   //     else if((chA=='1'&&chB=='1'&&carry=='1')){
	   //         ans += '1';
	   //         carry = '1';
	   //     }
	        
	   // }
	   // if(carry=='1') ans += '1';
	    
	   // reverse(ans.begin(), ans.end());
	   // int i=0;
	   // while(ans[i]=='0'){
	   // ans.erase(0,1);
	   // }
	    
	   // return ans;
	   
// 	 **************************************** Approch-2 **************************************************
        
        string ans = "";
	    int i = A.size() - 1, j = B.size() - 1;
	    bool carry = 0;
	   
	    
	    while(i >= 0 || j >= 0)
	    {
	        int sum = 0;
	        if(i >= 0 && A[i] == '1')
	            sum++;
            if(j >= 0 && B[j] == '1')
                sum++;
            
              
            if(sum + carry == 3)
            {
                ans += '1';
                carry = 1;
            }
            else if(sum + carry == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if(sum + carry == 1)
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 0;
            }
            i--; j--;
	           
	    }
	    if(carry == 1)
	        ans += to_string(carry);
	    reverse(ans.begin(), ans.end());
	    i = 0;
	    while(ans[i] == '0')
	    {
	        ans.erase(0, 1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends