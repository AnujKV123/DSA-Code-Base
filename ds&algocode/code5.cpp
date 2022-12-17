// C++ Program to display marks of 5 students

#include <iostream>
using namespace std;

// declare function to display marks
// take a 1d array as parameter

// Passing the Entire Array ********************
// void display(int m[5]) {

// Passing Data Values ******************
// void display(int m) {

// Passing Addresses
void display(int *m) {
    cout << "Displaying marks: " << endl;

    // display array elements    

    // Passing the Entire Array
    // for (int i = 0; i < 5; ++i) {
    //     cout << "Student " << i + 1 << ": " << m[i] << endl;
    // }

    //Passing Data Values
    // cout << "Student " << 1 << ": " << m << endl;

    //Passing Addresses
    cout << "Student " << 1 << ": " << *m << endl;
        
}

int main() {

    // declare and initialize an array
    int marks[5] = {88, 76, 90, 61, 69};
    
    // call display function
    // pass array as argument

// Passing the Entire Array
    // display(marks);

    //Passing Data Values
    // display(marks[3]);

    //Passing Addresses
    display(&marks[3]);

    return 0;
}