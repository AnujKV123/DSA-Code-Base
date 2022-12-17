//  iterators in stl

#include<bits\stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // creating iterator
    vector<int>::iterator it = v.begin(); // .begin() pointing to the first address of vector
    cout<<(*(it+1))<<endl;
    for(it = v.begin(); it != v.end(); ++it){ // .end() pointing to the last+1 address of vector
        cout<<*it<<endl;
    }

    // iterator of pair
    vector<pair<int, int>> v1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<pair<int, int>>::iterator it1;
    // for(it1 = v1.begin(); it1 != v1.end(); ++it1){ // .end() pointing to the last+1 address of vector
    //     cout<<(*it1).first<<" "<<(*it1).second<<endl;
    // }

    for(it1 = v1.begin(); it1 != v1.end(); ++it1){ // (*it1).first <=> it1->second
        cout<<(it1->first)<<" "<<(it1->second)<<endl;
    }

    // increamenting the value of elements of vectoe by using Range based loop in c++ stl
    for(int &value : v){  // &value is a reference variable of value
        value++;
    }

    // Range based loop in c++ stl
    for(int value : v){  // &value is a copy variable of value
        cout<<value<<endl;
    }

// auto keyword in c++
    // auto keyword autometically assume the data type of variable by seeing what data type of data assign in the variable

    auto a = 1; // data type = int
    auto b = 1.0; // data type = float

    // iteratin of vector by using auto keyword
     vector<int> v3 = {10, 11, 12, 13, 14};

    for(auto it = v3.begin(); it != v3.end(); ++it){ 
        cout<<*it<<endl;
    }

    return 0;
}