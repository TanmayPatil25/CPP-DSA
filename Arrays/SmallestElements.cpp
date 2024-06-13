#include<iostream>
#include<utility>
using namespace std;
int smallest(int arr[], int n){
    int smallest= arr[0];
    int ssmallest= INT16_MAX;
    for(int i=1; i<n; i++){
        if(arr[i]<smallest){
            ssmallest= smallest;
            smallest= arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest= arr[i];
        }
    }
    return ssmallest;
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
    cout<<"The second smallest element is: "<<smallest(arr, n)<<endl;
}