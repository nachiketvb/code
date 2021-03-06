#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void solve_case(void)
{
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; i++) {
		cin >> b[i];
		cin >> a[i];
	}
	vector< pair<int, int> > a_sorted(N), b_sorted(N);
	for (int i = 0; i < N; i++) {
		a_sorted[i].first = a[i];
		a_sorted[i].second = i;
		b_sorted[i].first = b[i];
		b_sorted[i].second = i;
	}

	sort(a_sorted.begin(), a_sorted.end());
	sort(b_sorted.begin(), b_sorted.end());

	map<int, int> a_sorted_orig, b_orig_sorted;

	for (int i = 0; i < N; i++) {
		a_sorted_orig[i] = a_sorted[i].second;
		b_orig_sorted[b_sorted[i].second] = i;
	}

	int a_index = 0, b_index = 0, current_level = 0, num_steps = 0;
	while (a_index < N) {
		if (a_sorted[a_index].first <= current_level) {
			if (b_orig_sorted[a_sorted_orig[a_index]] < b_index) { 
				current_level++;
			} else {
				current_level += 2;
			}
			a_index++;
			num_steps++;
		} else if (b_sorted[b_index].first <= current_level) {
			b_index++;
			num_steps++;
			current_level++;
		} else {
			cout << "Too Bad";
			return;
		}
	}
	cout << num_steps;
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
