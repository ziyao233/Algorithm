#include<iostream>

int dfs(int queue,int stack)
{
	if (!queue && !stack)
		return 1;
	int ans = 0;
	ans += queue ? dfs(queue - 1,stack + 1) : 0;
	ans += stack ? dfs(queue,stack - 1) : 0;
	return ans;
}

int main()
{
	int n = 0;
	std::cin >> n;
	std::cout << dfs(n,0) << std::endl;
	return 0;
}
