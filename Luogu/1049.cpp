#include<iostream>
#include<algorithm>
#include<climits>

#define MAXNUM 30
#define MAXVOL 20001

static int gVolume[MAXNUM];

int solution(int remainVolume,int n)
{
	if (n == -1)
		return remainVolume;

	static int mem[MAXNUM][MAXVOL];
	if (mem[n][remainVolume])
		return mem[n][remainVolume];
	mem[n][remainVolume] = std::min(solution(remainVolume,n - 1),
					gVolume[n] <= remainVolume	   ?
					solution(remainVolume - gVolume[n],
						 n - 1)			   :
					INT_MAX);
	return mem[n][remainVolume];
}

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
	int volume,num;
	std::cin >> volume >> num;

	for (int i = 0;i < num;i++)
		std::cin >> gVolume[i];

	std::cout << solution(volume,num - 1) << std::endl;
	return 0;
}
