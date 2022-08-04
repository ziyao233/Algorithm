#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int length = 0,sectionNum = 0;
	scanf("%d%d",&length,&sectionNum);

	_Bool *flag = (_Bool*)malloc(sizeof(_Bool) * (length + 1));
	assert(flag);
	memset(flag,0,length);

	int result = length + 1;
	for (int i = 0;i < sectionNum;i++) {
		int left,right = 0;
		scanf("%d%d",&left,&right);
		for (int p = left;p <= right;p++) {
			if (!flag[p]) {
				result--;
				flag[p] = !flag[p];
			}
		}
	}

	printf("%d\n",result);
	return 0;
}
