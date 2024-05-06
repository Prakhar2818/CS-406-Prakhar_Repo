#include <iostream>
#include <vector>

using namespace std;

void findWaitingTime(const vector<int>& processes, int n, const vector<int>& burst_time, vector<int>& wait_time) {
    wait_time[0] = 0;

    for (int i = 1; i < n; i++) {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
}

void findTurnAroundTime(const vector<int>& processes, int n, const vector<int>& burst_time, const vector<int>& wait_time, vector<int>& tat) {
    for (int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wait_time[i];
    }
}

void findavgTime(const vector<int>& processes, int n, const vector<int>& burst_time) {
    vector<int> wait_time(n), tat(n);
    float total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, burst_time, wait_time);
    findTurnAroundTime(processes, n, burst_time, wait_time, tat);

    cout << "Processes Burst time Waiting time Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_wt += wait_time[i];
        total_tat += tat[i];

        cout << processes[i] << "\t\t" << burst_time[i] << "\t\t" << wait_time[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average waiting time = " << total_wt / n << endl;
    cout << "Average turn around time = " << total_tat / n << endl;
}

int main() {
    vector<int> processes = {1, 2, 3, 4};
    int n = processes.size();
    vector<int> burst_time = {21, 3, 6, 2};

    findavgTime(processes, n, burst_time);
    return 0;
}
