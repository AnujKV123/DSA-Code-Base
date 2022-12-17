#include<bits/stdc++.h>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root = new TrieNode(ch);
    }
    
    void insertUtil(TrieNode* root, string word){
        // base case 
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // Assumption, word will be in CAPS
        int index = word[0] - 'a';
        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            
            if(root->childCount == 1){
                ans.push_back(ch);
//                 aage bdha do
                int index = ch - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            
            if(root->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
//     ******************** Approch 1 ********************
//     tc = O(m*n)
//     sc = O(m)
//     string ans = "";
    
// //     first traversing all charector of string
//     for(int i=0; i<arr[0].length(); i++){
        
//         char ch = arr[0][i];
//         bool match = true;
        
// //         comparing ch with rest of the string
//         for(int j=1; j<n; j++){
            
//             if(arr[j].size()<i || ch != arr[j][i]){
//                 match = false;
//                 break;
//             }
//         }
//         if(match == false){
//                     break;
//                 }
//         else{
//             ans.push_back(ch);
//         }
//     }
//     return ans;
    
//     *************************** Approch 2 **************************
//     tc = O(m*n)
//     sc = O(m*n)
    Trie *t = new Trie('\0');
    
//     insert all strings into trie
    for(int i=0; i<n; i++){
        t->insertWord(arr[i]);
    }
    
    string first = arr[0];
    string ans = "";
    
    t->lcp(first, ans);
    return ans;
}


