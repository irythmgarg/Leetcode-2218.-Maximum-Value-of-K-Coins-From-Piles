class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // Create a 2D DP table where dp[i][j] represents the maximum value using
        // the first i piles and choosing j coins
        vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1, 0));

        // Loop through each pile (1-indexed for dp)
        for (int i = 1; i <= piles.size(); i++) {
            // Try all possible number of coins we can take in total up to k
            for (int coin = 0; coin <= k; coin++) {
                int sum = 0;  // Sum of coins picked from current pile

                // Try picking 0 to min(coin, current pile size) coins from this pile
                for (int currcoin = 0; currcoin <= piles[i - 1].size() && currcoin <= coin; currcoin++) {
                    if (currcoin - 1 >= 0) {
                        // Accumulate prefix sum of coins from current pile
                        sum += piles[i - 1][currcoin - 1];
                    }

                    // Update dp[i][coin]: max of not taking from current pile vs taking currcoin coins
                    // dp[i-1][coin-currcoin] -> max value from previous piles with remaining coins
                    dp[i][coin] = max(dp[i][coin], sum + dp[i - 1][coin - currcoin]);
                }
            }
        }

        // Return the answer using all piles and exactly k coins
        return dp[piles.size()][k];
    }
};
