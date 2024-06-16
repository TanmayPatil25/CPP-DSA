#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data= data1;
        next= next1;
    }
    Node(int data1){
        data= data1;
        next= nullptr;
    }
};
Node* convertArraytoLL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover= head;
    for(int i=1; i<arr.size(); i++){
        Node* temp= new Node(arr[i]);
        mover->next= temp;
        mover= temp;
    }
    return head;
}
void print(Node* head){
    Node* temp= head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
Node* reverseLL(Node* head){
    Node* prev= nullptr;
    Node* temp= head;
    while(temp!=NULL){
        Node* front= temp->next;
        temp->next= prev;
        prev= temp;
        temp= front;
    }
    return prev;
}
Node* revByRec(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* newHead= revByRec(head->next);
    Node* front= head->next;
    front->next= head;
    head-> next= NULL;
    return newHead;
}
int main(){
    vector<int> arr= {12,5,8,7};
    Node* head= convertArraytoLL(arr);
    head= revByRec(head);
    print(head);
}