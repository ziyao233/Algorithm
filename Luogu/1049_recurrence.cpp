#include<iostream>
#include<algorithm>
#include<climits>

#define MAXNUM 31
#define MAXVOL 20001

/*
 *	The recurrence equation, in fact, is 
 *		dp[v][i] =	v				if i == 0
 *				dp[v][i - 1]			if i != 0 &&
 *								   volume[i] > v
 *				min(dp[v - volume[i]][i - 1],
 *				    dp[v][i - 1])		otherwise
 */
int main()
{
	int totalVolume,num;
	std::cin >> totalVolume >> num;

	static int volume[MAXNUM];
	for (int i = 1;i <= num;i++)
		std::cin >> volume[i];

	static int dp[MAXNUM][MAXVOL];
	for (int v = 0;v <= totalVolume;v++)
		dp[0][v] = v;

	for (int v = 1;v <= totalVolume;v++) {
		for (int i = 1;i <= num;i++) {
			dp[i][v] = std::min(dp[i - 1][v],
					    volume[i] <= v ?
						dp[i - 1][v - volume[i]] :
						INT_MAX);
		}
	}

	std::cout << dp[num][totalVolume] << std::endl;
		
	return 0;
}
