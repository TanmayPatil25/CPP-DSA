#include<iostream>
#include<vector>
using namespace std;
//For object oriented features use class instead of struct.
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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
bool loopDetection(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!=NULL and fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
int main(){
    vector<int> arr= {12,5,8,7};
    Node* head= convertArraytoLL(arr);
    cout<< loopDetection(head);
}