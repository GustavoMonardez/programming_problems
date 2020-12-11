#include "arrays.h"

int main() {
	int nums1[] = { 1,1,2,2 };
	int n1 = sizeof(nums1) / sizeof(int);

	int nums2[] = { 2,2 };
	int n2 = sizeof(nums2) / sizeof(int);
	
	int n3 = (n1 + n2) * sizeof(int);
	int res = intersect(nums1, n1, nums2, n2, n3);
	print_array(res, n3);
	//printf("res: %d\n", res);
	free(res);
	return 0;
}