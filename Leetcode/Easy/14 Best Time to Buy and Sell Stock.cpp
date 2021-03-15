class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0; //initially set max profit as zero 
        int min_price= INT_MAX; // min price as max number 
        for (int i=0;i<prices.size();i++){ // itearating through the loop 
            min_price=min(min_price,prices[i]); // compare the elements with min_price and return the minimum one 
            max_profit=max(max_profit,prices[i]-min_price); // in order to get max profit compare current (mininum price - current stock) with max profit 
        }
        return max_profit; // at last we will get the ,maximum profit 
    }
};
