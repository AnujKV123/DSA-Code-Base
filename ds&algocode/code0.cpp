#include<bits/stdc++.h>
using namespace std;

// vector<int> opx(vector<int> &num1, int num2, int N){
//     for(int i=0; i<num2; i++){
//         int var1 = num1[0];
//         for(int j=0; j<N-1; j++){
//              num1[j] = num1[j+1];
//         }
//         num1.push_back(var1);
//     }
//     cout<<endl;
//     return num1;
// }

// int main(){
//     int n, k;
//     vector<int> vx;
//     cin>>n;
//     for(int i=0; i<n; i++){
//         int x;
//         cin>>x;
//         vx.push_back(x);
//     }
//     cin>>k;
//     vector<int> ans = opx(vx, k, n);
//     for(int i=0; i<n; i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }


int main(){
    int a, b, count = 0;
    cin>>a>>b;
    if(a<b){
        for(int i=a; i<=b;i++){
                int x = i, r, rem, arr[10]={0};
                while (x>0)
                {
                    /* code */
                    rem = x%10;
                    if(arr[rem] == 1)
                    break;
                    else
                    arr[rem] = 1;
                    x /=10;

                }
                if(x==0){
                    count++;
                }
        }
    }
    cout<<count;
}