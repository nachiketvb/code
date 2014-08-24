#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void stack_turtles(vector<pair<int, int> > &turtles)
{
	int n = turtles.size();
	sort(turtles.begin(), turtles.end());
	vector<int> cost(n);
	vector<int> total_weight(n);
	if (turtles[0].first >= turtles[0].second)
	{
		cost[0] = 1;
		total_weight[0] = turtles[0].second;
	} else {
		cost[0] = 0;
		total_weight[0] = 0;
	}
	int max = 1;
	for (int i = 1; i < n; i++) {
		int current_cost, current_weight;
		if (turtles[i].first >= turtles[i].second)
		{
			current_cost = 1;
			current_weight = turtles[i].second;
		} else {
			current_cost = 0;
			current_weight = 0;
		}
		for (int j = 0; j < i; j++) {
			if ((total_weight[j] + turtles[i].second) <= turtles[i].first) {
				if (current_cost < (cost[j] + 1)) {
					current_cost = cost[j] + 1;
					current_weight = turtles[i].second + total_weight[j];
				}
			}
		}
		cost[i] = current_cost;
		total_weight[i] = current_weight;
		if (max < cost[i]) {
			max = cost[i];
		}
	}
	cout << max << endl;
}

int main()
{
	vector<pair<int, int> > turtles;
	while (1) {
		int weight, capacity;
		cin >> weight >> capacity;
		if (cin.eof()) {
			break;
		}
		turtles.push_back(pair<int, int>(capacity, weight));
	}
	stack_turtles(turtles);
	return 0;
}
