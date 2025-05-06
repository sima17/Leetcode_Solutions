class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n; i++){
            // final Value will be multiplied to 1000
            int finalValue = nums[nums[i]]%1000;
            // Original Value will be added to this multiple
            nums[i] = nums[i] + (1000 * finalValue);
        }

        for(int i = 0; i<n; i++){
            // Since finalValue was multiplied to 1000 so, on divide we get finalValue
            nums[i] = nums[i]/1000;
        }
        return nums;
    }
};