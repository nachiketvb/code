#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

void solve_case(int N)
{
	int W, H;
	vector<string> words;
	string S;
	cin >> W >> H;
	getline(cin, S);
	stringstream ss(S);
	while (!ss.eof()) {
		string temp;
		ss >> temp;
		words.push_back(temp);
	}
	int num_words = words.size();
	int max_size = (W > H) ? H : W;
	for (int i = max_size; i >= 1; i--) {
		int words_written = 0;
		int current_width = 0;
		int current_height = i;
		while (words_written != num_words) {
			if (current_height > H)
				break;
			int required_width = words[words_written].length() * i;
			if (W < (current_width + required_width)) {
				current_width = 0;
				current_height += i;
			} else {
				current_width += required_width + i;
				words_written++;
			}
		}
		if (words_written == num_words) {
			cout << "Case #" << N << ": " << i << endl;
			break;	
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		solve_case(i + 1);
	}
	return 0;
}
