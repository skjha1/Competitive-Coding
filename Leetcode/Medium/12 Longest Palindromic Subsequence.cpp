//https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    
    int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}
    int longestPalindromeSubseq(string s) {
        
        string rev_X = s;
        int n = s.length();
        reverse(rev_X.begin(), rev_X.end()); // reverse the string // take reversed string as another string of lcs and apply lcs 
	return LCS(s, rev_X, n, n);
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------
	
	class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false

        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};
