/*

From the description of f(i),we could rewrite f(i)
f(i) = sum (k = 1 -> i) [k | i]
a | b means that a is a divisor of b.
The mark,[ condition ],introduced in Iverson's APL and used widely in
	Knuth's Concrete Mathematics,means
	[q] = 1		if q is true
	      0		else
Our answer is		sum (d = 1 -> n) f(d)
	is equal to
		sum (d = 1 -> n) (sum (k = 1 -> d) [k | d])
	is equal to
		sum (d = 1 -> n) (sum (k = 1 -> n) [k | d])
	The reason is that any number larger than k could not
		k's divisor.This change remove dependency of d
		in the inner summary,which makes the next step
		easier.

	Exchange the order of summaries to make it clearer
		sum (k = 1 -> n) (sum (d = 1 -> n) [k | d] )

	The problem,now,is transformed into
		how many multiples of k are there between 1 and n.
	This coule be easily down.The answer is floor(n / d).

	The solution is sum (k = 1 -> n) floor(n / k)
*/

#include<iostream>

int main()
{
	long int answer = 0;
	int target = 0;
	std::cin >> target;
	for (int k = 1;k <= target;k++)
		answer += target / k;

	std::cout << answer << std::endl;

	return 0;
}
