#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>

using namespace std;

void solve_case(void)
{
	double D, N, A;
	cin >> D >> N >> A;
	vector<double> x(N), t(N), a(A);
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> x[i];
	}
	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}
	cout.precision(6);
	cout << fixed;
	for (int i = 0; i < A; i++) {
		double total_time = 0.0;
		double distance_covered = 0.0;
		double current_velocity = 0.0;
		for (int j = 0; j < N; j++) {
			double s = x[j] - distance_covered;
			double time_needed = (sqrt(current_velocity * current_velocity + 2 * a[i] * s) - current_velocity) / a[i];
			double acceleration;
		       	if ((time_needed + total_time) < t[j]) {
				time_needed = t[j] - total_time;
				total_time = t[j];
				acceleration = 2 * (s - current_velocity * time_needed) / (time_needed * time_needed);
			} else {
				total_time = t[j] + total_time;
				acceleration = a[i];
			}
			distance_covered = x[j];
			current_velocity = acceleration * time_needed + current_velocity;
			//cout << "cv: " << acceleration << " " << time_needed << " " << current_velocity << endl;
		}
		double s = D - x[N - 1];
		//cout << endl << s << " " << a[i] << " " << current_velocity << endl;
		double time_needed = (sqrt(current_velocity * current_velocity + 2 * a[i] * s) - current_velocity) / a[i];
		//cout << endl << time_needed << endl;
		total_time += time_needed;
		cout << total_time << endl;
	}
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": " << endl;
		solve_case();
	}
	return 0;
}
