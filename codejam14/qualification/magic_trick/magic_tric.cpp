#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int T;
	int grid1[4][4], grid2[4][4];
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans1, ans2;
		cin >> ans1;
		ans1--;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> grid1[j][k];
			}
		}
		cin >> ans2;
		ans2--;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> grid2[j][k];
			}
		}
		int num_pos = 0;
		int card = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (grid1[ans1][j] == grid2[ans2][k]) {
					num_pos++;
					card = grid1[ans1][j];
				}
			}
		}
		cout << "Case #" << i + 1 << ": ";
		if (num_pos == 1) {
			cout << card << endl;
		} else if (num_pos == 0) {
			cout << "Volunteer cheated!" << endl;
		} else {
			cout << "Bad magician!" << endl;
		}
	}
}
