#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>

using namespace std;

void solve_case(void)
{
	string input_line;
	getline(cin, input_line);
	int length = input_line.length();
	int occurances[8] = {0};
	for (int i = 0; i < length; i++) {
		switch (input_line[i]) {
			case 'H':
				occurances[0]++;
				break;
			case 'A':
				occurances[1]++;
				break;
			case 'C':
				occurances[2]++;
				break;
			case 'K':
				occurances[3]++;
				break;
			case 'E':
				occurances[4]++;
				break;
			case 'R':
				occurances[5]++;
				break;
			case 'U':
				occurances[6]++;
				break;
			case 'P':
				occurances[7]++;
				break;
			default :
				break;
		}
	}
	occurances[2] /= 2;
	int min = INT_MAX;
	for (int i = 0; i < 8; i++) {
		if (min > occurances[i]) {
			min = occurances[i];
		}
	}
	cout << min;
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
