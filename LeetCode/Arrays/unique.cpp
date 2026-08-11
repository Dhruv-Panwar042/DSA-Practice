class Solution {
public:
    int firstUniqChar(string s) {


        map<int, int> freq;

        for(int x : s)
            freq[x]++;

        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i]] == 1)
                return i;
        }

        return -1;
    }
};