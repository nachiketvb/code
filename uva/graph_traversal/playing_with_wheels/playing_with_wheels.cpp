#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<cmath>

using namespace std;

int num_steps(int init_state, int target_state, const vector<int> &forbidden_states)
{
        queue<int> state_queue;
        vector<int> visited(10000, 0);
        vector<int> distance(10000);
        state_queue.push(init_state);
        distance[init_state] = 0;
        visited[init_state] = 1;
        while(!state_queue.empty()) {
                int current_state = state_queue.front();
                state_queue.pop();
                int current_distance = distance[current_state];
                if (current_state == target_state) {
                        return current_distance;
                }
                int digit[4];
                for (int i = 0; i < 4; i++) {
                        digit[i] = current_state%10;
                        current_state /= 10;
                }
                for (int i = 0; i < 4; i++) {
                        int temp = digit[i];
                        if (digit[i] == 0) {
                                digit[i] = 9;
                        } else {
                                digit[i] = digit[i] - 1;
                        }
                        int new_state = digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0];
                        if (!visited[new_state] && !forbidden_states[new_state]) {
                                visited[new_state] = 1;
                                distance[new_state] = current_distance + 1;
                                state_queue.push(new_state);
                        }
                        digit[i] = (temp + 1) % 10;
                        new_state = digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0];
                        if (!visited[new_state] && !forbidden_states[new_state]) {
                                visited[new_state] = 1;
                                distance[new_state] = current_distance + 1;
                                state_queue.push(new_state);
                        }
                        digit[i] = temp;
                }
        }
        return -1;
}

int get_state()
{
        int number = 0;
        for (int i = 0; i < 4; i++) {
                int digit;
                cin >> digit;
                number = number * 10 + digit;
        }
        return number;
}

int main()
{
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
                int init_state;
                init_state = get_state();
                int target_state = get_state();
                int nforbidden;
                cin >> nforbidden;
                vector<int> forbidden(10000, 0);
                for (int i = 0; i < nforbidden; i++) {
                        forbidden[get_state()] = 1;
                }
                cout << num_steps(init_state, target_state, forbidden) << endl;
        }
        return 0;
}
