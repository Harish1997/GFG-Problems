/*
https://www.geeksforgeeks.org/find-a-rotation-with-maximum-hamming-distance/
Medium difficulty
Hamming distance refers to the number of unsimilar elements between two arrays or strings
*/
#include<iostream>
using namespace std;
void rotateArrayByOne(int arr[], int n){
    int temp = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}
void maxHammingDistance(int arr[], int n){
    int brr[n];
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    int maxHam = 0;
    for(int j=0;j<n;j++){
        rotateArrayByOne(brr,n);
        int ham=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=brr[i]){
                ham++;
            }
        }
        if(ham>maxHam){
            maxHam=ham;
        }
    }
    cout<<"Max hamming distance is "<<maxHam<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

    }
}