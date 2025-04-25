#include<vector>
#include<algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            else{
            int profit=prices[i]-minPrice;
            maxProfit=max(maxProfit,profit);
        }
        }

    
    return maxProfit;
    }
};