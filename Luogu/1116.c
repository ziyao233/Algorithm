#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num = 0;
	scanf("%d",&num);
	int *array = (int*)malloc(sizeof(int) * num);
	for (int i = 0;i < num;i++)
		scanf("%d",array + i);

	int result = 0;
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < i;j++) {
			if (array[i] < array[j]) {
				int tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				result++;
			}
		}
	}

	printf("%d\n",result);

	return 0;
}
