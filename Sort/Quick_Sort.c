/*
 *	Quick Sorting
 */

#include<stdio.h>

int partition(int *left,int range)
{
	int m = left[range - 1];
	
	/*
	 *	The part of array is divided into four parts
	 *	1. Values less than m
	 *	2. Values greater than m
	 *	3. Values not processed
	 *	4. m itself
	 *	| 1 | 2 | 3 | m |
	 */

	
	/*
	 *	p points to the first element in part 2
	 *	i holds the left boundary of part 3
	 */
	int *p = left;
	for (int i = 0;i < range - 1;i++) {
		/*
		 *	If left[i] is less than m,we need to move it to part 1
		 *	Otherwise,simply increase i to extend part 3
		 */
		if (left[i] < m) {
			int t = left[i];
			left[i] = *p;
			*p = t;
			p++;		// Move the pointer
		}
	}

	/*
	 *	Adjust the midvalue's place
	 */
	int t = *p;
	*p = left[range - 1];
	left[range - 1] = t;

	return p - left;		// Substract a pointer from another
					// results the number of elements
					// between them
}

void quick_sort_sub(int *left,int range)
{
	if (range <= 1)		// Already orderd
		return;
	/*
	 *	Here, mid is equal to n - 1,where n is the number of elements
	 *	in the left of the main value
	 */
	int mid = partition(left,range);
	quick_sort_sub(left,mid);
	quick_sort_sub(left + mid + 1,range - mid - 1);
	return;
}

void quick_sort(int *array,int size)
{
	quick_sort_sub(array,size);
}

int main()
{
	int array[] = {1,6,7,3,2,5};
	quick_sort(array,sizeof(array) / sizeof(int));
	for (int i = 0;i < (int)(sizeof(array) / sizeof(int));i++)
		printf("%d\n",array[i]);
	return 0;
}
