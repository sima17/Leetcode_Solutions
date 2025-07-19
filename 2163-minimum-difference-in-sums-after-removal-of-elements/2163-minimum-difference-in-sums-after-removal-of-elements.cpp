class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n), right(n);
        priority_queue<long long> pq; 
        long long s = 0;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
            s += nums[i];
            if (pq.size() > n / 3) {
                s -= pq.top();
                pq.pop();
            }
            if (pq.size() == n / 3) {
                left[i] = s;
            }
        }
        while(!pq.empty()) {
            pq.pop();
        }
        priority_queue<long long, vector<long long>, greater<long long>> min_pq;
        s = 0;
        for (int i = n - 1; i >= 0; i--) {
            min_pq.push(nums[i]);
            s += nums[i];
            if (min_pq.size() > n / 3) {
                s -= min_pq.top();
                min_pq.pop();
            }
            if (min_pq.size() == n / 3) {
                right[i] = s;
            }
        }
        long long ans = LLONG_MAX;
        for (int i = n / 3 - 1; i < n - n / 3; i++) {
            ans = min(ans, left[i] - right[i + 1]);
        }
        return ans;
    }
};