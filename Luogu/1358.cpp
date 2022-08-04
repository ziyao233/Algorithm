#include<iostream>

#define G_MOD 10007

int main()
{
	static short int c[10001][102] = { {0,1} };

	for (int i = 1;i < 10001;i++) {
		for (int j = 1;j < 102;j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % G_MOD;
	}

	int peopleNum,cardNum;
	std::cin >> cardNum >> peopleNum;

	int answer = 1;
	while (peopleNum > 0) {
		int expected = 0;
		std::cin >> expected;
		answer = c[cardNum][expected + 1] * answer % G_MOD;
		cardNum -= expected;
		peopleNum--;
	}

	std::cout << answer << std::endl;

	return 0;
}
