#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to check if a resource is already in the list
bool contains(vector<int> list, int resource) {
    return (find(list.begin(), list.end(), resource) != list.end());
}
int main() {
    int n, m; // number of processes and resources
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;
    // allocate a 2D array to represent the allocation matrix
    int** allocation = new int*[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = new int[m];
        cout << "Enter the allocation matrix for process " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }
    // allocate a 2D array to represent the request matrix
    int** request = new int*[n];
    for (int i = 0; i < n; i++) {
        request[i] = new int[m];
        cout << "Enter the request matrix for process " << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> request[i][j];
        }
    }
    // allocate a vector to store the available resources
    vector<int> available(m);
    cout << "Enter the available resources: ";
    for (int i = 0; i < m; i++) {
        cin >> available[i];
    }
    // allocate vectors to store the work and finish arrays
    vector<int> work = available;
    vector<bool> finish(n, false);
    // loop through the processes to find a safe sequence
    vector<int> safeSequence;
    bool found;
    do {
        found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i] && contains(work, request[i][0])) {
                bool canRun = true;
                for (int j = 1; j < m; j++) {
                    if (request[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    safeSequence.push_back(i);
                    found = true;
                }
            }
        }
    } while (found);
    // check if there is a deadlock
    bool deadlock = false;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = true;
            break;
        }
    }
    // print the safe sequence or deadlock message
    if (deadlock) {
        cout << "There is a deadlock." << endl;
    } else {
        cout << "The safe sequence is: ";
        for (int i = 0; i < n; i++) {
            cout << "P" << safeSequence[i];
            if (i != n - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    // deallocate the memory
    for (int i = 0; i < n; i++) {
        delete[] allocation[i];
        delete[] request[i];
    }
    delete[] allocation;
    delete[] request;

    return 0;
}