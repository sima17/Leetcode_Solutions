#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 1, i = 0, n = events.size(), attended = 0;

        int maxDay = 0;
        for (const auto& event : events) {
            maxDay = max(maxDay, event[1]);
        }

        for (day = 1; day <= maxDay; ++day) {
          
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
 
            if (!minHeap.empty()) {
                minHeap.pop();
                ++attended;
            }
        }

        return attended;
    }
};