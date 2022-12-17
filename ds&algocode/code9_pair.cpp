// pair and vector in c++

#include<bits/stdc++.h>

using namespace std;

int main(){
    pair<int, string> p; // method of creating pair

    // p=make_pair(2, "abcd"); // first method storing value in pair

    p = {2, "abcd"}; // second method storing value in pair

    // pair<int, string> p1 = p; // it create only copy of p
    // p1.first = 3;

    pair<int, string> &p1 = p; // it creatr refarence variable of p1
    p1.first = 3;

    cout<<p.first<<" "<<p.second<<endl;
    int a[] = {1,2,3};
    int b[] = {2, 3, 4};

    pair<int, int>p_array[3];

    p_array[0] = {1, 2};
    p_array[1] = {2, 3};
    p_array[2] = {3, 4};

    swap(p_array[0], p_array[2]); //swapping the two pairs 
    
    // taking input in pair
    // cin>>p.first;

    for(int i=0; i<3; i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
}