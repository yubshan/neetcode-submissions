class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sellPrice = 0;
        int ans = 0;
        for(int i = n-1 ; i >= 0; i--){
            int profit = sellPrice - prices[i];
            ans = max( ans, profit);
            sellPrice = max(prices[i], sellPrice);
        };
        return ans;
    }
};
