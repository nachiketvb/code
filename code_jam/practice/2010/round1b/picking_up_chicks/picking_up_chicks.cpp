#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

void solve_case()
{
	long N, K, B, T;
	cin >> N >> K >> B >> T;
	vector<long> x(N), v(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int num_crossings = 0;
	int num_swaps = 0;
	int num_slow = 0;
	for (int i = N - 1; i >= 0; i--) {
		if ((B - x[i]) <= v[i] * T) {
			num_crossings++;
			num_swaps += num_slow;
		} else {
			num_slow++;
		}
		if (num_crossings >= K) {
			break;
		}
	}
	if (num_crossings < K) {
		cout << "IMPOSSIBLE";
	} else {
		cout << num_swaps;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
