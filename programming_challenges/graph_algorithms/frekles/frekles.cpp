#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip>

using namespace std;

template<class T>
class min_heap {
public:
	void insert(T item);
	T max();
	void delete_max();
	int get_parent(int index)
	{
		return (index - 1) / 2;
	}
	int get_left_child(int index)
	{
		return (2 * index + 1);
	}
	void adjust(int index);
	void heapify();
	vector<T> data;
	vector<T> location;
};

template<class T>
void min_heap<T>::insert(T item)
{
	data.push_back(item);
	int n = data.size();
	int current = n - 1;
	while (current != 0) {
		int parent = get_parent(current);
		if (data[parent] > item) {
			data[current] = data[parent];
			current = parent;
		} else {
			break;
		}
	}
	data[current] = item;
}

template<class T>
T min_heap<T>:: max()
{
	return data[0];
}

template<class T>
void min_heap<T>:: adjust(int index)
{
	T item = data[index];
	int current = index;
	int child = get_left_child(index);
	int n = data.size();
	while (child < n) {
		if (((child + 1) < n) && (data[child] > data[child + 1])) {
			child = child + 1;
		}
		if (item > data[child]) {
			data[current] = data[child];
			current = child;
			child = get_left_child(current);
		} else {
			break;
		}
	}
	data[current] = item;
}

template<class T>
void min_heap<T>::delete_max()
{
	int n = data.size();
	data[0] = data[n - 1];
	data.pop_back();
	adjust(0);
}


template<class T>
void min_heap<T>::heapify()
{
	int n = data.size();
	int parent = get_parent(n - 1);
	for (int i = parent; i >= 0; i--) {
		adjust(i);
	}
}

class union_find {
public:
	union_find(int n) : data(n, -1)
	{
	}
	void do_union(int index1, int index2);
	int find(int index);
private:
	vector<int> data;
};

int union_find::find(int index)
{
	int parent = index;
	while (data[parent] >= 0) {
		parent = data[parent];
	}
	while (data[index] >= 0) {
		int temp = data[index];
		data[index] = parent;
		index = temp;
	}
	return parent;
}

void union_find::do_union(int index1, int index2)
{
	if (data[index1] > data[index2]) {
		data[index2] += data[index1];
		data[index1] = index2;
	} else {
		data[index1] += data[index2];
		data[index2] = index1;
	}
}

struct edge_data {
	int vertex1, vertex2;
	double weight;
	bool operator > (const edge_data &edge2) {
		return weight > edge2.weight;
	}
};

struct vertex_data {
	double x, y;
	vector<edge_data> edges;
};

void kruskral(min_heap<edge_data> &edge_heap, int n)
{
	int num_edges = 0;
	union_find vertex_sets(n);
	double spanning_tree_weight = 0;
	while (num_edges != n - 1) {
		edge_data current_edge = edge_heap.max();
		edge_heap.delete_max();
		int set1 = vertex_sets.find(current_edge.vertex1);
		int set2 = vertex_sets.find(current_edge.vertex2);
		if (set1 != set2) {
			spanning_tree_weight += current_edge.weight;
			vertex_sets.do_union(set1, set2);
			++num_edges;
		}
	}

	cout << fixed << setprecision(2) << spanning_tree_weight << endl;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		vector<vertex_data> adj_list(n);
		for (int j = 0; j < n; j++) {
			cin >> adj_list[j].x >> adj_list[j].y;
		}
		min_heap<edge_data> edge_heap;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
			       double edge_weight = sqrt((adj_list[k].x - adj_list[j].x) * (adj_list[k].x - adj_list[j].x) + (adj_list[k].y - adj_list[j].y) * (adj_list[k].y - adj_list[j].y));
			       struct edge_data edge = {j, k, edge_weight};
			       edge_heap.insert(edge);
			}
		}
		kruskral(edge_heap, n);
		if (i < N - 1) 
			cout << endl;
	}
	return 0;
}
