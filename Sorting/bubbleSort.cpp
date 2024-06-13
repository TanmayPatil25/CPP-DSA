#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        for(int j=0; j<=i; j++){
            if(arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements to be inserted into the array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<=n-1; i++){
        cout<<"Enter the element at position "<<i+1<<": ";
        cin>> arr[i];
    }
    cout<<"The array you entered: "<<endl;
    for(int i=0; i<=n-1; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr, n);
    cout<<"The array after sorting: "<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<arr[i]<<" ";
    }
}