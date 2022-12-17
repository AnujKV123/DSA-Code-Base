// ************************************* Find the Winner of the Circular Game ******************************************

// know more :- https://drive.google.com/file/d/1KLXqRXG3gOnIKz9WRKlkv_ExzOV4ejBR/view

// question :- https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k){
        if(n == 1) return 0;
        
        return (solve(n-1, k) + k)%n;
    }
    int findTheWinner(int n, int k) {
        
        int ans = solve(n, k) + 1;
        
        return ans;
    }
};