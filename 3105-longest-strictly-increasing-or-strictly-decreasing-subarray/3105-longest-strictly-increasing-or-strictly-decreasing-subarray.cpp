class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxHeight = 0;
        int i = 1;
        int len = 1;
        while(i<nums.size()){
            if(nums[i]>nums[i-1]){
                len++;
            }else{
                maxHeight = max(maxHeight, len);
                len = 1;
            }
            i++;
        }
        maxHeight = max(maxHeight, len);

        i = 1;
        len = 1;
        while(i<nums.size()){
            if(nums[i]<nums[i-1]){
                len++;
            }else{
                maxHeight = max(maxHeight, len);
                len = 1;
            }
            i++;
        }
        maxHeight = max(maxHeight, len);

        return maxHeight;

    }
};