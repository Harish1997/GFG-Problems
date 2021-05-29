#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void reverse(int arr[], int low, int high){
    while(low<high){
        swap(&arr[low],&arr[high]);
        low++;
        high--;
    }
}
void rightRotate(int arr[], int n, int k){
    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        rightRotate(arr,n,k);
        cout<<"Rotated array is "<<endl;
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
    }
}