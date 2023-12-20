class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size()<2){
            return money;
        }
        sort(prices.begin(),prices.end());
        int ans=prices[0]+prices[1];
        if(money-ans<0){
            return money;
        }
        else
            return(money-ans);
    }
};