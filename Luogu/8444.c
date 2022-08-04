#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b)
{
	return *(const int*)a > *(const int*)b;
}

int main()
{
	int num = 0;
	scanf("%d",&num);

	int *value = (int*)malloc(sizeof(int) * num);
	assert(value);

	for (int i = 0;i < num;i++)
		scanf("%d",value + i);

	qsort(value,num,sizeof(int),compare);

	int result = 0,money = 0;
	scanf("%d",&money);
	int last = num - 1;
	for (;last >= 0;last--) {
		if (money >= value[last])
			break;
	}
	money = last => 0 ? value[last] : 0;

	for (int i = 0;i <= last;i++) {
		if (money < value[i]) {
			break;
		} else {
			money -= value[i];
		}
		result++;
	}

	printf("%d\n",result);

	return 0;
}
