#include "arrays.h"

int main() {
	int nums[] = { 1,2,3,1, 5, 6 };
	int n = sizeof(nums) / sizeof(int);
	int k = 3;

	bool flag = containsDuplicate(nums, n);
	// Testing results
	if (flag) printf("Contains duplicates");
	else printf("Does not contain duplicates");

	return 0;
}