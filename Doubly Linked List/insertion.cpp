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
Node* insertbHead(Node* head, int val){
    Node* temp= new Node(val, nullptr, head);
    head->prev= temp;
    return temp;
}
Node* insertbTail(Node* head, int val){
    if(head==NULL) return new Node(val);
    Node* temp= head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    Node* back= temp-> prev;
    Node* newNode= new Node(val,back,temp);
    back->next= newNode;
    temp->prev= newNode;
    return head;
}
Node* insertbK(Node*head, int k, int val){
    if(k==1){
        return insertbHead(head, val);
    }
    int cnt=0;
    Node* temp= head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp= temp->next;
    }
    Node* back= temp->prev;
    Node* newNode= new Node(val, back, temp);
    back->next= newNode;
    temp->prev= newNode;
    return head;
}
int main(){
    vector<int> arr{1,2,3,4,5};
    Node* head= convertArraytoDLL(arr);
    head= insertbK(head,5,6);
    print(head);
}