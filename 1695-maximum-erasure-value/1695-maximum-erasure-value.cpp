class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> um;
        int l=0,r=0;
        int sum = 0, mx = 0;

        while(r<nums.size()){

            if(um.count(nums[r])){
                while(um[nums[r]] > 0){
                    um[nums[l]]--;
                    sum -= nums[l];
                    l++;
                }
            }

            um[nums[r]]++;
            sum += nums[r];

            mx = max(mx, sum);
            r++;
        }

        return mx;
    }
};