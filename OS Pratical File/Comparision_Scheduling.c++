#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
};

bool compareArrivalTime(const Process &a, const Process &b) {
    return a.arrival_time < b.arrival_time;
}

bool compareBurstTime(const Process &a, const Process &b) {
    return a.burst_time < b.burst_time;
}

bool comparePriority(const Process &a, const Process &b) {
    return a.priority > b.priority;
}

void FCFS(const vector<Process> &processes) {
    cout << "FCFS Scheduling:\n";
    int currentTime = 0;
    for (const auto &process : processes) {
        currentTime = max(currentTime, process.arrival_time);
        cout << "Process " << process.id << " starts at " << currentTime << " and ends at " << currentTime + process.burst_time << "\n";
        currentTime += process.burst_time;
    }
}

void SJF(const vector<Process> &processes) {
    cout << "SJF Scheduling:\n";
    vector<Process> remainingProcesses = processes;
    sort(remainingProcesses.begin(), remainingProcesses.end(), compareArrivalTime);
    int currentTime = 0;
    while (!remainingProcesses.empty()) {
        auto shortestProcess = min_element(remainingProcesses.begin(), remainingProcesses.end(), compareBurstTime);
        currentTime = max(currentTime, shortestProcess->arrival_time);
        cout << "Process " << shortestProcess->id << " starts at " << currentTime << " and ends at " << currentTime + shortestProcess->burst_time << "\n";
        currentTime += shortestProcess->burst_time;
        remainingProcesses.erase(shortestProcess);
    }
}

void RoundRobin(const vector<Process> &processes, int quantum) {
    cout << "Round Robin Scheduling with quantum " << quantum << ":\n";
    queue<Process> readyQueue;
    vector<Process> remainingProcesses = processes;
    sort(remainingProcesses.begin(), remainingProcesses.end(), compareArrivalTime);
    int currentTime = 0;
    int totalProcesses = processes.size();
    int completedProcesses = 0;
    while (completedProcesses < totalProcesses) {
        for (auto &process : remainingProcesses) {
            if (process.arrival_time <= currentTime) {
                readyQueue.push(process);
            }
        }
        if (!readyQueue.empty()) {
            Process currentProcess = readyQueue.front();
            readyQueue.pop();
            int executionTime = min(quantum, currentProcess.burst_time);
            cout << "Process " << currentProcess.id << " starts at " << currentTime << " and ends at " << currentTime + executionTime << "\n";
            currentTime += executionTime;
            currentProcess.burst_time -= executionTime;
            if (currentProcess.burst_time > 0) {
                readyQueue.push(currentProcess);
            } else {
                completedProcesses++;
            }
        } else {
            currentTime++;
        }
    }
}

void PriorityScheduling(const vector<Process> &processes) {
    cout << "Priority Scheduling:\n";
    vector<Process> remainingProcesses = processes;
    sort(remainingProcesses.begin(), remainingProcesses.end(), compareArrivalTime);
    int currentTime = 0;
    while (!remainingProcesses.empty()) {
        auto highestPriorityProcess = min_element(remainingProcesses.begin(), remainingProcesses.end(), comparePriority);
        currentTime = max(currentTime, highestPriorityProcess->arrival_time);
        cout << "Process " << highestPriorityProcess->id << " starts at " << currentTime << " and ends at " << currentTime + highestPriorityProcess->burst_time << "\n";
        currentTime += highestPriorityProcess->burst_time;
        remainingProcesses.erase(highestPriorityProcess);
    }
}

int main() {
    vector<Process> processes = {
        {1, 0, 6, 2},
        {2, 2, 4, 1},
        {3, 4, 2, 3},
        {4, 6, 5, 2},
        {5, 8, 3, 1}
    };

    FCFS(processes);
    cout << "\n";
    SJF(processes);
    cout << "\n";
    RoundRobin(processes, 2);
    cout << "\n";
    PriorityScheduling(processes);

    return 0;
}
