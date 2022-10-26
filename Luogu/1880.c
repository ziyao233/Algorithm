/*
 *	Refer to my blog: https://url/Luogu_P1880.html
 *	for details
 */

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define MAXNUM 200

static int stoneNum[MAXNUM];
static int stoneSum[MAXNUM][MAXNUM];	// Pre-calculated

static inline int max(int a,int b)
{
	return a > b ? a : b;
}

static inline int min(int a,int b)
{
	return a < b ? a : b;
}

static int max_solution(int l,int r)
{
	if (l == r)
		return 0;

	static int mem[MAXNUM][MAXNUM];		// Automatically set to zero
	if (mem[l][r])				// Already calculated
		return mem[l][r];
	int ans = 0;
	/*
	 *	cut is the position where we split the interval
	 *	For an interval with length k, we could split it at k - 1
	 *	different positions.
	 */
	for (int cut = l;cut < r;cut++)	
		ans = max(max_solution(l,cut) + max_solution(cut + 1,r),ans);

	return mem[l][r] = ans + stoneSum[l][r];
}

static int min_solution(int l,int r)
{
	if (l == r)
		return 0;

	static int mem[MAXNUM][MAXNUM];
	if (mem[l][r])
		return mem[l][r];
	// int ans = 1145141919810; OVERFLOW :(
	int ans = INT_MAX;
	for (int cut = l;cut < r;cut++)
		ans = min(min_solution(l,cut) + min_solution(cut + 1,r),ans);
	return mem[l][r] = ans + stoneSum[l][r];
}


int main(void)
{
	int num = 0;
	scanf("%d",&num);
	for (int i = 0;i < num;i++) {
		scanf("%d",stoneNum + i);
		stoneNum[i + num] = stoneNum[i];
		stoneSum[i][i] = stoneNum[i];
		stoneSum[i + num][i + num] = stoneNum[i];
	}

	/*
	 *	Calcutate the summaries, less memory could be used.
	 */
	for (int l = 0;l < (num << 1);l++) {
		for (int r = l + 1;r < (num << 1);r++)
			stoneSum[l][r] = stoneSum[l][r - 1] + stoneNum[r];
	}

	int minPrice = INT_MAX,maxPrice = 0;
	for (int i = 0;i < num;i++) {
		minPrice = min(minPrice,min_solution(i,i + num - 1));
		maxPrice = max(maxPrice,max_solution(i,i + num - 1));
	}
	printf("%d\n%d\n",minPrice,maxPrice);

	return 0;
}
