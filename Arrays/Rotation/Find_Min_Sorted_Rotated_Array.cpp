#include<iostream>
using namespace std;
    int findPivotBinarySearch(int arr[], int low, int high){
        if(low>=high){
            return -1;
        }
        int mid = (low+high)/2;
        if(mid<high && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(low<mid && arr[mid-1]>arr[mid]){
            return mid-1;
        }
        if(arr[low]>=arr[mid]){
            return findPivotBinarySearch(arr,low,mid);
        }
        return findPivotBinarySearch(arr,mid+1,high);
    }
    int findMin(int arr[], int n){
        //complete the function here
        int pivot = findPivotBinarySearch(arr,0,n-1);
        return arr[pivot+1];
    }


int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    findMin(arr,n);
	}
	return 0;
}