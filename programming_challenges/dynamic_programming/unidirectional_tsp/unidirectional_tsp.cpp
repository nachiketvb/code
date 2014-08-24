#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_min_path(vector<vector<int> > &parents, int m, int n)
{
	if (parents[m][n] == -1) {
		cout << m + 1<< " ";
	} else {
		print_min_path(parents, parents[m][n], n - 1);
		cout << m + 1 << " ";
	}
}

void min_cost_travel(vector<vector<int> > &matrix, int m, int n)
{
	vector<vector<int> > cost(m, vector<int>(n));
	vector<vector<int> > parent(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		cost[i][0] = matrix[i][0];
		parent[i][0] = -1;
	}
	for (int j = 1; j < n; j++) {
		int i = 0;
		int min, current_cost, current_parent;
		min = cost[i][j - 1];
		current_parent = i;
		if (min > cost[i + 1][j - 1]) {
			min = cost[i + 1][j - 1];
			current_parent = i + 1;
		}
		if (min > cost[m - 1][j - 1]) {
			min = cost[m - 1][j - 1];
			current_parent = m - 1;
		}
		cost[i][j] = min + matrix[i][j];
		parent[i][j] = current_parent;
		for (i = 1; i < m - 1; i++) {
			min = cost[i - 1][j - 1];
			current_parent = i - 1;
			if (min > cost[i][j - 1]) {
				min = cost[i][j - 1];
				current_parent = i;
			}
			if (min > cost[i + 1][j - 1]) {
				min = cost[i + 1][j - 1];
				current_parent = i + 1;
			}
			cost[i][j] = min + matrix[i][j];
			parent[i][j] = current_parent;
		}
		min = cost[0][j - 1];
		current_parent = 0;
		if (min > cost[i - 1][j - 1]) {
			min = cost[i - 1][j - 1];
			current_parent = i - 1;
		}
		if (min > cost[i][j - 1]) {
			min = cost[i][j - 1];
			current_parent = i;
		}
		cost[i][j] = min + matrix[i][j];
		parent[i][j] = current_parent;
	}
	int min_cost = cost[0][n - 1];
	int min_index = 0;
	for (int i = 1; i < m; i++) {
		if (min_cost > cost[i][n - 1]) {
			min_cost = cost[i][n - 1];
			min_index = i;
		}
	}
#if 0
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
#endif
	print_min_path(parent, min_index, n - 1);
	cout << endl << min_cost << endl;
}
int main()
{
	while (1) {
		int m, n;
		cin >> m >> n;
		if (cin.eof()) {
			break;
		}
		vector<vector<int> > matrix(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		min_cost_travel(matrix, m, n);
	}
	return 0;
}
