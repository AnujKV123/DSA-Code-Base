#include<iostream>
using namespace std;

void revStr(char name[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s], name[e]);
        s++;
        e--;
    }

}

int main(){

    char name[20];
    cin>>name;
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){

        count++;
    }
    revStr(name, count);
    cout<<"The string after reverse: ";
    cout<<name;
    
    return 0;
}