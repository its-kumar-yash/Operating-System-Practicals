#include <bits/stdc++.h>
using namespace std;

struct Page
{
    int pageNum;
    int frequency;
    int lastUsed;
    bool operator<(const Page &other) const
    {
        if (frequency == other.frequency)
        {
            return lastUsed > other.lastUsed;
        }
        return frequency > other.frequency;
    }
};

int main()
{
    unordered_map<int, Page> memory;
    unordered_set<int> inMemory;
    priority_queue<Page> frequencyQueue;
    int hits = 0, faults = 0;
    int memorySize = 3; // assume memory size of 3 pages

    int reference[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(reference) / sizeof(reference[0]);

    for (int i = 0; i < n; i++)
    {
        int page = reference[i];
        if (inMemory.count(page))
        { // hit
            hits++;
            Page hitPage = memory[page];
            hitPage.frequency++;
            hitPage.lastUsed = i;
            memory[page] = hitPage;
        }
        else
        { // page fault
            faults++;
            if (inMemory.size() == memorySize)
            {
                int evicted = frequencyQueue.top().pageNum;
                frequencyQueue.pop();
                inMemory.erase(evicted);
                memory.erase(evicted);
            }
            Page newPage = {page, 1, i};
            inMemory.insert(page);
            memory[page] = newPage;
            frequencyQueue.push(newPage);
        }
    }
    cout << "Hits: " << hits << endl;
    cout << "Faults: " << faults << endl;
    return 0;
}