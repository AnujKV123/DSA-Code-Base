#include<iostream>
using namespace std;

int getLen(char name[]){
    int count = 0;
    for(int i=0; name[i] != '\0'; i++){

        count++;
    }
    return count;

}

int main(){

    char name[20];
    cin>>name;

    int x = getLen(name);
    cout<<"The length of string is: "<<x;
    
    return 0;
}