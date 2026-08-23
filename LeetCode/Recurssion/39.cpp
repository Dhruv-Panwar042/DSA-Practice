class Solution {
public:
    void solve(int index, int target, vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i = index; i < candidates.size(); i++) {
            // pick
            curr.push_back(candidates[i]);

            solve(i, target - candidates[i], candidates, curr, ans);

            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, target, candidates, curr, ans);

        return ans;
    }
};