#include <iostream>
#include <map>
using namespace std;

map<int, int> cycle_length;

int find_cycle_length(int n)
{
	if (n == 1) {
		return 1;
	} else if (cycle_length.find(n) != cycle_length.end()) {
		return cycle_length[n];
	} else {
		if ((n % 2) == 0) {
			cycle_length[n] = find_cycle_length(n/2) + 1;
			return cycle_length[n];
		} else {
			cycle_length[n] = find_cycle_length(3 * n + 1) + 1;
			return cycle_length[n];
		}
	}
}

int find_max_cycle_length(int start, int end)
{
	int current_cycle_length, max_cycle_length = 1;
	for (int i = start; i <= end; i++) {
		current_cycle_length = find_cycle_length(i);
		if (current_cycle_length > max_cycle_length) {
			max_cycle_length = current_cycle_length;
		}
	}
	return max_cycle_length;
}

int main()
{
	int i, j;
	while (1) {
		cin >> i >> j;
		if (cin.eof()) {
			break;
		}
		cout << i << " " << j << " " << ((i <= j) ? find_max_cycle_length(i, j) : find_max_cycle_length(j, i)) << endl;
	}
	return 0;
}
