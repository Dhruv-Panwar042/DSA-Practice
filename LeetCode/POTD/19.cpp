#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1000000007;

        int n = s.length();

        vector<long long> dp(n + 1, 0);
        vector<long long> last(26, 0);

        // Empty subsequence
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            int ch = s[i - 1] - 'a';

            // Every old subsequence can either
            // take or not take the current character
            dp[i] = (2 * dp[i - 1]) % MOD;

            // Remove duplicates
            dp[i] = (dp[i] - last[ch] + MOD) % MOD;

            // Store the number of subsequences
            // before this character appeared
            last[ch] = dp[i - 1];
        }

        // Remove the empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};