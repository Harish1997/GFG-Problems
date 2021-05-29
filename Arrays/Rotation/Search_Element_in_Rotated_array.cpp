/*
This problem involves Binary Search
We use binary search twice to find the pivot element and to find the key element
Refer: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
*/
// Complexity: O(LogN)


/*
Approach: 
 
1. The idea is to find the pivot point, divide the array in two sub-arrays and perform binary search.
2. The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element for which next element to it is smaller than it.
3. Using the above statement and binary search pivot can be found.
4. After the pivot is found out divide the array in two sub-arrays.
5. Now the individual sub – arrays are sorted so the element can be searched using Binary Search.
*/
#include<iostream>
using namespace std;
    int binarySearch(int arr[], int left, int right, int key){
        if(right<left){
            return -1;
        }
        
        int mid = (left + right)/2;
        
        if(key == arr[mid]){
            return mid;
        } else if(key < arr[mid]){
            return binarySearch(arr,left,mid-1,key);
        } else {
            return binarySearch(arr,mid+1,right,key);
        }
    }
    
    // ignore this func
    int findPivotLinearSearch(int arr[], int l, int h) {
        for(int i=l;i<h;i++){
            if(arr[i]>arr[i+1]){
                return i;
            }
        }
        return -1;
    }
    
    int findPivotBinarySearch(int arr[], int low, int high){
        if(high<low){
            return -1;
        }
        if(high==low){
            return low;
        }
        
        int mid = (low + high)/2;
        if(mid<high && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(mid>low && arr[mid]<arr[mid-1]) {
            return mid-1;
        }
        if(arr[low]>=arr[mid]){
            return findPivotBinarySearch(arr,low,mid-1);
        }
        return findPivotBinarySearch(arr,mid+1,high);
    }
    
    int findElement(int arr[], int l, int h, int key){
    //complete the function here

        /*
            First we find the element, i.e the index where the previosu element is greater than next element
            arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
            here pivot is index 6
        */
        int pivot = findPivotBinarySearch(arr,l,h);
        
        // Basically if its not a rotated array, there is no pivot
         if (pivot == -1){
            return binarySearch(arr, l, h, key);
         }
        
        if(arr[pivot] == key) {
            return pivot;
        }
        
        if(arr[0]<=key) {
            return binarySearch(arr, 0, pivot-1, key);
        }else {
            return binarySearch(arr,pivot+1,h,key);
        }
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
        int k;
        cin>>k;
        cout<<findElement(arr,0,n-1,k)<<endl;
    }
}

