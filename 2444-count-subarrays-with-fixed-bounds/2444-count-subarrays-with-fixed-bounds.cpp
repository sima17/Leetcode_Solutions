class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count=0;
        int lastMinK=-1;
        int lastMaxK=-1;
        int lastInvalid=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK|| nums[i]>maxK){
                lastInvalid=i;
            }
            if(nums[i]==minK) lastMinK=i;
            if(nums[i]==maxK) lastMaxK=i;
            int validStart=min(lastMinK,lastMaxK);
            if(validStart>lastInvalid){
                count+=(validStart-lastInvalid);
            }

        }
        return count;
    }
};