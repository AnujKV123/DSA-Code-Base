// Map in c++ stl

#include<bits\stdc++.h>
using namespace std;
void print(map<int, string> &m){
        map<int, string>::iterator it; // accessing value fron map by using iterator
        for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}

int main(){
    

    map<int, string> m; // initializing the map ****** map<int ->(key), string ->(value)> ****** key of every map should be common
    m[1] = "abc"; // inserting value in map method - 1 TC -> O(log(n))
    m[2] = "bcd";
    m[3] = "def";

    m.insert({4, "efg"}); // inserting value in map method - 2

    map<int, string>::iterator it; // accessing value fron map by using iterator
    for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    for(auto &pr:m){  // accessing value fron map by using auto keyword 
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    print(m);

    // auto itx = m.find(3); // .find(x) first of all search key values in the whole map if the key is not exist then it return .ende()
    auto itx = m.find(7); // TC -> O(log(n))
    if(itx == m.end()){
        cout<<"No value";
    }
    else{
        cout<<itx->first<<" "<<itx->second<<endl;
        }
    
    m.erase(3); // .erase(x) is used to delete the value from map
                // TC -> O(log(n))
    m.clear(); // .cleare() is used to delete the whole value from map
                // TC -> O(log(n))
    return 0;
}