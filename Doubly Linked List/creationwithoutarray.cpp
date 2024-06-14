#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1){
        data= data1;
        next= nullptr;
        prev= nullptr;
    }
    public:
    Node(int data1, Node* next1, Node* prev1){
        data= data1;
        next= next1;
        prev= prev1;
    }
};
void insertNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp; // Link the new node's prev pointer to the current node
    }
}
void print(Node* &head){
    Node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
int main(){
    Node* head= nullptr;
    int cnt;
    cout<<"How many nodes do we want to insert: ";
    cin>> cnt;
    int element;
    for(int i=0; i<cnt; i++){
        cout<<"Enter element at position "<<i+1<<":";
        cin>> element;
        insertNode(head, element);
    }
    print(head);
}