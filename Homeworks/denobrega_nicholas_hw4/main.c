#include <stdio.h>

// Returns n-th term in fibonacci sequence using iteration
extern int fib_seq(unsigned n);
// Modifies arr in-place to sort it using bubble sort
extern int bubble_sort(int *arr, unsigned len);
// Returns index of target in arr using binary search
extern int binary_search(int *arr, unsigned len, unsigned target);

int main(){
	//1. Testing fib_seq
	printf("%d\n", fib_seq(20));

	//2. Testing bubble_sort
	int arr[] = {7,100,5,50,1,36,77,20,0};
	unsigned int len = sizeof(arr) / sizeof(arr[0]);
	printf("Original Array: ");
	for (int i = 0; i < len; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, len);
	printf("Sorted Array: ");
	for (int i = 0; i < len; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");

	//3. Testing Binary Search
	int arr2[] = {5,5,5,5};
	unsigned int len2 = sizeof(arr2) / sizeof(arr2[0]);
	int target = 5;
	printf("%d\n",binary_search(arr2,len2,target));

	return 0;
}
