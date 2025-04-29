class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0, ans = 0;
        int n = nums.size(), j = 0, maxi = INT_MIN;
        for(int i:nums) maxi = max(maxi, i);
        for(int i=0;i<n;i++){
            if(nums[i] == maxi) count++;
            if(count == k) ans += n-i;
            while(count == k){
                j++;
                if(nums[j-1] == maxi){
                    count--;
                    continue;
                }
                ans += n-i;
            }
        }
        return ans;
    }
};