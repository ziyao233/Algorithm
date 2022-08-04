#include<iostream>
#include<cmath>

int main()
{
	unsigned long int target = 0;
	std::cin >> target;

	unsigned long int doubled = target << 1;
	for (unsigned long int a = 1;a < target - 1;a++) {
		unsigned long int b = ((unsigned long int)sqrt(1 + (target << 3) +  ((a * a - a) << 2)) - 1) >> 1;
		if ((a + b) * (b - a + 1) == doubled) {
			std::cout << a << " " << b << std::endl;
		}
	}

	return 0;
}
