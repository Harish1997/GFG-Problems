// C++ program to find max value of i*arr[i]
#include <iostream>
using namespace std;

/*
	https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/
	The solution for the problem is as follows:
	// arr = [1, 2, 3, 4]
	1. First sum all the elements of the array (1+2+3+4 = 10)
	2. Find index sum of all elements of the array (1*0  +   2*1   +  3*2   +   4*3  = 20)
	3. This index sum is our max value (similar to how we find max element)
	4. To get the new index sum on each rotation use the formula currVal = currVal + arrSum-n*arr[n-j];
*/

// Returns max possible value of i*arr[i]
int maxSum(int arr[], int n)
{
	// Find array sum and i*arr[i] with no rotation
	int arrSum = 0; // Stores sum of arr[i]
	int currVal = 0; // Stores sum of i*arr[i]
	for (int i=0; i<n; i++)
	{
		arrSum = arrSum + arr[i];
		currVal = currVal+(i*arr[i]);
	}

	// Initialize result as 0 rotation sum
	int maxVal = currVal;

	// Try all rotations one by one and find
	// the maximum rotation sum.
	for (int j=1; j<n; j++)
	{
		currVal = currVal + arrSum-n*arr[n-j];
		if (currVal > maxVal)
			maxVal = currVal;
	}

	// Return result
	return maxVal;
}

// Driver program
int main(void)
{
	int arr[] = {1, 20, 2, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "\nMax sum is " << maxSum(arr, n);
	return 0;
}
