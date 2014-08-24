#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int match(vector<string> outlet, vector<string> device, vector<int> flips, int N, int L, int index)
{
	int n_outlet_1s = 0, n_device_1s = 0;
	vector<string> outlet_1s, outlet_0s, device_1s, device_0s;
	if ((index == L) || (N == 0))
		return 0;
	for (int i = 0; i < N; ++i) {
		if (outlet[i][index] == '1') {
			n_outlet_1s++;
			outlet_1s.push_back(outlet[i]);
		} else {
			outlet_0s.push_back(outlet[i]);
		}
		if (device[i][index] == '1') {
			n_device_1s++;
			device_1s.push_back(device[i]);
		} else {
			device_0s.push_back(device[i]);
		}
	}
	cout << n_outlet_1s << " " << n_device_1s << endl;
	if (n_outlet_1s == n_device_1s) {
		if (flips[index] == 2) {
			return -1;
		}
		cout << "flips[" << index << "]" << flips[index] << endl;
		int match_0s, match_1s;
		match_0s = match(outlet_0s, device_0s, flips, N - n_outlet_1s, L, index + 1);
		if (match_0s == -1) {
			return -1;
		}
		match_1s = match(outlet_1s, device_1s, flips, n_outlet_1s, L, index + 1);
		if (match_1s == -1) {
			return -1;
		}
		if (n_outlet_1s != (N - n_device_1s)) {
			flips[index] = 1;
		}
		return max(match_0s, match_1s);
	} else if (n_outlet_1s == (N - n_device_1s)) {
		cout << "flips[" << index << "]" << flips[index] << endl;
		if (flips[index] == 1) {
			return -1;
		}
		int match_0s, match_1s;
		match_0s = match(outlet_0s, device_1s, flips, N - n_outlet_1s, L, index + 1);
		if (match_0s == -1) {
			return -1;
		}
		match_1s = match(outlet_1s, device_0s, flips, n_outlet_1s, L, index + 1);
		if (match_1s == -1) {
			return -1;
		}
		flips[index] = 2;
		return max(match_0s, match_1s);
	} else {
		return -1;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N, L;
		cin >> N >> L;
		vector<string> outlet(N), device(N);
		vector<int> flips(N, 0);
		for (int j = 0; j < N; ++j) {
			cin >> outlet[j];
		}
		for (int j = 0; j < N; ++j) {
			cin >> device[j];
		}
		cout << "Case #" << i + 1 << ": ";
		int result = match(outlet, device, flips, N, L, 0);
		if (result == -1) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << result << endl;
		}
	}
	return 0;
}
