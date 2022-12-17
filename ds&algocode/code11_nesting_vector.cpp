// nesting in vector in c++
//  vector of pairs
#include<bits\stdc++.h>
using namespace std;

void printVec(vector<pair<int, int>> &v){
    cout<<"size: "<<v.size()<<endl;
    for(int i=0;i<v.size();++i){
        // v.size() ->Time Complexity -> o(1)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

int main(){
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    printVec(v);
    int n;
    vector<pair<int, int>> v1;
    cin>>n;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        v1.push_back({x, y});
    }
    for(int i=0; i<v1.size();i++){
        cout<<v1[i].first<<" "<<v1[i].second<<endl;
    }


    return 0;
}