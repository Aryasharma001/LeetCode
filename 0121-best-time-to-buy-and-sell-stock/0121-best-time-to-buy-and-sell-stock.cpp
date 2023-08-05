class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX;
        int high=0;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<low){
                low=prices[i];
                high=0;
            }
            if(prices[i]>high){
                high=prices[i];
            }
            profit=max(high-low,profit);
        }
        return profit;
    }
};