#include<stdio.h>
#include<stdbool.h>

int width,height;
static _Bool visited[5][5];
int targetX,targetY;

long int dfs(int x,int y)
{
	if (visited[x][y])
		return 0;
	if (x == targetX && y == targetY)
		return 1;

	visited[x][y] = true;
	long int res = 0;
	res += x + 1 < width ? dfs(x + 1,y) : 0;
	res += x > 0 ? dfs(x - 1,y)	 : 0;
	res += y + 1 < height ? dfs(x,y + 1) : 0;
	res += y > 0 ? dfs(x,y - 1)	  : 0;
	visited[x][y] = false;
	return res;
}

int main()
{
	int blockedNum = 0;
	scanf("%d%d%d",&width,&height,&blockedNum);

	int startX,startY;
	scanf("%d%d%d%d",&startX,&startY,&targetX,&targetY);
	targetX--,targetY--;

	for (int i = 0;i < blockedNum;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		visited[x - 1][y - 1] = true;
	}

	printf("%ld\n",dfs(startX - 1,startY - 1));

	return 0;
}
