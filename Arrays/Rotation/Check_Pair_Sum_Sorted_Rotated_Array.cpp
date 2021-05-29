/*
    Refer https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
    Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
    Output: true
    There is a pair (6, 10) with sum 16
*/

// Complexity - O(N)
#include <iostream>
using namespace std;
int findPivotBinarySearch(int arr[], int low, int high) {
    if(high<low){
        return -1;
    }
    if(low == high){
        return low;
    }
    int mid = (low+high)/2;
    if(mid<high && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(low<mid && arr[mid-1]>arr[mid]){
        return mid-1;
    }
    
    if(arr[low]>=arr[mid]){
        return findPivotBinarySearch(arr,low,mid-1);
    } 
    return findPivotBinarySearch(arr,mid+1,high);
}
void checkPairWithSum(int arr[],int n,int x){
    int pivot = findPivotBinarySearch(arr, 0, n-1);
    int left = pivot+1;
    int right = pivot;

    if(pivot == -1) {
       left = 0;
       right = n-1;
    }
    
    while(left!=right) {
        if(arr[left]+arr[right]==x){
            cout<<"Pairs found at positions "<<left+1<<" and "<<right+1<<endl;
            break;
        } else if(arr[left]+arr[right]<x){
            left=(left+1)%n;
        } else {
            right = (right-1+n)%n;
        }
    }
    
    if(left==right){
        cout<<"No pairs found for the sum "<<x<<endl;
    }
}
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    checkPairWithSum(arr,n,x);
	}
	return 0;
}