class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);

        // freq of characters in p
        for(char ch : p)
            freqP[ch - 'a']++;

        int k = p.size();

        // first window
        for(int i = 0; i < k; i++) {
            freqWindow[s[i] - 'a']++;
        }

        // check first window
        if(freqWindow == freqP) {
            ans.push_back(0);
        }

        // slide the window
        for(int right = k; right < s.size(); right++) {
            // add new character
            freqWindow[s[right] - 'a']++;

            // remove character leaving the window
            int left = right - k;
            freqWindow[s[left] - 'a']--;

            if(freqWindow == freqP) {
                ans.push_back(left + 1);
            }
        }

        return ans;
    }
};