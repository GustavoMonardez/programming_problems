#pragma once

#include <stdbool.h>

void print_array(int* nums, int n);
void rotate(int* nums, int numsSize, int k);
bool containsDuplicate(int* nums, int numsSize);
int singleNumber(int* nums, int numsSize);
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);