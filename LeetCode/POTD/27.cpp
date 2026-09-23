class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;

        for(int num : nums) {
            total += num;
        }

        int target = total - x;

        // We need to remove everything
        if(target < 0) {
            return -1;
        }

        // If target == 0, we have to remove all elements
        if(target == 0) {
            return n;
        }

        int left = 0;
        int sum = 0;
        int maxLength = -1;

        for(int right = 0; right < n; right++) {
            sum += nums[right];

            while(sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        if(maxLength == -1) {
            return -1;
        }

        return n - maxLength;
    }
};