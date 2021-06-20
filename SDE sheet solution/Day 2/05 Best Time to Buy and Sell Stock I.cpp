class Solution {
public:
    int maxProfit(vector<int> &prices) {
    int ret = 0;
    for (int p = 1; p < prices.size(); ++p) 
      ret += max(prices[p] - prices[p - 1], 0);    
    return ret;
}
};
