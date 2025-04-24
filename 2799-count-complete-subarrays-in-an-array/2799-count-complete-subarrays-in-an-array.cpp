class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // Step 1: Count the total number of distinct elements in the whole array
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        int totalUnique = uniqueElements.size();
        int n = nums.size();
        int count = 0;

        // Step 2: Check every subarray starting at i
        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            for (int j = i; j < n; ++j) {
                seen.insert(nums[j]);
                if (seen.size() == totalUnique) {
                    count++;
                }
            }
        }

        return count;
    }
};
