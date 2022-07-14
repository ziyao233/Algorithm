#include<iostream>
#include<cmath>

class Solution {
public:
	int mySqrt(int x)
	{
		double res = x / 2.;
		while (std::fabs(res * res - (double)x) > 0.1)
			res = (res + x / res) / 2.;
		return (int)std::floor(res);
	}
};

int main()
{
	int x = 0;
	auto obj = new Solution;
	std::cin >> x;
	std::cout << obj->mySqrt(x) << std::endl;
	return 0;
}
