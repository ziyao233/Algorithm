#include<iostream>
#include<algorithm>
#include<climits>

int gCost[2001][2001],gGroupNum,gStepNum;

int dfs(int step,int group)
{
	static int mem[2001][2001];
	if (mem[step][group])
		return mem[step][group];

	if (step == gStepNum)
		return 0;

	int ans = std::min(dfs(step + 1,group),
			   dfs(step + 1,(group + 1) % gGroupNum)) +
	          gCost[step][group];
	mem[step][group] = ans;
	return ans;
}

int main()
{
	std::cin >> gStepNum >> gGroupNum;

	for (int grp = 0;grp < gGroupNum;grp++) {
		for (int step = 0;step < gStepNum;step++)
			std::cin >> gCost[step][grp];
	}

	int result = INT_MAX;
	for (int grp = 0;grp < gGroupNum;grp++)
		result = std::min(result,dfs(0,grp));

	std::cout << result << std::endl;

	return 0;
}
