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
int lengthofLL(Node* head){
    int count=0;
    Node*temp= head;
    while(temp){
        temp= temp->next;
        count++;
    }
    return count;
}
void print(Node* head){
    Node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp-> next;
    }
}
Node* startOfLoop(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!=NULL and fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
        if(fast==slow){
            slow= head;
            while(slow!=fast){
                slow= slow->next;
                fast= fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main(){
    vector<int> arr= {12,5,8,7};
    Node* head= convertArraytoLL(arr);
    Node* loopStart= startOfLoop(head);
    cout<<loopStart->data;
}