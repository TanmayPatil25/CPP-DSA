#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int data1){
        data= data1;
        prev= nullptr;
        next= nullptr;
    }
    public:
    Node(int data1, Node* prev1, Node* next1){
        data= data1;
        prev= prev1;
        next= next1;
    }
};
Node* convertArray2DLL(vector<int> arr){
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
Node* deleteHead(Node* head){
    if(head== NULL || head->next== NULL){
        delete head;
        return NULL;
    }
    Node* prev= head;
    head= head->next;
    head->prev= nullptr;
    prev->next= nullptr;
    delete prev;
    return head;
}
int main(){
    vector<int> arr{1,3,5,7};
    Node* head= convertArray2DLL(arr);
    head= deleteHead(head);
    print(head);
}