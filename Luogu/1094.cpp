#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	int maxPrice,num;
	std::cin >> maxPrice >> num;

	std::vector<int> *priceList = new std::vector<int>();
	assert(priceList);
	for (int i = 0;i < num;i++) {
		int t;
		std::cin >> t;
		priceList->push_back(t);
	}
	std::sort(priceList->begin(),priceList->end());

	std::vector<int>::iterator start = priceList->begin();
	std::vector<int>::iterator end = priceList->end() - 1;
	long int answer = 0;
	while (end >= start) {
		if ((*end + * start) <= maxPrice) {
			start++;
		}
		answer++;
		end--;
	}

	std::cout << answer << std::endl;

	return 0;
}
