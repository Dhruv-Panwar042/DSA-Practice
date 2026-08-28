class Solution {
public:

    string makePalindrome(string& left, char middle) {
        string ans = left;

        if (middle != '#') {
            ans += middle;
        }

        for (int i = left.size() - 1; i >= 0; i--) {
            ans += left[i];
        }

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = '#';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // We only need half of each frequency
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
        }

        int halfLen = n / 2;

        string left = "";

        // Construct left half
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Try smallest possible character
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Temporarily use this character
                half[c]--;
                left.push_back(char('a' + c));

                // Construct the LARGEST possible remaining half
                string temp = left;

                for (int x = 25; x >= 0; x--) {
                    temp += string(half[x], char('a' + x));
                }

                // Construct maximum possible palindrome
                string candidate = temp;

                if (middle != '#') {
                    candidate += middle;
                }

                for (int i = temp.size() - 1; i >= 0; i--) {
                    candidate += temp[i];
                }

                // Can this choice eventually produce
                // something greater than target?
                if (candidate > target) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            // No character works
            if (!found) {
                return "";
            }
        }

        // Construct final answer
        string ans = left;

        if (middle != '#') {
            ans += middle;
        }

        for (int i = left.size() - 1; i >= 0; i--) {
            ans += left[i];
        }

        if (ans > target)
            return ans;

        return "";
    }
};