#include <iostream>
#include <algorithm> 

using namespace std;

struct Process {
    int id;
    int burstTime;
    int priority;
};

void sortProcessesByPriority(Process processes[], int n) {
    sort(processes, processes + n, [](const Process& a, const Process& b) {
        return a.priority < b.priority;
    });
}

void findWaitingTime(Process processes[], int n, int waitTime[]) {
    waitTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitTime[i] = processes[i - 1].burstTime + waitTime[i - 1];
    }
}

void findTurnAroundTime(Process processes[], int n, int waitTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = processes[i].burstTime + waitTime[i];
    }
}

void findAvgTime(Process processes[], int n) {
    int waitTime[n], turnAroundTime[n];
    float total_wt = 0, total_tat = 0;

    sortProcessesByPriority(processes, n);
    findWaitingTime(processes, n, waitTime);
    findTurnAroundTime(processes, n, waitTime, turnAroundTime);

    cout << "Processes Burst time Priority Waiting time Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_wt += waitTime[i];
        total_tat += turnAroundTime[i];
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" 
             << processes[i].priority << "\t\t" << waitTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }

    cout << "Average waiting time = " << total_wt / n << endl;
    cout << "Average turn around time = " << total_tat / n << endl;
}

int main() {
    Process processes[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof(processes) / sizeof(processes[0]);

    findAvgTime(processes, n);

    return 0;
}
