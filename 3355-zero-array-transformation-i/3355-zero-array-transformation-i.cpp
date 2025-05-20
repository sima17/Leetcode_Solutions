class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        for (int i = 0 ; i < queries.size() ; i++) 
            for (int j = queries[i][0]; j <= queries[i][1]; j++) 
                if (nums[j] > 0) nums[j]--;

        for (int i = 0 ; i < nums.size(); i++) 
            if (nums[i] != 0) return false;
        return true;
    }
};