// *************************** implementation of max heap with 1 based indexing ******************************

#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size = 0;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        // inserting nodes in max heap
        void insert(int val){
            size = size+1;
            int index = size;
            arr[index] = val;

            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void print(){
            for(int i=1; i<=size; i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }


        // deleteing node from max heap
        void Delete(){

            if(size == 0){
                cout<<"Nothing to Delete"<<endl;
                return;
            }

            // step 1 :- put last element into first index
            arr[1] = arr[size];

            // strp 2 :- delete last element
            size--;

            // step 3 :- take root node to its correct position
            int i = 1;
            while(i<size){
                int leftIndex = i*2;
                int rightIndex = i*2 + 1;
                
                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[leftIndex], arr[i]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[rightIndex], arr[i]);
                    i = rightIndex;
                }
                else{
                    return;
                }
            }
        }
};

void heapify(int arr[], int n, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    heap h;
    h.insert(23);
    h.insert(24);
    h.insert(25);
    h.insert(30);
    // h.insert(44);
    // h.print();
    // h.Delete();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout<<"printing the array now "<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}