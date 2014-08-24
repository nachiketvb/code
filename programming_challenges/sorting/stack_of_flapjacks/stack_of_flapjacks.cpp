#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int partition(vector<int> &a, int low, int high)
{
	int pivot = a[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (a[j] < pivot) {
			i = i + 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1;
}

void quick_sort(vector<int> &a, int low, int high)
{
	if (low >= high) {
		return;
	}
	int pivot_index = partition(a, low, high);
	quick_sort(a, low, pivot_index - 1);
	quick_sort(a, pivot_index + 1, high);
}

void flipsort(vector<int> &stack)
{
	int n = stack.size();
	vector<int> sorted;
	sorted = stack;
	quick_sort(sorted, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
	for (int i = n - 1; i >= 0; i--) {
		if (sorted[i] == stack[i]) {
			continue;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (stack[j] == sorted[i]) {
				if (j != 0) {
					reverse(&stack[0], &stack[j + 1]);
					cout << n - j << " ";
				}
				reverse(&stack[0], &stack[i + 1]);
				cout << n - i << " ";
				break;
			}
		}
	}
	cout << 0;
}

int main()
{
	while (1) {
		string line;
		getline(cin, line);
		if (cin.eof()) {
			break;
		}
		if (line == "") {
			continue;
		}
		stringstream sin(line);
		vector<int> stack;
		int n = 0;
		while (!sin.eof()) {
			int d;
			sin >> d;
			stack.push_back(d);
		}
		flipsort(stack);
		cout << endl;
	}
}
