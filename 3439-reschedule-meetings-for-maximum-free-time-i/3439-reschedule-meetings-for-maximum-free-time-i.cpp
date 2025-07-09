class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        gaps.reserve(n + 1);
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime[n - 1]);
        int sz = min(k + 1, int(gaps.size()));
        long long curr = 0, best = 0;
        for (int i = 0; i < sz; ++i) curr += gaps[i];
        best = curr;
        for (int i = sz; i < gaps.size(); ++i) {
            curr += gaps[i] - gaps[i - sz];
            if (curr > best) best = curr;
        }
        return int(best);
    }
};