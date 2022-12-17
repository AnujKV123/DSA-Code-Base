//  in unorserd_map and map has a basic differences

//  1. in map data stored in sorted manner(alphabetical or numerical) of key but in unsorted map data not stored in sorted manner
//  2. inbuilt implementation -> map stored the data by using tree but unorderd_map is stored the data by using hash function
//  3. Time Complexity -> TC of map is O(log(n)) but TC of unsorted_map is O(1)
//  4. Valid key data type -> in case of map you have power to insert copmlex data type but in case of unorderd_map you have no power to insert complex data type

// Map in c++ stl

#include<bits\stdc++.h>
using namespace std;
void print(unordered_map<int, string> &m){
        unordered_map<int, string>::iterator it; // accessing value fron map by using iterator
        for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}

int main(){
    

    unordered_map<int, string> m; // initializing the map ****** map<int ->(key), string ->(value)> ****** key of every map should be common
    m[9] = "abc"; // inserting value in map method - 1 TC -> O(1)
    m[2] = "bcd";
    m[3] = "def";

    m.insert({4, "efg"}); // inserting value in map method - 2

    unordered_map<int, string>::iterator it; // accessing value fron map by using iterator
    for(it = m.begin(); it != m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl;

    for(auto &pr:m){  // accessing value fron map by using auto keyword 
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    cout<<endl;
    print(m);
    cout<<endl;

    // auto itx = m.find(3); // .find(x) first of all search key values in the whole map if the key is not exist then it return .ende()
    auto itx = m.find(7); // TC -> O(1)
    if(itx == m.end()){
        cout<<"No value";
    }
    else{
        cout<<itx->first<<" "<<itx->second<<endl;
        }
    
    m.erase(3); // .erase(x) is used to delete the value from map
                // TC -> O(1)
    m.clear(); // .cleare() is used to delete the whole value from map
                // TC -> O(1)
    return 0;
}