#include<iostream>
using namespace std;
int twoPointerApproach(int arr[], int n){
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[j]!=arr[i]){
            arr[i+1]= arr[j];
            i++;
        }
    }
    return i+1;
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
    int newSize= twoPointerApproach(arr, n);
    cout<<"The array with distinct elements is: ";
    for(int i=0; i<=newSize-1; i++){
        cout<<arr[i]<<" ";
    }
}
