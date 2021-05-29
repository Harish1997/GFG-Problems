// https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/

/*
Algorithm:
rotate(arr[], d, n)
  reverse(arr[], 1, d) ;
  reverse(arr[], d + 1, n);
  reverse(arr[], 1, n);
*/
void swapper(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void rotate(int arr[], int start, int end) {
    while(start<=end){
        swapper(&arr[start],&arr[end]);
        start++;
        end--;
    }
}

void leftRotate(int arr[], int n, int d) {
    // code here
    rotate(arr,0,d-1);
    rotate(arr,d,n-1);
    rotate(arr,0,n-1);
}