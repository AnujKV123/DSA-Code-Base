#include <iostream>

using namespace std;

// creating a simple linked list *************************************************


// struct Node
// {
//     int data;
//     Node *link;
// };

// Node *head = NULL;
// int main(){
//     Node *ptr = new Node();
//     ptr->data = 2;
//     ptr->link = NULL;
//     head=ptr;
//     cout << head->data;
//     return 0;
// }

// inserting a node in linked list ************************************************

struct Node
{
    int data;
    Node *link;
};
Node *head = NULL;

void insertBeg(int d){
    Node *ptr = new Node();
    ptr->data=d;
    ptr->link=head;
    head=ptr;
}

void insertEnd(int d){
    Node *ptr = new Node();             // CREATING new node
    ptr->data = d;
    ptr->link = NULL;

    if(head == NULL){                   // List is empty
        head = ptr;
    }
    else{                               // List is not empty
        Node *temp = head;
        while (temp->link != NULL){    //traversing the list
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

int main(){
    Node *ptr = new Node();
    ptr->data = 2;
    ptr->link = NULL;
    head=ptr;
    insertEnd(5);
    insertBeg(10);
    while (head != NULL) {
    cout << head->data<<endl;
    head = head->link;
  }
    return 0;
}

// linked list implementation with another method ******************************************

// struct node
// {
//     int data;
//     node *next;
// };

// class linked_list
// {
// private:
//     node *head,*tail;
// public:
//     linked_list()
//     {
//         head = NULL;
//         tail = NULL;
//     }

//     void add_node(int n)
//     {
//         node *tmp = new node;
//         tmp->data = n;
//         tmp->next = NULL;

//         if(head == NULL)
//         {
//             head = tmp;
//             tail = tmp;
//         }
//         else
//         {
//             tail->next = tmp;
//             tail = tail->next;
//         }
//     }
// };

// int main()
// {
//     linked_list a;
//     a.add_node(1);
//     a.add_node(2);
//     return 0;
// }
