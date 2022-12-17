// ********************************************** Maximum Meetings in One Room *********************************************

// compiler :- https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        pair<int, int> v[N+1];
        
        for(int i=0; i<N; i++){
            
            v[i] = {F[i], i+1};
        }
        
        sort(v, v+N);
        
        vector<int> ans;
        
        ans.push_back(v[0].second);
        int endAns = v[0].first;
        
        for(int i=1; i<N; i++){
            if(S[v[i].second-1] > endAns){
                
                ans.push_back(v[i].second);
                endAns = v[i].first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    // pair<int, int> a[N + 1];
    // int i;
    // for (i = 0; i < N; i++) {
    //     a[i].first = F[i];
    //     a[i].second = i;
    // }
   
    // Sorting of meeting according to their finish time.
    // sort(a, a + N);
 
    // // Time_limit to check whether new
    // // meeting can be conducted or not.
    // int time_limit = a[0].first;
 
    // // Vector for storing selected meeting.
    // vector<int> m;
 
    // // Initially select first meeting.
    // m.push_back(a[0].second + 1);
 
    // // Check for all meeting whether it
    // // can be selected or not.
    // for (i = 1; i < N; i++) {
    //     if (S[a[i].second] > time_limit) {
    //         // Push selected meeting to vector
    //         m.push_back(a[i].second + 1);
 
    //         // update time limit
    //         time_limit = a[i].first;
    //     }
    // }
    // sort(m.begin(), m.end());
    // return m;
    // }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends