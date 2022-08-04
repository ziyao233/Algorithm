#include<iostream>

int main()
{
	int l,r;
	std::cin >> l >> r;

	int count = 0;
	while (l <= r) {
		count = l & 0x01 || !(l & 0x03) ? count + 1:count;
		l++;
	}

	std::cout << count << std::endl;

	return 0;
}
