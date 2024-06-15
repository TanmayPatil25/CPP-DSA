#include<iostream>
#include<vector>
#include<stack>
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
Node* reverseDLL(Node* head){
    Node* temp= head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp= temp->next;
    }
    temp= head;
    while(temp!=NULL){
        temp->data= st.top();
        st.pop();
        temp= temp->next;
    }
    return head;
}
Node* rbySwap(Node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node* prev= NULL;
    Node* current= head;
    while(current!= NULL){
        prev= current->prev;
        current->prev= current->next;
        current->next= prev;
        current= current->prev;
    }
    return prev->prev;
}
int main(){
    vector<int> arr{6,7,8,9,10};
    Node* head= convertArraytoDLL(arr);
    head= rbySwap(head);
    print(head);
}