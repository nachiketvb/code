#include <iostream>
#include <vector>

using namespace std;



void print_max_profit(vector<long long> &profits, int k)
{
	int n = profits.size();
	vector<long long> cost(n, 0);
	cost[0] = profits[0];
	for (int i = 1; i < k; i++) {
		cost[i] = cost[i - 1] + profits[i];
	}
	long long ksum = cost[k - 1];
	int i = k;
	if (i < n) { 
		long long max = 0, second_max = 0;
		int max_index, second_max_index;
		ksum += profits[i];
		long long temp_sum = ksum;
		for (int j = i - k; j <= i; j++) {
			temp_sum -= profits[j];
			long long current_cost = temp_sum + ((j > 0) ? cost[j - 1] : 0);
			if (max < current_cost) { 
				max = current_cost;
				max_index = j;
			} else if (second_max < current_cost) {
				second_max = current_cost;
				second_max_index = j;
			}
		}
		cost[i] = max;
		ksum -= profits[i - k];
		for (; i < n; i++) {
			ksum += profits[i];
			long long temp_sum = ksum;
			for (int j = i - k; j <= i; j++) {
				temp_sum -= profits[j];
				long long current_cost = temp_sum + ((j > 0) ? cost[j - 1] : 0);
				if (max < current_cost) { 
					max = current_cost;
					max_index = j;
				} else if (second_max < current_cost) {
					second_max = current_cost;
					second_max_index = j;
				}
			}
			cost[i] = max;
			ksum -= profits[i - k];
		}
	}
	cout << cost[n - 1] << endl;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<long long> profits;
	for (int i = 0; i < N; i++) {
		long long profit;
		cin >> profit;
		profits.push_back(profit);
	}
	print_max_profit(profits, K);
}

