#include "arrays.h"
#include <stdio.h>

void print_array(int* nums, int n) {
	printf("Array: \n");
	for (int i = 0; i < n; ++i) {
		printf("%d, ", nums[i]);
	}
	printf("\n");
}

void reverse_arr(int* nums, int start, int end) {
	int temp;
	while (start < end) {
		temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		++start;
		--end;
	}
}

void rotate(int* nums, int numsSize, int k) {
	if (numsSize == 0) return;
	k = k % numsSize; // acccounts for k bigger than array size
	int half = numsSize - k - 1; // accounts for zero base
	reverse_arr(nums, 0, half); 
	reverse_arr(nums, half + 1, numsSize - 1);
	reverse_arr(nums, 0, numsSize - 1);
}