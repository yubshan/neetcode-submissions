class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice =  prices[0];
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int profit = prices[i] - buyPrice ;
            ans = max( ans, profit);
            buyPrice = min(prices[i], buyPrice);
        };
        return ans;
    }
};
