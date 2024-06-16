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
Node* middleLL(Node* head){
    Node* temp= head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp= temp->next;
    }
    int midNode= (cnt/2);
    temp= head;
    while(midNode!=0){
        midNode--;
        temp= temp->next;
    }
    return temp;
}
Node* middleLLbS(Node* head){
    Node* temp= head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp= temp->next;
    }
    int midNode= (cnt/2)+1;
    temp= head;
    while(temp!=NULL){
        midNode--;
        if(midNode==0) break;
        temp= temp->next;
    }
    return temp;
}
Node* middleTH(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!=NULL and fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}
int main(){
    vector<int> arr= {12,5,8,7,6,4,5,2};
    Node* head= convertArraytoLL(arr);
    Node* midNode= middleTH(head);
    cout<<midNode->data;
}