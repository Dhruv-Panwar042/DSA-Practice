class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;

        int even = 1;
        int odd = 0;

        int prefixSum = 0;
        int answer = 0;

        for(int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if(prefixSum % 2 == 0) {
                answer = (answer + odd) % MOD;
                even++;
            }
            else {
                answer = (answer + even) % MOD;
                odd++;
            }
        }

        return answer;
    }
};