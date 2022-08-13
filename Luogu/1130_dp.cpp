#include<iostream>
#include<algorithm>
#include<climits>

int main()
{
	int groupNum,stepNum;
	std::cin >> stepNum >> groupNum;

	static int cost[2001][2001];
	for (int grp = 0;grp < groupNum;grp++) {
		for (int step = 0;step < stepNum;step++)
			scanf("%d",&cost[step][grp]);
	}

	static int dp[2001][2001];
	for (int step = stepNum - 1;step >= 0;step--) {
		for (int grp = 0;grp < groupNum;grp++) {
			dp[step][grp] = std::min(
					  dp[step + 1][grp],
					  dp[step + 1][(grp + 1) % groupNum]) +
					cost[step][grp];
		}
	}

	int result = INT_MAX;
	for (int grp = 0;grp < groupNum;grp++)
		result = std::min(result,dp[0][grp]);

	std::cout << result << std::endl;

	return 0;
}
