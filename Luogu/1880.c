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
	int ans = 0;
	for (int cut = l;cut < r;cut++)
		ans = max(max_solution(l,cut) + max_solution(cut + 1,r),ans);
	return ans + stoneSum[l][r];
}

static int min_solution(int l,int r)
{
	if (l == r)
		return 0;
	// int ans = 1145141919810;
	int ans = INT_MAX;
	for (int cut = l;cut < r;cut++)
		ans = min(min_solution(l,cut) + min_solution(cut + 1,r),ans);
	return ans + stoneSum[l][r];
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
		for (int j = 0;j < i;j++) {
			stoneSum[j][i] = stoneSum[j][i - 1] + stoneNum[i];
			stoneSum[j + num][i + num] = stoneSum[j + num][i + num - 1] + stoneNum[i + num];
		}
	}

	int minPrice = INT_MAX,maxPrice = 0;
	for (int i = 0;i < num << 1;i++) {
		minPrice = min(minPrice,min_solution(i,i + num - 1));
		maxPrice = max(maxPrice,max_solution(i,i + num - 1));
	}
	printf("%d\n%d\n",minPrice,maxPrice);

	return 0;
}
