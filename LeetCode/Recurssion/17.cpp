class Solution {
public:
    void solve(int ind, string digits, string current, vector<string>& ans, vector<string>& keypad) {

         if(ind == digits.size()){
            ans.push_back(current);
            return;
        }

        int digit = digits[ind] - '0';

        for(char ch : keypad[digit]) {
            current.push_back(ch);

            solve(ind + 1, digits, current, ans, keypad);

            current.pop_back(); 



        

        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.empty())
            return ans;

        vector<string> keypad = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, "", ans, keypad);

        return ans;
    }
};