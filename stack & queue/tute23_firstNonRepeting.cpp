// ******************************** irst non-repeating character in a stream *************************************

/* Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating 
character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

    Example 1:

    Input: A = "aabc"
    Output: "a#bb"
    Explanation: For every character first non
    repeating character is as follow-
    "a" - first non-repeating character is 'a'
    "aa" - no non-repeating character so '#'
    "aab" - first non-repeating character is 'b'
    "aabc" - first non-repeating character is 'b'

    Example 2:

    Input: A = "zz"
    Output: "z#"
    Explanation: For every character first non
    repeating character is as follow-
    "z" - first non-repeating character is 'z'
    "zz" - no non-repeating character so '#'
 */ 

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    map<char, int> m;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		        q.push(ch);
		        m[ch]++;
		        
		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends