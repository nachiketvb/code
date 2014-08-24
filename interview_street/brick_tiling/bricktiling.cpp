#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get_block_count

void solve_case()
{
	int N, M;
	cin >> N >> M;
	vector<string> gird(N);
	vector< vector <long> > covered(N, vector<long>(M, 0));
	long current_total = 1;
	for (int i = 0; i < N; i++) {
		cin >> grid[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == '.') {
				grid[i][j] = '#';
				current_total *= block_count;
			}
		}
	}
	cout << current_total << endl;
}
int main()
{
	int T;
	for (int i = 0; i < T; i++) {
		solve_case();
	}
	return 0;
}
