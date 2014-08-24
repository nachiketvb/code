#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <list>

using namespace std;

void create_mapping(const string &encrypted, const string &dictionary, map<char,char> &mapping)
{
    if (encrypted.size() != dictionary.size()) {
        return;
    }
    int n = encrypted.size();
    //cout << "Trying to map " << encrypted << " to " << dictionary << endl;
    map<char, char> reverse_mapping;
    for (int i = 0; i < n; i++) {
        if ((mapping.find(encrypted[i]) != mapping.end())) {
	    //cout << "Previous mapping found" << endl;
            if (mapping[encrypted[i]] != dictionary[i]) {
		//cout << "Mapping aborted" << endl;
                mapping.erase(mapping.begin(), mapping.end());
                return;
            } else {
                continue;
            }
        }
	if ((reverse_mapping.find(dictionary[i]) != reverse_mapping.end())) {
	    //cout << "Previous reverse mapping found" << endl;
            if (reverse_mapping[encrypted[i]] != dictionary[i]) {
		//cout << "Mapping aborted" << endl;
                mapping.erase(mapping.begin(), mapping.end());
                return;
            } else {
                continue;
            }
        }
        mapping[encrypted[i]] = dictionary[i];
	reverse_mapping[dictionary[i]] = mapping[encrypted[i]];
	//cout << "mapping " << encrypted[i] << " to " << dictionary[i] << endl;
    }
    //cout << "Mapping successful" << endl;
}

void merge_mappings(const map<char, char> &mapping1, const map<char, char> &mapping2, map<char, char> &new_mapping)
{
    new_mapping = mapping1;
    for (map<char, char>::const_iterator itr = mapping2.begin(); itr != mapping2.end(); ++itr) {
        if (new_mapping.find(itr->first) != new_mapping.end()) {
            if (new_mapping[itr->first] != itr->second) {
                new_mapping.erase(new_mapping.begin(), new_mapping.end());
                return;
            } else {
                continue;
            }
        }
        new_mapping[itr->first] = itr->second;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<string> dictionary(N);
    for (int i = 0; i < N; i++) {
        cin >> dictionary[i];
    }
    while (1) {
        string line;
        getline(cin, line);
        if (cin.eof())
            break;
        if (line.empty())
            continue;
        stringstream sin(line);
        bool first = true;
	list<map<char, char> > current_mapping;
        while (1) {
            string current_word;
            if (sin.eof())
                break;
            sin >> current_word;
	    //cout << "current_word = " << current_word << endl;
            if (first == true) {
                first = false;
                for (int i = 0; i < N; i++) {
                    map<char, char> tmp_map;
                    create_mapping(current_word, dictionary[i], tmp_map);
                    if (tmp_map.empty()) {
                        continue;
                    }
                    current_mapping.push_back(tmp_map);
                }
            } else {
                list<map<char, char> > new_mapping;
                for (int i = 0; i < N; i++) {
                    map<char, char> tmp_map;
                    create_mapping(current_word, dictionary[i], tmp_map);
                    if (tmp_map.empty()) {
                        continue;
                    }
                    for (list<map<char, char> >::iterator itr = current_mapping.begin(); itr != current_mapping.end(); ++itr) {
                        map<char, char> new_map;
                        merge_mappings(*itr, tmp_map, new_map);
                        if (new_map.empty()) {
                            continue;
                        }
                        new_mapping.push_back(new_map);
                    }
                }
                current_mapping = new_mapping;
            }
            if (current_mapping.empty()) {
                break;
            }
        }
        if (current_mapping.empty()) {
            int N = line.size();
            for (int i = 0; i < N; i++) {
                if (line[i] != ' ') {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        } else {
            list<map<char, char> >::iterator itr = current_mapping.begin();
            int N = line.size();
	    //cout << line << endl;
            for (int i = 0; i < N; i++) {
                if (line[i] != ' ') {
                    cout << (*itr)[line[i]];
                } else {
                    cout << " ";
                }
	    }
	    cout << endl;
        }
    }
    return 0;
}
