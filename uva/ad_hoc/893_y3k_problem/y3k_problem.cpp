#include <iostream>
using namespace std;

#define DAYS_PER_400_YEARS (365 * 400 + 100 - 4 + 1)
#define DAYS_PER_100_YEARS (365 * 100 + 25 - 1)
#define DAYS_PER_4_YEARS (365 * 4 + 1)


unsigned int get_num_days(unsigned int mm, unsigned int yyyy)
{
	unsigned int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (mm == 2) {
		if ((yyyy % 4) == 0) {
			if ((yyyy % 100) == 0) {
				if ((yyyy % 400) == 0) {
					return 29;
				} else {
					return 28;
				}
			} else {
				return 29;
			}
		} else {
			return 28;
		}
	} else {
		return days_of_month[mm - 1];
	}
}

void print_date(unsigned int dd, unsigned int mm, unsigned int yyyy)
{
	cout << dd << " " << mm << " " << yyyy << endl;
}

void find_date(unsigned int ndays, unsigned int dd, unsigned int mm,
		unsigned int yyyy)
{
	unsigned int curr_dd, curr_mm, curr_yyyy, curr_ndays;
	unsigned int temp;
	curr_dd = dd;
	curr_mm = mm;
	curr_yyyy = yyyy;
	curr_ndays = ndays;

	/* Move ahead by 400 year intervals if possible */
	curr_yyyy += ((curr_ndays / DAYS_PER_400_YEARS) * 400);
	curr_ndays = curr_ndays % DAYS_PER_400_YEARS;

	while (curr_ndays != 0) {
		unsigned int days_this_month = get_num_days(curr_mm,
						curr_yyyy);
		unsigned int days_left = days_this_month - curr_dd + 1;

		if (curr_ndays >= days_left) {
			curr_dd = 1;
			curr_mm = (curr_mm) % 12 + 1;
			curr_yyyy += (curr_mm == 1);
			curr_ndays -= days_left;
		} else {
			curr_dd += curr_ndays;
			curr_ndays = 0;
		}
	}
	print_date(curr_dd, curr_mm, curr_yyyy);
	return;
# if 0	
	/* Move ahead by 100 year intervals if possible */
	temp = curr_yyyy;
	curr_yyyy += (curr_ndays / DAYS_PER_100_YEARS);
	curr_ndays = curr_ndays % DAYS_PER_100_YEARS;
	if (curr_mm > 2) {
		if (((curr_yyyy / 400) * 400) > temp) {
		/* We need to adjust for a year which is a multiple of 400 */
			move_back_days(curr_dd, curr_mm, curr_yyyy, 1);
		}
	} else {
		if ((((curr_yyyy - 1) / 400) * 400) > temp) {
		/* We need to adjust for a year which is a multiple of 400 */
			move_back_days(curr_dd, curr_mm, curr_yyyy, 1);
		}
	}
	if (curr_ndays == 0) {
		print_date(curr_dd, curr_mm, curr_yyyy);
		return;
	}

	/* Move ahead by 4 year intervals if possible */
	curr_yyyy += (curr_ndays / DAYS_PER_4_YEARS);
	curr_ndays = curr_ndays % DAYS_PER_4_YEARS;
#endif
}

int main()
{
	unsigned int ndays, dd, mm, yyyy;
	while (1)
	{
		cin >> ndays >> dd >> mm >> yyyy;
		if ((ndays == 0) && (dd == 0) && (mm == 0) && (yyyy == 0))
			break;
		find_date(ndays, dd, mm, yyyy);
	}
	return 0;
}
