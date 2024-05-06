#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;
};

void findWaitingTime(vector<Process>& processes, int quantum) {
    vector<int> rem_bt(processes.size());
    for (size_t i = 0; i < processes.size(); i++)
        rem_bt[i] = processes[i].burstTime;

    int t = 0; // Current time

    while (true) {
        bool done = true;

        for (size_t i = 0; i < processes.size(); i++) {
            if (rem_bt[i] > 0) {
                done = false; // There is a pending process

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    processes[i].burstTime = t; // Store waiting time
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }
}

void findTurnAroundTime(vector<Process>& processes) {
    for (size_t i = 0; i < processes.size(); i++)
        processes[i].burstTime += processes[i].burstTime;
}

void findAvgTime(vector<Process>& processes, int quantum) {
    findWaitingTime(processes, quantum);
    findTurnAroundTime(processes);

    int total_wt = 0, total_tat = 0;
    cout << "Processes Burst time Waiting time Turn around time\n";

    for (size_t i = 0; i < processes.size(); i++) {
        total_wt += processes[i].burstTime;
        total_tat += processes[i].burstTime + processes[i].burstTime;
        cout << i+1 << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].burstTime
             << "\t\t" << processes[i].burstTime + processes[i].burstTime << endl;
    }

    cout << "Average waiting time = " << static_cast<float>(total_wt) / processes.size() << endl;
    cout << "Average turn around time = " << static_cast<float>(total_tat) / processes.size() << endl;
}

int main() {
    vector<Process> processes = {{1, 24}, {2, 3}, {3, 3}};
    int quantum = 4;

    findAvgTime(processes, quantum);
    return 0;
}
