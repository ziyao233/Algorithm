#include<stdio.h>

int main()
{
	int k = 0;
	scanf("%d",&k);

	int ans = k;
	while (1) {
		int p = 0;
		for (int i = k << 1;i > k;i--) {
			p = (ans + p) % i;
			if (p < k)
				goto nextLoop;
		}
		break;
nextLoop:
		ans++;
	}

	printf("%d\n",ans + 1);
	return 0;
}
