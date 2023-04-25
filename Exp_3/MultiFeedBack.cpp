#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int id;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};
bool operator<(const Process &a, const Process &b)
{
    return a.priority < b.priority;
}
int main()
{
    int num_processes;
    cout << "Enter the number of processes: ";
    cin >> num_processes;
    vector<Process> processes(num_processes);
    for (int i = 0; i < num_processes; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter the burst time and priority of process " << processes[i].id << ": ";
        cin >> processes[i].burst_time >> processes[i].priority;
        processes[i].remaining_time = processes[i].burst_time;
    }
    queue<Process> q1, q2, q3;
    for (int i = 0; i < num_processes; i++)
    {
        q1.push(processes[i]);
    }
    int time = 0;
    while (!q1.empty() || !q2.empty() || !q3.empty())
    {
        if (!q1.empty())
        {
            Process p = q1.front();
            q1.pop();
            p.remaining_time--;
            time++;
            if (p.remaining_time == 0)
            {
                p.turnaround_time = time;
                p.waiting_time = p.turnaround_time - p.burst_time;
                cout << "Process " << p.id << " completed at time " << time << endl;
            }
            else if (time % 4 == 0)
            {
                p.priority--;
                q2.push(p);
            }
            else
            {
                q1.push(p);
            }
        }
        else if (!q2.empty())
        {
            Process p = q2.front();
            q2.pop();
            p.remaining_time--;
            time++;
            if (p.remaining_time == 0)
            {
                p.turnaround_time = time;
                p.waiting_time = p.turnaround_time - p.burst_time;
                cout << "Process " << p.id << " completed at time " << time << endl;
            }
            else if (time % 8 == 0)
            {
                p.priority--;
                q3.push(p);
            }
            else
            {
                q2.push(p);
            }
        }
        else if (!q3.empty())
        {
            Process p = q3.front();
            q3.pop();
            p.remaining_time--;
            time++;
            if (p.remaining_time == 0)
            {
                p.turnaround_time = time;
                p.waiting_time = p.turnaround_time - p.burst_time;
                cout << "Process " << p.id << " completed at time " << time << endl;
            }
            else
            {
                q3.push(p);
            }
        }
    }
    return 0;
}