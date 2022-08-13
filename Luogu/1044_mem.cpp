#include<iostream>

int dfs(int queue,int stack)
{
	static int mem[20][20];
	if (mem[queue][stack])
		return mem[queue][stack];
	if (!queue && !stack)
		return 1;
	int ans = 0;
	ans += queue ? dfs(queue - 1,stack + 1) : 0;
	ans += stack ? dfs(queue,stack - 1) : 0;
	mem[queue][stack] = ans;
	return ans;
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::cout << dfs(n,0) << std::endl;
	return 0;
}
