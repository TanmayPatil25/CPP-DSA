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
    while(temp){
        cout<< temp->data<<" ";
        temp= temp->next;
    }
    cout<< endl;
}
Node* insertHead(Node* head, int val){
    Node* temp= new Node(val, head);
    return temp;
}
Node* insertTail(Node* head, int val){
    if(head==NULL) return new Node(val);
    Node* temp= head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    Node* nextNode= new Node(val);
    temp->next= nextNode;
    return head;
}
Node* insertAtK(Node* head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }else{
            return head;
        }
    }
    if(k==1){
        return new Node(val, head);
    }
    int cnt=0;
    Node* temp= head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x= new Node(val, temp->next);
            temp->next= x;
            break;
        }
        temp= temp->next;
    }
    return head;
}
Node* insertValue(Node* head, int val, int vtbi){
    if(head==NULL){
        return NULL;
    }
    if(head->data== val){
        return new Node(vtbi, head);
    }
    Node* temp= head;
    while(temp->next != NULL){
        if(temp->next->data==val){
            Node* x= new Node(vtbi, temp->next);
            temp->next= x;
            break;
        }
        temp= temp->next;
    }
    return head;
}
int main(){
    vector<int> arr{12,15,17,19,21};
    Node* head= convertArraytoLL(arr);
    head= insertValue(head, 17, 6);
    print(head);
}