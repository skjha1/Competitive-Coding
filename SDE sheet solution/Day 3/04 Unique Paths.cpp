// Since the robot can only move right and down, when it arrives at a point, it either arrives from left or above. If we use dp[i][j] for the number of unique paths 
// to arrive at the point (i, j), then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j]. Moreover, we have the base cases dp[0][j] = dp[i][0] = 1 for all valid i and j.


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
/*
The above solution runs in O(m * n) time and costs O(m * n) space. However, you may have noticed that each time when we update dp[i][j], we only need dp[i - 1][j] 
(at the previous row) and dp[i][j - 1] (at the current row). So we can reduce the memory usage to just two rows (O(n)).
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};
/*
Further inspecting the above code, pre[j] is just the cur[j] before the update. So we can further reduce the memory usage to one row.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
};
/*
Now, you may wonder whether we can further reduce the memory usage to just O(1) space since the above code seems to use only two variables (cur[j] and cur[j - 1]). 
However, since the whole row cur needs to be updated for m - 1 times (the outer loop) based on old values, all of its values need to be saved and thus O(1)-space is 
impossible. However, if you are having a DP problem without the outer loop and just the inner one, then it will be possible.
*/
