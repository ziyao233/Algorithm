#include<iostream>
#include<cstdint>

int64_t gcd(int64_t a,int64_t b)
{
	return b ? gcd(b,a % b) : a;
}

int main()
{
	int sampleNum = 0;
	std::cin >> sampleNum;

	for (int i = 0;i < sampleNum;i++) {
		int64_t l = 0,r = 0,step = 0;
		std::cin >> l >> r >> step;

		l = l / step;
		int64_t result = l;
		for (;result != 1 && l <= r / step;l++)
			result = gcd(result,l);
		std::cout << result << std::endl;
	}

	return 0;
}
