//  ************************************ Implementing queue by using array ****************************************

#include<iostream>
#include<queue>
using namespace std;

class Queue {
    
    int* arr;
    int qfront;
    int rear; 
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/
// checking queue is empty or not
    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

// push element in queue
    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

// pop element from queue
    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }

// getting front element of queue
    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main(){
    Queue obj;
    obj.enqueue(10);
    cout<<obj.isEmpty()<<endl;
    cout<<obj.front()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.isEmpty()<<endl;
    cout<<obj.dequeue()<<endl;
    obj.enqueue(20);
    cout<<obj.front()<<endl;
    obj.enqueue(30);
    cout<<obj.front()<<endl;
    return 0;
}