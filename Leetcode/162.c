#include<stdio.h>

#define findPeakElement find_peak_element

int find_peak_element(int *nums,int numSize)
{
	int start = 0,end = numSize - 1;
	while (start < end) {
		int mid = (start + end) >> 1;
		if (nums[mid] > nums[mid + 1]) {
			end = mid;
		} else {
			start = mid + 1;
		}
	}
	return start;
}

int main()
{
	int target = 0;
	scanf("%d",&target);

	int array[target];
	for (int i = 0;i < target;i++)
		scanf("%d",array + target);

	printf("%d\n",find_peak_element(array,target));

	return 0;
}
