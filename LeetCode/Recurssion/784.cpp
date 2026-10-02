class Solution {
public:
    void solve(int index, string& s, vector<string>& ans) {
        if(index == s.length()) {
            ans.push_back(s);
            return;
        }

        // if the character is a digit
        if(isdigit(s[index])) {
            solve(index + 1, s, ans);
            return;
        }

        // Choice - 1: To lowercase
        s[index] = tolower(s[index]);
        solve(index + 1, s, ans);

        // Choice - 2: To uppercase
        s[index] = toupper(s[index]);
        solve(index + 1, s, ans);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;

        solve(0, s, ans);

        return ans;
    }
};