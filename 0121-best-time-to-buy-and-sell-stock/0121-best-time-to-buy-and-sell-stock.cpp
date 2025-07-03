class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            maxProfit = max(prices[i] - minPrice, maxProfit);
            minPrice = min(prices[i], minPrice);
        }
        return maxProfit;
    }
};