#include<iostream>
using namespace std;
int largestElement(int arr[], int n){
    int largest= arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest= arr[i];
        }
    }
    return largest;
}
int secondLargestElement(int arr[], int n){
    int largest= arr[0];
    int secondLargest= -1;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            secondLargest= largest;
            largest= arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest= arr[i];
        }
    }
    return secondLargest;
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
    cout<<"The largest element is: "<<largestElement(arr, n)<<endl;
    cout<<"The second largest element is: "<<secondLargestElement(arr, n)<<endl;
}