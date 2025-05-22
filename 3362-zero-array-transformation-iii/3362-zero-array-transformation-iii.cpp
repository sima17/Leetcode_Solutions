class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
      
        sort(queries.begin(),queries.end());
        int n=nums.size();
       
        priority_queue<int>available;
       
        priority_queue<int,vector<int>,greater<int>>chosen;

        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
           
            while(j<queries.size() && queries[j][0]==i){
                available.push(queries[j][1]);
                j++;
            }
            nums[i]-=chosen.size();
            while(nums[i]>0 && !available.empty() && available.top()>=i){
                chosen.push(available.top());
                available.pop();
                nums[i]--;
                ans++;
            }

            
            if(nums[i]>0) return -1;
            
            while(!chosen.empty() && chosen.top()==i) chosen.pop();
        }

        return queries.size()-ans;
    }
};