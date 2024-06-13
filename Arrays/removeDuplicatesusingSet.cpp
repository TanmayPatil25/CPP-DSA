#include<iostream>
#include<set>
using namespace std;
int removeDuplicates(int arr[], int n){
    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    int index= 0;
    for(auto it: st){
        arr[index]= it;
        index++;
    }
    return index;
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
    int newSize= removeDuplicates(arr, n);
    cout<<"The array with distinct elements is: ";
    for(int i=0; i<=newSize-1; i++){
        cout<<arr[i]<<" ";
    }
}