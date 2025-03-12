class Solution {
public:
  int maximumCount(vector<int>& nums) {
    int n = nums.size();
    if (n==0) return 0; 

    int first_Pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
    int last_Neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
    return max(last_Neg, n - first_Pos);
}
};