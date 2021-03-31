class Solution {
public:
    long reverse(int n) {
        // support variables
        long res = 0;
        // restructuring the number
        while (n) {
            res = res * 10 + n  % 10;
            n /= 10;
        }
        // filtering out invalid results
        if (res < -2147483648 || res > 2147483647) return 0;
        return res;
    }
};
