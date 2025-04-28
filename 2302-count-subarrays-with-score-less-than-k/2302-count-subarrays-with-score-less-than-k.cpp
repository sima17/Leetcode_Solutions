class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0;
        long long sum=0;
        long long count=0;
        
        for (int r=0; r<nums.size(); ++r) {
            sum+=nums[r];
            
            while (l<=r && sum*(r-l+1)>=k) {
                sum -= nums[l];
                l++;
            }
            
            count += (r-l+1);
        }
        
        return count;
    }
};