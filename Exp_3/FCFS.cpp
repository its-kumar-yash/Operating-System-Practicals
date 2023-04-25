#include<iostream> 
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    // waiting time for first process is 0
    wt[0] = 0;
    // calculating waiting time for
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i-1] + wt[i-1];
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}
void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
    // Display processes along with all details
    cout << "Processes\tBurst time\tWaiting time\tTurn around time\n";
    for (int i=0; i<n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
    cout << '\n';
}

int main() {
    int num, temp;
    cout << "Enter number of Process: ";
    cin >> num;
    int processes[num];
    int burst_time[num];
    cout << "...Enter the process ID...\n";
    for (int i=0; i<num; i++) {
        cout << "...Process " << i+1 << "...\n";
        cout << "Enter Process Id: ";
        cin >> processes[i];
        cout << "Enter Burst Time: ";
        cin >> burst_time[i];
    }
    int n = sizeof processes / sizeof processes[0];
    findavgTime(processes, n, burst_time);
    return 0;
}