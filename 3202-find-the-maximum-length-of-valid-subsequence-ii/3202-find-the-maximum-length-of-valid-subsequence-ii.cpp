class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int dp[1001][1001]={0};
        int ans=0;

        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                int t=(nums[i]+nums[j])%k;
                dp[i][t]=dp[j][t]+1;
                ans=max(ans,dp[i][t]);
            }
        }
        return ans+1;
    }
};