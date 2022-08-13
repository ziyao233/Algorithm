#include<iostream>
#include<algorithm>
#include<map>

int dfs(const int *timeConsume,const int *value,int idx,int remainTime)
{
	static int mem[101][1001];
	if (mem[idx][remainTime])
		return mem[idx][remainTime];
	if (!idx) {
		return *timeConsume <= remainTime ? *value : 0;
	}

	int retVal = dfs(timeConsume,value,idx - 1,remainTime);
	retVal = remainTime >= timeConsume[idx] ?
			std::max(dfs(timeConsume,value,idx - 1,
				     remainTime - timeConsume[idx]) +
				 value[idx],retVal):
			retVal;
	mem[idx][remainTime] = retVal;
	return retVal;
}

int main()
{
	int num = 0,time = 0;
	std::cin >> time >> num;
	int *timeConsume = new int[num],*value = new int[num];

	for (int i = 0;i < num;i++)
		std::cin >> timeConsume[i] >> value[i];

	std::cout << dfs(timeConsume,value,num - 1,time) << std::endl;

	delete [] timeConsume;
	delete [] value;

	return 0;
}
