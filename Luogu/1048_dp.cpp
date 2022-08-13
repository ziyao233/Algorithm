#include<iostream>
#include<algorithm>
#include<map>

int main()
{
	int num = 0,time = 0;
	std::cin >> time >> num;
	int *timeConsume = new int[num + 1],*value = new int[num + 1];
	int dp[101][1001];

	for (int i = 1;i <= num;i++)
		std::cin >> timeConsume[i] >> value[i];

	for (int idx = 1;idx <= num;idx++) {
		for (int t = 1;t <= time;t++) {
			if (timeConsume[idx] > t) {
				dp[idx][t] = dp[idx - 1][t];
			} else {
				dp[idx][t] = std::max(dp[idx - 1][t],
						      dp[idx - 1]
						        [t- timeConsume[idx]] +
						      value[idx]);
			}
		}
	}

	std::cout << dp[num][time] << std::endl;

	delete [] timeConsume;
	delete [] value;

	return 0;
}
