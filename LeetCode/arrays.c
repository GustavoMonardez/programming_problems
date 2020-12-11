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

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
	if (numsSize <= 1) return false;
	if (numsSize == 2) return (nums[0] == nums[1]) ? true : false;

	qsort(nums, numsSize, sizeof(int), comp);

	for (int i = 0; i < numsSize - 1; i++) {
		if (nums[i] == nums[i + 1]) return true;
	}

	return false;
}