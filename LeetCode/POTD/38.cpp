class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        long long sum = 0;

        for(int num : nums) {
            sum += num;
        }

        return sum - (long long)mn * nums.size();
    }
};