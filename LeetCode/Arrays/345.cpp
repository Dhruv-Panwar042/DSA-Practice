class Solution {
public:

    string toLowerCase(string s) {
        string ans = "";

        for(char ch : s) {
            ans += tolower(ch);
        }

        return ans;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        string ans = toLowerCase(s);

        int left = 0;
        int right = s.size() - 1;

        while(left < right) {

            if(isVowel(ans[left]) && isVowel(ans[right])) {
                swap(s[left], s[right]);

                left++;
                right--;
            }

            else if(!isVowel(ans[left])) {
                left++;
            }

            else {
                right--;
            }
        }

        return s;
    }
};