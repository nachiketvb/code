/* Extended Euclid's Algorithm */
#include <iostream>
#include <sstream>
using namespace std;

void extended_euclid(int num1, int num2, int &gcd,
		int &coef1, int &coef2)
{
	int rem;
	int coef1_, coef2_;
	if (num2 == 0) {
		gcd = num1;
		coef1 = 1;
		coef2 = 0;
		return;
	}
	rem = num1 % num2;
	// gcd = s'.num2 + t'.rem
	// gcd = s'num2 + t'.(num1 - floor(num1 / num2).num2)
	// gcd = s'num2 + t'.num1 -t'.floor(num1/num2).num2
	// gcd = t'.num1 + (s' - t'.floor(num1/num2)).num2
	extended_euclid(num2, rem, gcd, coef1_, coef2_);
	coef1 = coef2_;
	coef2 = (coef1_ - coef2_ * (num1 / num2));
}

int main(int argc, char *argv[])
{
	int num1, num2, gcd, coef1, coef2;
	stringstream strstream;
	if (argc != 3) {
		cerr << "Usage " << argv[0] << " <num1> <num2>" << endl;
		return 1;
	}
	strstream << argv[1] << " " << argv[2];
	strstream >> num1;
	strstream >> num2;
	extended_euclid(num1, num2, gcd, coef1,
			coef2);
	cout << "GCD = " << gcd << endl;
	cout << "coef1 = " << coef1 << endl;
	cout << "coef2 = " << coef2 << endl;
	return 0;
}
