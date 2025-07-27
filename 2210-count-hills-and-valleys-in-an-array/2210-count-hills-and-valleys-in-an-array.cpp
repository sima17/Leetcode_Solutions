class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int l = 0, m = 1, r = 2, res = 0;

        while (r < n) {
            while (r < n && nums[l] == nums[m]) {
                m++;
            }
            r = m + 1;
            while (r < n && nums[m] == nums[r]) {
                r++;
            }
            if (r < n && ((nums[l] > nums[m] && nums[r] > nums[m]) ||
                          (nums[l] < nums[m] && nums[r] < nums[m]))) {
                res++;
            }
            l = m;
            m = r;
        }
        return res;
    }
};