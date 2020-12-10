#include "arrays.h"

int main() {
	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(nums) / sizeof(int);
	int k = 3;

	print_array(nums, n);
	rotate(nums, n, k);
	print_array(nums, n);
	return 0;
}