#include<stdio.h>

int main()
{
	int result = 0,day = 0;
	for (int i = 0;i < 7;i++) {
		int a = 0,b = 0;
		scanf("%d%d",&a,&b);
		if ((a + b > 8) && (a + b > result)) {
			day = i + 1;
			result = a + b;
		}
	}
	printf("%d\n",day);
	return 0;
}
