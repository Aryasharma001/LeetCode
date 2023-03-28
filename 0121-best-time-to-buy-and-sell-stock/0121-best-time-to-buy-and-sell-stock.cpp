class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far=prices[0];
        int max_profit=0;    
        for(int i=0;i<prices.size();i++){
            min_so_far=min(min_so_far,prices[i]);
            max_profit=max(max_profit,(prices[i]-min_so_far));
        }
        return max_profit;
        
    }
};