#include<iostream>
using namespace std;
bool checkingArray(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        if(arr[i]<arr[i+1]){

        }
        else return false;
    }
    return true;
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
    int value= checkingArray(arr, n);
    if(value==1){
        cout<<"The given array is sorted.";
    }else{
        cout<<"The given array is not sorted.";
    }
}