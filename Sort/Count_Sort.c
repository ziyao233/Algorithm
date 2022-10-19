#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *	Sort an array with Counting Sort
 */
void count_sort(int *array,int *output,int num,int maxValue)
{
	int *count	= malloc(sizeof(int) * (maxValue + 1));
	assert(count);
	memset(count,0,sizeof(int) * (maxValue + 1));		// XXX:I once forgot this line

	/*
	 *	For all elements,we calculate the number of
	 *	elements less than it.
	 */
	for (int i = 0;i < num;i++)
		count[array[i]]++;			// XXX: array[i] not output[i]

	/*
	 *	Now count[i] holds the time i appears.
	 */
	for (int i = 1;i <= maxValue;i++)
		count[i] += count[i - 1];

	/*
	 *	Put every element in the correct place in output.
	 *	Notice we decrease the counter to avoiding problems
	 *	caused by duplicated numbers
	 */
	for (int i = 0;i < num;i++) {
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}

	free(count);
	return;
}

int main()
{
	int array[] = {1,6,7,7,2,3,5};
	int output[sizeof(array) / sizeof(int)];
	count_sort(array,output,sizeof(array) / sizeof(int),16);

	for (int i = 0;i < (int)(sizeof(array) / sizeof(int));i++)
		printf("%d\n",output[i]);

	return 0;
}
