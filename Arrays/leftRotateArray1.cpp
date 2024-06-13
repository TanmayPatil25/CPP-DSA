#include<iostream>
using namespace std;
void leftRotate(int arr[], int n){
    int temp= arr[0];
    for(int i=0; i<n; i++){
        arr[i]= arr[i+1];
    }
    arr[n-1]= temp;
}
int main(){
    int n;
    cout<<"Enter the number of elements to be inserted in the array: ";
    cin>> n;
    int arr[n];
    for(int i=0; i<=n-1; i++){
        cout<<"Enter element at position "<<i+1<<": ";
        cin>>arr[i];
    }
    leftRotate(arr, n);
    cout<<"Array after a left rotation: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}