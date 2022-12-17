// ********************************************* N meetings in one room ****************************************************

// know more for all codes :- https://drive.google.com/file/d/1HFLguXs6LtH491Ojh1uVXZe2ij90HQln/view

// compiler :- https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second<b.second;
    }
    // int maxMeetings(int start[], int end[], int n)
    // {
    //     // Your code here
    //     vector<pair<int, int>> v;
        
    //     for(int i=0; i<n; i++){
            
    //         pair<int, int> p = {start[i], end[i]};
    //         v.push_back(p);
    //     }
        
    //     sort(v.begin(), v.end(), cmp);
        
    //     int count = 1;
    //     int endAns = v[0].second;
        
    //     for(int i=1; i<n; i++){
            
    //         if(v[i].first > endAns){
                
    //             count +=1;
    //             endAns = v[i].second;
    //         }
    //     }
    //     return count;
    // }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v(n, pair<int, int>(0, 0));
        
        for(int i=0; i<n; i++){
            
            v[i] = {end[i], start[i]};
        }
        
        sort(v.begin(), v.end());
        
        int count = 1;
        int endAns = v[0].first;
        
        for(int i=1; i<n; i++){
            
            if(v[i].second > endAns){
                
                count +=1;
                endAns = v[i].first;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends