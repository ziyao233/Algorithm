#include<iostream>
#include<algorithm>

#define MAXSIZE 9

static int gValue[MAXSIZE][MAXSIZE];

int walk(int size,int x1,int y1,int x2,int y2)
{
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
		return 0;
	static int mem[MAXSIZE][MAXSIZE][MAXSIZE][MAXSIZE];
	if (mem[x1][y1][x2][y2])
		return mem[x1][y1][x2][y2];
	int result = walk(size,x1,y1 - 1,x2,y2 - 1);
	result = std::max(result,walk(size,x1,y1 - 1,x2 - 1,y2));
	result = std::max(result,walk(size,x1 - 1,y1,x2,y2 - 1));
	result = std::max(result,walk(size,x1 - 1,y1,x2 - 1,y2));
	mem[x1][y1][x2][y2] =
		result + (x1 == x2 && y1 == y2 ?
				0 : gValue[x1][y1])
		       + gValue[x2][y2];
	return mem[x1][y1][x2][y2];
}

int main()
{
	int size = 0;
	std::cin >> size;

{
	int x,y,value;
	do {
		std::cin >> x >> y >> value;
		if (x)
			gValue[x - 1][y - 1] = value;
	} while(x);
}

	std::cout << walk(size,size - 1,size - 1,
			  size - 1,size - 1)
		  << std::endl;
	return 0;
}
