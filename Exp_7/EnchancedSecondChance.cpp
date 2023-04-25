#include <bits/stdc++.h>
using namespace std;

struct Page
{
    int pageNum;
    bool secondChance;
    bool modified;
};
int main()
{
    unordered_map<int, Page> memory;
    unordered_set<int> inMemory;
    queue<int> fifoQueue;
    vector<int> reference = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int hits = 0, faults = 0;
    int memorySize = 3; // assume memory size of 3 pages

    for (int i = 0; i < reference.size(); i++)
    {
        int page = reference[i];
        if (inMemory.count(page))
        { // hit
            hits++;
            memory[page].secondChance = true;
        }
        else
        { // page fault
            faults++;
            if (inMemory.size() == memorySize)
            {
                int evictedPage = -1;
                while (evictedPage == -1)
                {
                    int pageToCheck = fifoQueue.front();
                    fifoQueue.pop();
                    if (memory[pageToCheck].secondChance)
                    {
                        fifoQueue.push(pageToCheck);
                        memory[pageToCheck].secondChance = false;
                    }
                    else if (memory[pageToCheck].modified)
                    {
                        evictedPage = pageToCheck;
                        inMemory.erase(evictedPage);
                        memory.erase(evictedPage);
                    }
                    else
                    {
                        evictedPage = pageToCheck;
                        inMemory.erase(evictedPage);
                        memory.erase(evictedPage);
                    }
                }
            }
            Page newPage = {page, true, false};
            fifoQueue.push(page);
            inMemory.insert(page);
            memory[page] = newPage;
        }
        if (memory[page].modified)
        { // page is in memory but has been modified
            memory[page].modified = false;
        }
    }
    cout << "Total Hits: " << hits << endl;
    cout << "Total Faults: " << faults << endl;
    return 0;
}