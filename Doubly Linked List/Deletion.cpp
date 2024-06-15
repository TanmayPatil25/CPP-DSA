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
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        delete head;
        return NULL;
    }
    Node* tail= head;
    while(tail->next!=NULL){
        tail= tail->next;
    }
    Node* prev= tail->prev;
    prev->next= nullptr;
    tail->prev= nullptr;
    delete tail;
    return head;
}
Node* deleteAtK(Node* head, int k){
    if(head== NULL){
        return NULL;
    }
    int cnt=0;
    Node* temp= head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp= temp->next;
    }
    Node* prev= temp->prev;
    Node* front= temp->next;
    if(prev==NULL and front==NULL){
        delete head;
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    prev->next= front;
    front->prev= prev;
    temp->prev= nullptr;
    temp->next= nullptr;
    free(temp);
    return head;
}
int main(){
    vector<int> arr{1,3,5,7};
    Node* head= convertArray2DLL(arr);
    head= deleteAtK(head, 5);
    print(head);
}