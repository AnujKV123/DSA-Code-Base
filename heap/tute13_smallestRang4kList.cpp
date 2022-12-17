// ************ find Smallest Range From K Sorted List where at least 1 element come in the rangte from the all k lists **************

#include<bits/stdc++.h>
#include<limits.h>
#include<queue>

using namespace std;

// tc = O(n*k logk)
class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    
//     step 1 : ceate a min heap for starting element for each list and tracking mini/maxi values;
    for(int i=0; i<k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }
    
    int start = mini, end = maxi;
    
//     step 2 : process ranges
    while(!minHeap.empty()){
        node* temp = minHeap.top();
        minHeap.pop();
        
//         range or answer updation
        mini = temp->data;
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }
        
//         next element exista
        if(temp->col+1 < n){
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col+1));
        }
        else{
//             break element doesn't exist
            break;
        }
    }
//     returning the difference of range values;
    return (end - start + 1);
}