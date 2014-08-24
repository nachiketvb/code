#include <iostream>
#include <vector>
#include <map>


#define BASE 142857

using namespace std;

map<pair<unsigned long, unsigned long>, unsigned long> mem;

unsigned long pow(unsigned long a, unsigned long b)
{
	unsigned long soln = 1, temp = a;
	while (b > 0) {
		if (b % 2 != 0) {
			soln *= temp;
			soln %= BASE;
		}
		temp *= temp;
		temp %= BASE;
		b /= 2;
	}
	return soln;
}

unsigned long mult_inverse(unsigned long n)
{
	return pow(n, BASE - 2);
}

unsigned long ncr(unsigned long n, unsigned long r)
{
	unsigned long num = 1, den = 1;
	if ((n - r) < r) {
		r = n - r;
	}
	if (r == 0) {
		return 1;
	}
	for (unsigned long i = 0; i < r; i++) {
		num *= (n - i);
		num %= BASE;
		den *= (r - 1);
		den %= BASE;
	}
	return 
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		unsigned long n, r;
		cin >> n >> r;
		unsigned long soln = 1;
		while (n > 0) {
			unsigned long n1, r1;
			n1 = n % BASE;
			r1 = r % BASE;
			n = n / BASE;
			r = r / BASE;
			soln = (soln * ncr(n1, r1)) % BASE;
		}
		cout << soln << endl;
	}
	return 0;
}
