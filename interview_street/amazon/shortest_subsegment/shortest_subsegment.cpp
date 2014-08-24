/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <strings.h>
using namespace std;

class word_comparator {
	public:
		bool operator()(string word1, string word2)
		{
			return (strcasecmp(word1.c_str(), word2.c_str()) < 0);
		}
};

int main()
{
	string paragraph;
	getline(cin, paragraph);
	int n;
	cin >> n;
	map<string, int, word_comparator> words;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		words[word] = 0;
	}
	int paragraph_length = paragraph.size();
	int i = 0;
	int current_max = -1, current_min = -1;
	vector<string> word_list;
	while (1) {
		string current_word;

		while ((i < paragraph_length) && (!isalpha(paragraph[i]))) {
			i++;
		}
		if (i >= paragraph_length) {
			break;
		}
		while ((i < paragraph_length) && (isalpha(paragraph[i]))) {
			current_word.push_back(paragraph[i]);
			i++;
		}
		word_list.push_back(current_word);
		if (i >= paragraph_length) {
			break;
		}
	}
	int list_size = word_list.size();
	for (int i = 0; i < list_size; i++) {
		map<string, int, word_comparator>::iterator itr1;
		if ((itr1 = words.find(word_list[i])) != words.end()) {
			if (itr1->second == 0) {
				(itr1->second)++;
				if (current_min == -1) {
					current_min = i;
				}
				current_max = i;
			} else {
				(itr1->second)++;
				int temp = current_min;
				map<string, int, word_comparator> temp_words = words;
				while(1) {
					map<string, int, word_comparator>::iterator itr2;
					if ((itr2 = temp_words.find(word_list[temp])) != temp_words.end()) {
						if (itr2->second > 1)
							(itr2->second)--;
						else
							break;
					}
					temp++;

				}
				if ((i - temp + 1) < (current_max - current_min + 1)) {
					current_max = i;
					current_min = temp;
					words = temp_words;
				}
			}
		}
	}
	bool found = true;
	for (map<string, int, word_comparator>::iterator i = words.begin(); i != words.end(); ++i) {
		if (i->second == 0) {
			found = false;
			break;
		}
	}
	if (found) {
		for (int i = current_min; i <= current_max; i++) {
			cout << word_list[i] << " ";
		}
		cout << endl;
	} else {
		cout << "NO SUBSEGMENT FOUND" << endl;
	}
	return 0;
}
