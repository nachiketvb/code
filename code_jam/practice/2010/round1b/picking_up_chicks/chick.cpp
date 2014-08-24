#include <iostream>

using namespace std;

int main()
{
	unsigned int C, N, K, B, T;
	unsigned int *V, *X;	
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> K >> B >> T;
		V = new unsigned int[N];
		X = new unsigned int[N];
		for (int j = 0; j < N; j++) {
			cin >> X[j];
		}
		for (int j = 0; j < N; j++) {
			cin >> V[j];
		}
		int l = (N - K - 1), swaps = 0;
		for (int j = N - K; j < N; j++) {
			if (((B - X[j]) % T) == 0) {
				if (((B - X[j]) / T) <= V[j]) {
					continue;
				}
			} else {
				if (((B - X[j]) / T) < V[j]) {
					continue;
				}
			}

			while (l >= 0) {
				if (((B - X[l]) % T) == 0) {
					if (((B - X[l]) / T) > V[l]) {
						l--;
						continue;
					}
				} else {
					if (((B - X[l]) / T) >= V[l]) {
						l--;
						continue;
					}
				}
				swaps += (j - l);
				break;
			}
			if (l < 0) {
				cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
				goto next;
			}
			l--;

		}
		cout << "Case #" << i + 1 << ": " << swaps << endl;

next:
		delete[] V;
		delete[] X;
	}

	return 0;
}
