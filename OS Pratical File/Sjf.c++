#include <iostream>
#include <vector>

using namespace std;

void swap(int& xp, int& yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void sortProcessByBurst(int n, vector<int>& burst, vector<int>& process) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (burst[j] > burst[j+1]) {
                swap(burst[j], burst[j+1]);
                swap(process[j], process[j+1]);
            }
        }
    }
}

void calculateTimes(const vector<int>& processes, int n, const vector<int>& burst_time) {
    vector<int> wait_time(n), tat(n);
    int total_wt = 0, total_tat = 0;

    vector<int> burst_copy = burst_time;
    sortProcessByBurst(n, burst_copy, const_cast<vector<int>&>(processes));

    wait_time[0] = 0;
    tat[0] = burst_copy[0];

    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i-1] + burst_copy[i-1];
        tat[i] = wait_time[i] + burst_copy[i];
    }

    cout << "Processes Burst time Waiting time Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_wt += wait_time[i];
        total_tat += tat[i];
        cout << processes[i] << "\t\t" << burst_time[i] << "\t\t" << wait_time[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Average waiting time = " << static_cast<float>(total_wt) / n << endl;
    cout << "Average turn around time = " << static_cast<float>(total_tat) / n << endl;
}

int main() {
    vector<int> processes = {1, 2, 3, 4};
    int n = processes.size();
    vector<int> burst_time = {6, 8, 7, 3};

    calculateTimes(processes, n, burst_time);
    return 0;
}
