/*
link:
https://leetcode.com/problems/two-sum/description/
##################################################
question:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
##################################################
result:
$ ./a.out
p[0]=0 p[1]=3
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int x = 0, y = 0;
    int *p = (int *)malloc(2 * sizeof(int));
    for(x = 0; x < numsSize; x++)
        for(y = 0; y < numsSize; y++)
            if( (nums[x] + nums[y]) == target && x != y ){
                p[0] = (x<y)?x:y;
                p[1] = (x>y)?x:y;
                break;
            }
    return p;
}

int main(void){
	int nums[] = {1, 341, 6, 9, 123, 5}, *p = NULL;
	p = twoSum(nums, sizeof(nums)/sizeof(nums[0]), 10);
	printf("p[0]=%d p[1]=%d\n", p[0], p[1]);
	free(p);p = NULL;
	
	return 0;
}

