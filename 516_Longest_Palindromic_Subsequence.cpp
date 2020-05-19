optimized solution using recursion:

class Solution {
public:
    int lps(const string& s, int start, int end, vector<vector<int>>& memo) {
        // empty sequence is a palindromic sequence of size 0
	if (start > end)
	    return 0;
	// avoid recomputation
	if (memo[start][end] == -1) {
            // memo[start][end] = memo[start+1][end-1] if s[start]==start[end]
  	    if (s[start] == s[end]) {
		memo[start][end] = 2 + lps(s, start+1, end-1, memo);
	    }
            // otherwise we solve two subproblems: memo[start+1][end] vs memo[start][end-1] and take max
	    else {
		memo[start][end] = max(lps(s, start+1, end, memo), lps(s, start, end-1, memo));
	    }
	}
	return memo[start][end];
    }

    int longestPalindromeSubseq(string s) {
    	int n = s.size();
    	// memo[start][end] : the length of the longest palindromic subsequence in s[start:end]
    	vector<vector<int>> memo(n, vector<int>(n, -1));
    	// each letter is a palindromic sequence of size 1
    	for (int i = 0; i < n; i++)
    	    memo[i][i] = 1;
    	// recursion with memoization
    	return lps(s, 0, n-1, memo);
    }
};

Brute force :

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        
        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        vector<vector<int> > dp(N, vector<int>(N, 0));
        
        // all single chars are palindromic
        for(int i = 0; i < N; i++)
            dp[i][i] = 1;
        
        for(int l = 1; l < N; l++) {
            // starting index of window
            for(int i = 0; i < N - l; i++) {
                // ending index of window
                int j = i + l;
                
                // if there are only two chars
                if((j - i + 1) == 2) {
                    // if the chars are same, then that contributes 2, otherwise since
                    // individually they are palindromic so max length 1
                    dp[i][j] = 1 + (s[i] == s[j]);
                }
                else {
                    // for s[i:j]:
                    // longest palindrome length in s[i+1 : j-1] and +1 if s[i] == s[j]
                    // if s[i] != s[j], longest length palindrome = Max of longest palin in s[i:j-1] and s[i+1:j]
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N-1];
        
    }
};