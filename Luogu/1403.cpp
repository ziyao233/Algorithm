#include<iostream>

static long int divisorNum[1000001];

int main()
{
	long int answer = 1;

	int target = 0;
	std::cin >> target;

	/*	Ignore 1	*/
	for (int i = 2;i <= target;i++) {
		answer += divisorNum[i] + 2;
		for (int times = i;times <= target;times += i)
			divisorNum[times]++;
	}

	std::cout << answer << std::endl;

	return 0;
}
