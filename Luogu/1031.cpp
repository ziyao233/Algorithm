#include<iostream>
#include<cassert>

int main()
{
	int stackNum;
	std::cin >> stackNum;

	int *num = new int[stackNum],average = 0;
	assert(num);
	for (int i = 0;i < stackNum;i++) {
		std::cin >> num[i];
		average += num[i];
	}
	average /= stackNum;

	int answer = 0;
	for (int i = 0;i < stackNum - 1;i++) {
		if (num[i] != average) {
			answer++;
			num[i + 1] -= average - num[i];
		}
	}

	std::cout << answer << std::endl;

	return 0;
}
