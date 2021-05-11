// https://leetcode.com/problems/online-stock-span/
class StockSpanner {
    stack <pair<int,int>> s;
public:
    StockSpanner() {
    }
    
    
    int next(int price) {
        int res=1;
        while (s.size()!=0 && s.top().first<=price)
        {
            res+=s.top().second;
            s.pop();
        }
        s.push({price,res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
