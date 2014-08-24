#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class card {
public:
	char rank, suit;
	int _rank;
	void update_rank() {
		char order[]="23456789TJQKA";
		for (int i = 0; i < 13; i++) {
			if (order[i] == rank) {
				_rank = i;
			}
		}
	}
	bool operator < (const card &second) const
	{
		return (_rank < second._rank);
	}
	bool operator > (const card &second) const
	{
		return (_rank > second._rank);
	}
	bool operator == (const card &second) const
	{
		return (_rank == second._rank);
	}
	friend istream& operator >> (istream&, card&);
};

istream& operator >> (istream &card_in, card &input_card) {
	card_in >> input_card.rank;
	card_in >> input_card.suit;
	input_card.update_rank();
	return card_in;
}

int compare_hands(card hand1[], card hand2[], int num_cards)
{
	for (int i = 0; i < num_cards; i++) {
		// cout << hand1[i].rank << hand1[i].suit << " " << hand1[i]._rank << " ";
		// cout << hand2[i].rank << hand2[i].suit << " " << hand2[i]._rank << endl;
		if (hand1[i] > hand2[i]) {
			return 0;
		} else if (hand2[i] > hand1[i]) {
			return 1;
		}
	}
	return 2;
}

bool straight(card hand[5])
{
	for (int i = 0; i < 4; i++) {
		if ((hand[i]._rank - hand[i+1]._rank) != 1) {
			return false;
		}
	}
	return true;
}

bool flush(card hand[5])
{
	char suit = hand[0].suit;
	for (int i = 1; i < 5; i++) {
		if (hand[i].suit != suit) {
			return false;
		}
	}
	return true;
}

bool four_kind(card hand[5], card tmp[5])
{
	int num_kind = 0;
	for (int i = 1; i < 5; i++) {
		if (hand[i].rank == hand[0].rank) {
			num_kind++;
		}
	}
	if (num_kind == 3) {
		tmp[0] = hand[0];
		return true;
	}
	num_kind = 0;
	for (int i = 2; i < 5; i++) {
		if (hand[i].rank == hand[1].rank) {
			num_kind++;
		}
	}
	if (num_kind == 3) {
		tmp[0] = hand[1];
		return true;
	}
	return false;
}

bool three_of_kind(card hand[5], card tmp[5])
{
	vector<int> ranks(13, 0);
	for (int i = 0; i < 5; i++) {
		ranks[hand[i]._rank]++;
		if (ranks[hand[i]._rank] == 3) {
			tmp[0]._rank = hand[i]._rank;
			return true;
		}
	}

	return false;
}

bool full_house(card hand[5], card tmp[5])
{
	vector<int> ranks(13, 0);
	for (int i = 0; i < 5; i++) {
		ranks[hand[i]._rank]++;
	}
	for (int i = 0; i < 13; i++) {
		if (ranks[i] == 3) {
			for (int j = 0; j < 13; j++) {
				if (ranks[j] == 2) {
					tmp[0]._rank = i;
					return true;
				}
			}
		}
	}
	return false;
}

bool straight_flush(card hand[5])
{
	return straight(hand) && flush(hand);
}

bool Pair(card hand[5], card tmp[5]) {
	vector<int> ranks(13, 0);

	for (int i = 0; i < 5; i++) {
		ranks[hand[i]._rank]++;
	}

	for (int i = 0; i < 13; i++) {
		if (ranks[i] == 2) {
			tmp[0]._rank = i;
			tmp[1]._rank = i;
			int k = 2;
			for (int j = 12; j >= 0; j--) {
				if (ranks[j] == 1) {
					tmp[k++]._rank = j;
				}
			}
			return true;
		}
	}

	return false;
}

bool two_pair(card hand[5], card tmp[5]) {
	vector<int> ranks(13, 0);

	for (int i = 0; i < 5; i++) {
		ranks[hand[i]._rank]++;
	}

	for (int i = 12; i >= 0; i--) {
		if (ranks[i] == 2) {
			tmp[0]._rank = i;
			tmp[1]._rank = i;
			for (int j = i - 1; j >= 0; j--) {
				if (ranks[j] == 2) {
					tmp[2]._rank = j;
					tmp[3]._rank = j;
					for (int k = 0; k < 13; k++) {
						if (ranks[k] == 1) {
							tmp[4]._rank = k;
							return true;
						}
					}
				}
			}
			return false;
		}
	}

	return false;
}

int play(card hand1[5], card hand2[5])
{
	card tmp_hand1[5], tmp_hand2[5];
	sort(&hand1[0], &hand1[5]);
	reverse(&hand1[0], &hand1[5]);
	for (int i = 0; i < 5; i++) {
		//cout << hand1[i].rank << hand1[i].suit << " ";
	}
	//cout << endl;
	sort(&hand2[0], &hand2[5]);
	reverse(&hand2[0], &hand2[5]);
	for (int i = 0; i < 5; i++) {
		//cout << hand2[i].rank << hand2[i].suit << " ";
	}
	//cout << endl;
	if (straight_flush(hand1)) {
		//cout << "straight flush black" << endl;
		if (straight_flush(hand2)) {
			return compare_hands(hand1, hand2, 5);
		} else {
			return 0;
		}
	}
	if (straight_flush(hand2)) {
		//cout << "straight flush white" << endl;
		return 1;
	}
	
	if (four_kind(hand1, tmp_hand1)) {
		//cout << "four kind black" << endl;
		if (four_kind(hand2, tmp_hand2)) {
			return compare_hands(tmp_hand1, tmp_hand2, 1);
		} else {
			return 0;
		}
	}
	if (four_kind(hand2, tmp_hand2)) {
		//cout << "four kind white" << endl;
		return 1;
	}

	if (full_house(hand1, tmp_hand1)) {
			//cout << "full house black" << endl;
			if (full_house(hand2, tmp_hand2)) {
				return compare_hands(tmp_hand1, tmp_hand2, 1);
			} else {
				return 0;
			}
	}
	if (full_house(hand2, tmp_hand2)) {
			//cout << "full house white" << endl;
			return 1;
	}

	if (flush(hand1)) {
			//cout << "flush black" << endl;
			if (flush(hand2)) {
				return compare_hands(hand1, hand2, 5);
			} else {
				return 0;
			}
	}
	if (flush(hand2)) {
			//cout << "flush white" << endl;
			return 1;
	}

	if (straight(hand1)) {
			//cout << "straight black" << endl;
			if (straight(hand2)) {
				return compare_hands(hand1, hand2, 5);
			} else {
				return 0;
			}
	}
	if (straight(hand2)) {
			//cout << "straight white" << endl;
			return 1;
	}

	if (three_of_kind(hand1, tmp_hand1)) {
			//cout << "three of kind black" << endl;
			if (three_of_kind(hand2, tmp_hand2)) {
				return compare_hands(tmp_hand1, tmp_hand2, 1);
			} else {
				return 0;
			}
	}
	if (three_of_kind(hand2, tmp_hand2)) {
			//cout << "three of kind white" << endl;
			return 1;
	}

	if (two_pair(hand1, tmp_hand1)) {
			//cout << "two pair black" << endl;
			if (two_pair(hand2, tmp_hand2)) {
				return compare_hands(tmp_hand1, tmp_hand2, 5);
			} else {
				return 0;
			}
	}
	if (two_pair(hand2, tmp_hand2)) {
			//cout << "two pair white" << endl;
			return 1;
	}

	if (Pair(hand1, tmp_hand1)) {
			//cout << "pair black" << endl;
			if (Pair(hand2, tmp_hand2)) {
				return compare_hands(tmp_hand1, tmp_hand2, 5);
			} else {
				return 0;
			}
	}
	if (Pair(hand2, tmp_hand2)) {
			//cout << "pair white" << endl;
			return 1;
	}
	//cout << "high card" << endl;
	return compare_hands(hand1, hand2, 5);
}

int main()
{
	while (1) {
		string line;
		getline(cin, line);
		if (cin.eof()) {
			break;
		}
		if (line.empty()) {
			continue;
		}
		card hand1[5], hand2[5];
		stringstream ss(line);
		for (int i = 0; i < 5; i++) {
			ss >> hand1[i];
		}
		for (int i = 0; i < 5; i++) {
			ss >> hand2[i];
		}
		int winner = play(hand1, hand2);
		if (winner == 0) {
			cout << "Black wins." << endl;
		} else if (winner == 1) {
			cout << "White wins." << endl;
		} else {
			cout << "Tie." << endl;
		}
	}
	return 0;
}

