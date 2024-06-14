#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int data1, Node* prev1, Node* next1){
        data= data1;
        prev= prev1;
        next= next1;
    }
    Node(int data1){
        data= data1;
        prev= nullptr;
        next= nullptr;
    }
};
Node* convertArraytoDLL(vector<int> arr){
    Node* head= new Node(arr[0]);
    Node* prev= head;
    for(int i=1; i<arr.size(); i++){
        Node* temp= new Node(arr[i], prev, nullptr);
        prev->next= temp;
        prev= temp;
    }
    return head;
}
void print(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
int main(){
    vector<int> arr{1,2,3,4,5};
    Node* head= convertArraytoDLL(arr);
    cout<<"The given array: "<<endl;
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<"The Linked List: "<<endl;
    print(head);
}