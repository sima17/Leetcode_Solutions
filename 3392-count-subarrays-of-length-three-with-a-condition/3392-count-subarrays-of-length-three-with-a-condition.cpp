class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        const int n=nums.size();
        int cnt=0;
        for(int i=1; i<n-1; i++)
            cnt+=(2*(nums[i-1]+nums[i+1])-nums[i]==0);
        return cnt;
    }
};