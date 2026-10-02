class Solution {
public:
    void solve(string curr, int open, int close, int n, vector<string>& ans) {
        if(curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Pick '('
        if(open < n) {
            curr.push_back('(');
            solve(curr, open + 1, close, n, ans);
            curr.pop_back();
        }

        // Pick ')'
        if(close < open) {
            curr.push_back(')');
            solve(curr, open, close + 1, n, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve("", 0, 0, n, ans);

        return ans;
    }
};