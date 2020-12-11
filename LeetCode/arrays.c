#include "arrays.h"
#include <stdio.h>

int compare_ints(const void* p1, const void* p2) {
	return (*(int*)p1 - *(int*)p2);
}

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

int singleNumber(int* nums, int numsSize) {
	if (numsSize == 1) return nums[0];

	int res = nums[0];

	for (int i = 1; i < numsSize; ++i) {
		res ^= nums[i];
	}
	return res;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* res = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
	qsort(nums1, nums1Size, sizeof(int), compare_ints);
	qsort(nums2, nums2Size, sizeof(int), compare_ints);

	int i = 0, j = 0, k = 0;

	while (i < nums1Size && j < nums2Size) {
		if (nums1[i] == nums2[j]) {
			res[k++] = nums1[i];
			++i;
			++j;
		} else if (nums1[i] < nums2[j]) {
			++i;
		} else {
			++j;
		}
	}
	*returnSize = k;
	return res;
}