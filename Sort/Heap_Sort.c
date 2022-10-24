/*
 *	This program relies on a trick.
 *	As the original code in Algorithm Introduction does,
 *	we calculate the index of a node's child by shifting,
 *	If the root node is indexing as 0, then 0 << 1 is 0.
 *	So we take 1 as the index of the root node, and in order
 *	not to waste heap[0], we store the size there
 */
#include<stdio.h>
#include<stdlib.h>


#if 0
/*
 *	Adjust the heap from element idx
 *	in order to meet the requirements of a heap
 *
 *	XXX: There is a tail recursion, which could be
 *	expanded as a loop
 */
void adjust(int *heap,int idx)
{
	int v = heap[idx];
	/*
	 *	XXX: Always notice the priority of bit shifting
	 */
	int child = idx << 1 <= heap[0]		?
			heap[idx << 1] > v ?
				idx << 1   :
				idx		:
			idx;
	child = ((idx << 1) + 1) <= heap[0]	?
			heap[(idx << 1) + 1] > heap[child]	? 
				(idx << 1) + 1			:
				child		:
			child;
	/*
	 *	heap[idx] is a leaf node or it has already been
	 *	larger than its children
	 */
	if (child == idx)
		return;


	heap[idx]	= heap[child];
	heap[child]	= v;
	adjust(heap,child);		// The swapping may break the child tree

	return;
}
#endif

/*
 *	Loop version
 */
void adjust(int *heap,int idx)
{
	int child = 0;
	while (1) {
		int v = heap[idx];
		int child = idx << 1 <= heap[0]		?
				heap[idx << 1] > v ?
					idx << 1   :
					idx		:
				idx;
		child = ((idx << 1) + 1) <= heap[0]	?
				heap[(idx << 1) + 1] > heap[child]	? 
					(idx << 1) + 1			:
					child		:
				child;
		if (child == idx)
			break;


		heap[idx]	= heap[child];
		heap[child]	= v;
		idx = child;
	}
	return;
}

/*
 *	Turn an array into a heap, requiring ONE MORE SLOT available
 */
void heapify(int *array,int size)
{
	array[size] = array[0];
	array[0]    = size;
	for (int i = size;i > 0;i--)
		adjust(array,i);
	return;
}

/*
 *	Sort a heap in heap sort in place, requiring ONE MORE SLOT available
 */
void heap_sort(int *array,int size)
{
	heapify(array,size);

	while (array[0] > 1) {
		/*
		 *	We always pick the maximum element in the heap,
		 *	swap it with the last element (must be a leaf node),
		 *	decrease the heap's size and the adjust the heap
		 */
		int maxValue	= array[1];	// The root element is
						// the maximum one
		array[1]	= array[array[0]];
		array[array[0]]	= maxValue;
		array[0]--;
		adjust(array,1);
	}

	// XXX: Notice that all elements have been moved backward a slot
	return;
}

int main()
{
	int array[] = {1,2,3,4,3,8,0};
	heap_sort(array,sizeof(array) / sizeof(int) - 1);

	// See notes above
	for (int i = 1;i < (int)(sizeof(array) / sizeof(int));i++)
		printf("%d\n",array[i]);

	return 0;
}
