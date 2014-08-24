#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <stack>

using namespace std;

string debug;
stack<int> debug_indices;
int debug_index;


void unmerge(vector<int> &indices, int start, int mid, int end)
{
	int i, j;
	int k = start;
	int n1 = mid - start;
	int n2 = end - mid + 1;
	i = 0;
	j = 0;
	int debug_index = debug_indices.top();
	debug_indices.pop();
	vector<int> first_half(mid - start), second_half(end - mid + 1);
	while ((i < n1) && (j < n2)) {
		if (debug[debug_index++] =='1') {
			first_half[i++] = indices[k++];
		} else {
			second_half[j++] = indices[k++];
		}
	}
	while (i < n1) {
		first_half[i++] = indices[k++];
	}
	while (j < n2) {
		second_half[j++] = indices[k++];
	}
	for (int l = 0; l < n1; l++) {
		indices[start + l] = first_half[l];
	}
	for (int l = 0; l < n2; l++) {
		indices[start + n1 + l] = second_half[l];
	}
}

void unsort(vector<int> &indices, int start, int end)
{
	int n = end - start + 1;
	if (n <= 1)
		return;
	int mid = n/2 + start;
	unmerge(indices, start, mid, end);
	unsort(indices, mid, end);
	unsort(indices, start, mid - 1);
}

void increment_debug_index(int start, int mid, int end)
{
	int i, j;
	i = 0;
	j = 0;
	int n1 = mid - start;
	int n2 = end - mid + 1;
	while ((i < n1) && (j < n2)) {
		if (debug[debug_index++] =='1') {
			i++;
		} else {
			j++;
		}
	}
}

void init_debug_indices(int start, int end)
{
	int n = end - start + 1;
	if (n <= 1)
		return;
	int mid = n/2 + start;
	init_debug_indices(start, mid - 1);
	init_debug_indices(mid, end);
	debug_indices.push(debug_index);
	increment_debug_index(start, mid, end);
}

void solve_case(void)
{
	int N;
	cin >> N;
	cin >> debug;
	vector<int> indices(N);
	for (int i = 0; i < N; i++) {
		indices[i] = i + 1;
	}
	debug_index = 0;
	init_debug_indices(0, N-1);
	unsort(indices, 0, N - 1);
	int result = 1;
	for (int i = 0; i < N; i++) {
		result = (result * 31 + indices[i]) % 1000003;
	}
	cout << result;
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
