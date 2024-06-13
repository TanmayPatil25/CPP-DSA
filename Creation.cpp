#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* previous;
    public:
    Node(int data1, Node* next1, Node* previous1){
        data= data1;
        next= next1;
        previous= previous1;
    }
    public:
    Node(int data1){
        data= data1;
        next= nullptr;
        previous= nullptr;
    }
};
Node* convertArraytoDLL(vector<int> arr){
}
int main(){
    vector<int> arr{1,2,3,4};
}