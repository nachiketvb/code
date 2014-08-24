#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct route_data {
	string destination;
	int start_time;
	int end_time;
};

void add_cities(map<string, vector<route_data> > &adj_list, map<string, int> &visited, map<string, int> &cost, queue<string> &city_queue, string &source, int start_time, int new_cost)
{
	for (vector<route_data>::iterator itr = adj_list[source].begin(); itr != adj_list[source].end(); ++itr) {
		route_data &destination_data = *itr;
		if ((destination_data.start_time + 6) % 24 >= (start_time + 6) % 24) {
			if(!visited[destination_data.destination]) {
				visited[destination_data.destination] = 1;
				cost[destination_data.destination] = new_cost;
				city_queue.push(destination_data.destination);
				//cout << "Visited " << destination_data.destination << " at time " << destination_data.end_time << endl;
			}
			add_cities(adj_list, visited, cost, city_queue, destination_data.destination, destination_data.end_time, new_cost);
		}
	}
}

void find_min_blood(map<string, vector<route_data> > &adj_list, string &source, string &destination)
{
	map<string, int> visited, cost;
	queue<string> city_queue;
	for (map<string, vector<route_data> >::iterator itr = adj_list.begin(); itr != adj_list.end(); ++itr) {
		visited[itr->first] = 0;
		cost[itr->first] = -1;
	}
	visited[source] = 1;
	cost[source] = 0;
	city_queue.push(source);
	//cout << "Visited " << source << endl;
	add_cities(adj_list, visited, cost, city_queue, source, 18, cost[source]);
	while(!city_queue.empty()) {
		string current_source = city_queue.front();
		city_queue.pop();
		int new_cost = cost[current_source] + 1;
		add_cities(adj_list, visited, cost, city_queue, current_source, 18, new_cost);
	}
	if ((adj_list.find(destination) == adj_list.end()) || (cost[destination] == -1)) {
		cout << "There is no route Vladimir can take." << endl;
	} else {
		cout << "Vladimir needs " << cost[destination] << " litre(s) of blood." << endl;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		map<string, vector<route_data> > adj_list;
		int num_routes;
		cin >> num_routes;
		for (int j = 0; j < num_routes; j++) {
			string source, destination;
			int start_time, duration;
			cin >> source >> destination >> start_time >> duration;
			if (((start_time >= 18) || (start_time <= 6)) && ((((start_time + duration) % 24) <= 6) || ((start_time + duration) % 24) >= 18)) {
				//cout << "Added " << source << " " << destination << " " << start_time << " " << duration << endl;
				route_data current_route;
				current_route.destination = destination;
				current_route.start_time = start_time % 24;
			        current_route.end_time = (start_time + duration) % 24;
				adj_list[source].push_back(current_route);
			}
		}
		string source, destination;
		cin >> source >> destination;
		cout << "Test Case " << i + 1 << "." << endl;
		find_min_blood(adj_list, source, destination);
	}

	return 0;
}
