#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> memory;
    unordered_set<int> inMemory;
    vector<int> reference = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int hits = 0, faults = 0;
    int memorySize = 3; // assume memory size of 3 pages

    for (int i = 0; i < reference.size(); i++) {
        int page = reference[i];
        if (inMemory.count(page)) { // hit
            hits++;
            memory[page] = i;
        } else { // page fault
            faults++;
            if (inMemory.size() == memorySize) {
                int evictedPage = -1;
                int maxLastUsed = -1;
                for (auto it = memory.begin(); it != memory.end(); it++) {
                    if (it->second > maxLastUsed) {
                        evictedPage = it->first;
                        maxLastUsed = it->second;
                    }
                }
                inMemory.erase(evictedPage);
                memory.erase(evictedPage);
            }
            inMemory.insert(page);
            memory[page] = i;
        }
    }
    cout << "Total Hits: " << hits << endl;
    cout << "Total Faults: " << faults << endl;
    return 0;
}