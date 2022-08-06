#include<iostream>
#include<algorithm>
#include<vector>

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

struct Fraction {
	int denominator,numerator;
	float value;
	Fraction(int denominator,int numerator)
	{
		this->value = (float)numerator / denominator;
		this->denominator = denominator;
		this->numerator = numerator;
	}
	bool operator < (const struct Fraction &to)
	{
		return value < to.value;
	}
};

int main()
{
	int target = 0;
	std::cin >> target;

	std::cout << "0/1" << std::endl;

	std::vector<Fraction> *list = new std::vector<Fraction>();
	for (int denominator = 2;denominator <= target;denominator++) {
		for (int numerator = 1;numerator < denominator;numerator++) {
			if (gcd(denominator,numerator) == 1) {
				struct Fraction frac(denominator,
						     numerator);
				list->push_back(frac);
			}
		}
	}

	std::sort(list->begin(),list->end());
	for (std::vector<Fraction>::iterator iter = list->begin();
	     iter != list->end();iter++) {
		std::cout << iter->numerator << "/" << iter->denominator;
		std::cout << std::endl;
	}

	std::cout << "1/1" << std::endl;

	return 0;
}
