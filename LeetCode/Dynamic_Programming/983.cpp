class Solution {
public:
    int solve(int i, vector<int>& days, vector<int>& costs,
              vector<int>& dp) {

        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Buy 1-day pass
        int oneDay = costs[0] + solve(i + 1, days, costs, dp);

        // Buy 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7)
            j++;

        int sevenDay = costs[1] + solve(j, days, costs, dp);

        // Buy 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30)
            j++;

        int thirtyDay = costs[2] + solve(j, days, costs, dp);

        return dp[i] = min({oneDay, sevenDay, thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        vector<int> dp(n, -1);

        return solve(0, days, costs, dp);
    }
};