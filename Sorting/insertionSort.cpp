#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        for(int j=i; j>0; j--){
            if(arr[j-1]> arr[j]){
                int temp= arr[j-1];
                arr[j-1]= arr[j];
                arr[j]= temp;
            }
        }
    }
}
void insertionSortStriver(int arr[], int n){
    for(int i=1; i<= n-1; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp= arr[j-1];
            arr[j-1]= arr[j];
            arr[j]= temp;
            j--;
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
    insertionSortStriver(arr, n);
    cout<<"The array after sorting: "<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<arr[i]<<" ";
    }
}