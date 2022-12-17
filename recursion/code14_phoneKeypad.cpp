// *********************** Letter Combinations of a Phone Number ************************

/*  Given a string containing digitss from 2-9 inclusive, return all possible letter combinations that the number could represent. 
    Return the answer in any order.

    A mapping of digitss to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    

    Example 1:

    Input: digitss = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Example 2:

    Input: digitss = ""
    Output: []

    Example 3:

    Input: digitss = "2"
    Output: ["a","b","c"]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        void solve(string digits, string output, int index, vector<string>& ans, string mapping[]){
            
            if(index>=digits.length()){
                ans.push_back(output);
                return;
            }
            int number = digits[index] - '0';
            string value = mapping[number];
            
            for(int i=0; i<value.length(); i++){
                output.push_back(value[i]);
                solve(digits, output, index+1, ans, mapping);
                output.pop_back();
            }
        }
    public:
        vector<string> phoneKeypad(string& digits){

            vector<string> ans;
            
            if(digits.length()==0) return ans;
            string output;
            int index = 0;
            
            string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
                
            solve(digits, output, index, ans, mapping);
            return ans;
        }
};

int main(){
    cout<<"Enter the no string:"<<endl;
    string digits;
    cin>>digits;
    Solution obj;
    vector<string> result = obj.phoneKeypad(digits);
    
    cout<<"[";
    for(int i=0; i<result.size(); i++){

        if(i>0)  cout<<", "<<'"'<<result[i]<<'"';
        else cout<<'"'<<result[i]<<'"';
    }
    cout<<"]";

    return 0;
}
