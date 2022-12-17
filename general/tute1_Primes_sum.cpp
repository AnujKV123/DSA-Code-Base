// ****************************************** Primes sum ********************************************

// know more :- https://practice.geeksforgeeks.org/problems/primes-sum5827/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:

// ***************************** Approch-1 ***************************

    // bool isPrime(int n){
    //     int count = 0;
    //     for(int i=2; i<=n; i++){
    //         if(n%i == 0){
    //             count++;
    //         }
    //     }
    //     if(count>1) return false;
    //     else return true;
    // }
    // string isSumOfTwo(int N){
    //     // code here
    //     for(int i=2; i<N; i++){
    //         if(isPrime(i)){
    //             int num = N-i;
    //             if(isPrime(num)){
    //                 return "Yes";
    //             }
    //         }
    //     }
    //     return "No";
    // }

// ***************************** Approch-2 ***************************

    bool isPrime(int n){
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    string isSumOfTwo(int N){
        // code here
        for(int i=2; i<N; i++){
            if(isPrime(i) && isPrime(N-i)){
                return "Yes";
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends