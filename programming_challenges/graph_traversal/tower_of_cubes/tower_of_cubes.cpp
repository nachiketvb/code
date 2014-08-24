#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline int get_opposite_face(int index)
{
	if (index % 2 == 0) {
		return index + 1;
	} else {
		return index - 1;
	}
}

void print_tower(vector<vector<int> > cube_data, vector<vector<int> > &selected, int cube_index, int color_index)
{
	string face[6] = {"front", "back", "left", "right", "top", "bottom"};
	int N = cube_data.size();
	if (cube_index == N) {
		return;
	}
	int i = selected[cube_index][color_index];
	if (i != -1) {
		int bottom_color;
		cout << cube_index + 1 << " " << face[i] << endl;
		bottom_color = cube_data[cube_index][get_opposite_face(i)];
		print_tower(cube_data, selected, cube_index + 1, bottom_color);
	} else {
		print_tower(cube_data, selected, cube_index + 1, color_index);
	}
}

void tallest_tower(vector<vector<int> > &cube_data)
{
	int N = cube_data.size();
	vector<vector<int> > cost(N, vector<int>(100, 0));
	vector<vector<int> > selected(N, vector<int>(100, -1));
	
	for (int i = 0; i < 6; i++) {
		cost[N - 1][cube_data[N-1][i]] = 1;
		selected[N - 1][cube_data[N-1][i]] = i;
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < 100; j++) {
			cost[i][j] = cost[i + 1][j];
		}
		for (int j = 0; j < 6; j++) {
			int current_color = cube_data[i][j];
			int opposite_color = cube_data[i][get_opposite_face(j)];
			if (cost[i][current_color] < (cost[i + 1][opposite_color] + 1)) {
				cost[i][current_color] = cost[i + 1][opposite_color] + 1;
				selected[i][current_color] = j;
			}
		}
	}
	int max_cost = cost[0][0];
	int max_index = 0;
	for (int i = 1; i < 100; i++) {
		if (max_cost < cost[0][i]) {
			max_cost = cost[0][i];
			max_index = i;
		}
	}
	cout << max_cost << endl;
	print_tower(cube_data, selected, 0, max_index);
}

int main()
{
	int case_no = 1;
	while (1) {
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		vector<vector<int> > cube_data(N, vector<int>(6));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> cube_data[i][j];
				cube_data[i][j]--;
			}
		}
		cout << "Case #" << case_no++ << endl;
		tallest_tower(cube_data);
		cout << endl;
	}
	return 0;
}
