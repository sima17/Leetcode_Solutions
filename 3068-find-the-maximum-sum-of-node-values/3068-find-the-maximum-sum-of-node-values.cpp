class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        ll sum = 0;
        int count = 0;
        int n = nums.size();
        int minDiff = INT_MAX;

        for(int i = 0; i<n; i++){
            if((nums[i]^k) > nums[i]){
                count++;
                sum += (nums[i]^k);
            }
            else{
                sum += nums[i];
            }

            minDiff = min(minDiff, abs(nums[i] - (nums[i]^k)));
        }

        if(count&1){
            sum -= minDiff;
        }
        return sum;
    }
};