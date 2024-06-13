#include<iostream>
using namespace std;
void reverseArray(int arr[], int n){
    int rarr[n];
    for(int i=n-1; i>=0; i--){
        rarr[n-i-1]= arr[i];
    }
}
void leftRotateD(int arr[], int n, int d){
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i]= arr[i];
    }
    for(int i= d; i<n; i++){
        arr[i-d]= arr[i];
    }
    for(int i= n-d; i<n; i++){
        arr[i]= temp[i-(n-d)];
    }
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
    int d;
    cout<<"By how many elements do you want to rotate the array left?: ";
    cin>>d;
    d=d%n;
    leftRotateD(arr, n, d);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
