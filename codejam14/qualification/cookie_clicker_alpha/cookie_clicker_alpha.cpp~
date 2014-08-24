#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		double C, F, X;
		cin >> C >> F >> X;
		double prev_secs, max_secs, curr_secs;
		prev_secs = max_secs = X / 2.0;
		int n = 1;
		double curr_rate = 2.0, curr_farm_time = 0.0;;
		while (1) {
			curr_secs = curr_farm_time + C / curr_rate + X / (curr_rate + F);
			if (curr_secs >= prev_secs) {
				printf("Case #%d: %.7f\n", i + 1, prev_secs);
				break;
			}
			curr_farm_time += C/curr_rate;
			curr_rate += F;
			prev_secs = curr_secs;
		}
	}
	return 0;
}
