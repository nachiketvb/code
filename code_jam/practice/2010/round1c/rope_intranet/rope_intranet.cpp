#include<iostream>
#include<vector>

using namespace std;

void solve_case()
{
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	int intersections = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if(((A[i] > A[j]) && (B[i] < B[j])) || ((A[i] < A[j]) && (B[i] > B[j]))) {
				intersections++;
			}
		}
	}
	cout << intersections;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
