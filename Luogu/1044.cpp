#include<iostream>

int main()
{
	static int dp[20][20] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}};
	int n = 0;
	std::cin >> n;

	for (int queue = 1;queue <= n;queue++) {
		for (int stack = 0;stack <= n;stack++) {
			dp[queue][stack] = dp[queue - 1][stack + 1] +
					   (stack ? dp[queue][stack - 1] : 0);
		}
	}

	std::cout << dp[n][0] << std::endl;

	return 0;
}
