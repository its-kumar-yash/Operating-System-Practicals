#include <bits/stdc++.h>
using namespace std;

int pageFaults(int pages[], int n, int capacity)
{
    // set to hold current set of pages
    unordered_set<int> s;
    // Queue to implement FIFO
    queue<int> indexes;
    // init_ variables
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present; represents page fault
            if (s.find(pages[i]) == s.end())
            {
                // Insert the current page into the set
                s.insert(pages[i]);
                // increment page fault
                page_faults++;
                // Push the current page into the queue
                indexes.push(pages[i]);
            }
        }
        // If the set is full then need to perform FIFO
        // remove the first page and insert the current page else
        else
        {
            // Check if current page is present
            if (s.find(pages[i]) == s.end())
            {
                // Store the first page
                int val = indexes.front();
                // Pop the first page from the queue
                indexes.pop();
                // Remove the indexes page from the set
                s.erase(val);
                // insert the current page in the set
                s.insert(pages[i]);
                // push the current page
                indexes.push(pages[i]);
                // Increment page faults
                page_faults++;
            }
        }
    }
    return page_faults;
}
int main()
{
    int n;
    cout << "Enter the number of pages in the sequence: "; // 13
    cin >> n;
    int pages[n];
    cout << "Enter the sequence of pages that will be called: ";
    //  7 0 1 2 0 3 0 4 2 3 0 3 2
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    int capacity; // 4
    cout << "Enter the capacity of pages that can be held in memory: ";
    cin >> capacity;
    cout << "The number of page faults encountered: " << pageFaults(pages, n, capacity);
    cout << '\n';
    return 0;
}