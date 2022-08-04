#include<stdio.h>

int main()
{
	int height[10];

	for (int i = 0;i < 10;i++)
		scanf("%d",height + i);

	int limitation = 0;
	scanf("%d",&limitation);
	limitation += 30;

	int result = 0;
	for (int i = 0;i < 10;i++)
		result = height[i] <= limitation ? result + 1: result;

	printf("%d\n",result);

	return 0;
}
