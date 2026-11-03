class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = 0;

        for(int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
        }

        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            cnt += abs(mx - nums[i]);
        }

        return cnt;
    }
};