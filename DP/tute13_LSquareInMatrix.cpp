// ************************************ Largest square formed in a matrix ******************************************

// know more :- https://drive.google.com/file/d/1G9-W7U6-KjLN3R-3_qPesE044HukTVuk/view

// compiler :- https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// ************************************** recursion *******************************************

    // int solve(vector<vector<int>> &mat, int i, int j, int &maxi){
        
    //     if(i >= mat.size() || j >= mat[0].size()) return 0;
        
    //     int row = solve(mat, i, j+1, maxi);
    //     int dig = solve(mat, i+1, j+1, maxi);
    //     int col = solve(mat, i+1, j, maxi);
        
    //     if(mat[i][j] == 1){
    //         int ans = 1 + min(row, min(dig, col));
    //         maxi = max(maxi, ans);
            
    //         return ans;
    //     }
    //     else{
    //         return 0;
    //     }
        
    // }
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     // code here
        
    //     int maxi = 0;
    //     solve(mat, 0, 0, maxi);
    //     return maxi;
    // }
    


// ********************* Top-Down Approch - (recursion + memoization) ************************
// T.C = O(m*n)
// S.C = O(m*n)

    // int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
        
    //     if(i >= mat.size() || j >= mat[0].size()) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int row = solve(mat, i, j+1, maxi, dp);
    //     int dig = solve(mat, i+1, j+1, maxi, dp);
    //     int col = solve(mat, i+1, j, maxi, dp);
        
    //     if(mat[i][j] == 1){
    //         dp[i][j] = 1 + min(row, min(dig, col));
    //         maxi = max(maxi, dp[i][j]);
    //         return dp[i][j];
    //     }
    //     else{
    //         return dp[i][j] = 0;
    //     }
        
    // }
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     // code here
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     int maxi = 0;
    //     solve(mat, 0, 0, maxi, dp);
    //     return maxi;
        
    // }
    


// ****************** Bottom-Up Approch - Tabulatopn Method *****************
// T.C = O(m*n)
// S.C = O(m*n)

    // int solve(vector<vector<int>> &mat, int n, int m, int &maxi){
        
    //     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        
    //     for(int i=n-1; i>=0; i--){
    //         for(int j=m-1; j>=0; j--){
                
    //             int row = dp[i][j+1];
    //             int dig = dp[i+1][j+1];
    //             int col = dp[i+1][j];
                
    //             if(mat[i][j] == 1){
    //                 dp[i][j] = 1 + min(row, min(dig, col));
    //                 maxi = max(maxi, dp[i][j]);
    //             }
    //             else{
    //                 dp[i][j] = 0;
    //             }
    //         }
    //     }
    //     return dp[0][0];  
    // }
    // int maxSquare(int n, int m, vector<vector<int>> mat){
    //     // code here
    //     int maxi = 0;
    //     solve(mat, n, m, maxi);
    //     return maxi;
        
    // }
    
    
    


// ****************** Approch3 - Space Optimization *****************
// T.C = O(m*n)
// S.C = O(m)

    int solve(vector<vector<int>> &mat, int n, int m, int &maxi){
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                int row = curr[j+1];
                int dig = next[j+1];
                int col = next[j];
                
                if(mat[i][j] == 1){
                    curr[j] = 1 + min(row, min(dig, col));
                    maxi = max(maxi, curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];  
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi = 0;
        solve(mat, n, m, maxi);
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends