#include <iostream>
#include <string>

using namespace std;

int get_value(string card)
{
	if ((card[0] >= '2') && (card[0] <= '9')) {
		return card[0] - '0';
	} else {
		return 10;
	}
}

void solve(string cards[])
{
	int top = 51 - 25;
	int Y = 0;
	int X;
	X = get_value(cards[top]);
	Y += X;
	top -= (10 - X + 1);
	X = get_value(cards[top]);
	Y += X;
	top -= (10 - X + 1);
	X = get_value(cards[top]);
	Y += X;
	top -= (10 - X + 1);
	Y--;
	if (Y <= top) {
		cout << cards[Y];
	} else {
		cout << cards[51 - 25 + Y - top];
	}
	cout << endl;
}

int main()
{
	int n;
	string cards[52];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 52; ++j) {
			cin >> cards[j];
		}
		cout << "Case " << i + 1 << ": ";
		solve(cards);
	}
	return 0;
}
