#include<bits/stdc++.h>

using namespace std;

void printVec(vector<int> &v){
    cout<<"size: "<<v.size()<<endl;
    for(int i=0;i<v.size();++i){
        // v.size() ->Time Complexity -> o(1)
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;

    // vector<int> v(size, element); // pre felling the vector
    // vector<int> v(10, 3);
    // v.push_back(7); 7 storing after address 10
    // v.pop_back(); // removing elements from vector TC-> O(1)

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    printVec(v);
}