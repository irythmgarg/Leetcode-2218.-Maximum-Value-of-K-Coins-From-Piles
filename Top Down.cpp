class Solution {
public:
    // Memoization table to store results of subproblems
    // dp[k][pile] represents the maximum value we can get by picking k coins starting from 'pile'
    int dp[2001][1001];

    // Recursive function to compute the maximum value
    int hlo(vector<vector<int>>& piles, int k, int pile)
    {
        // Base case: No coins left to pick
        if (k <= 0)
            return 0;

        // Base case: No more piles left to consider
        if (pile >= piles.size())
            return 0;

        // If already computed, return the stored result
        if (dp[k][pile] != -1)
            return dp[k][pile];

        // Option 1: Skip the current pile
        int nottaken = hlo(piles, k, pile + 1);

        int maxans = 0; // To track the maximum value achievable from this state
        int ans = 0;    // To accumulate the prefix sum of coins picked from the current pile

        // Try taking 1 to min(k, size of current pile) coins from the current pile
        for (int i = 0; i < piles[pile].size() && i < k; i++)
        {
            ans += piles[pile][i]; // Add the i-th coin's value to the current sum

            // Option 2: Take (i+1) coins and solve the remaining problem for (k - i - 1) coins from the next pile
            maxans = max(maxans, ans + hlo(piles, k - i - 1, pile + 1));
        }

        // Store and return the maximum of the two options
        return dp[k][pile] = max(nottaken, maxans);
    }

    // Main function
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // Initialize the memoization table with -1
        memset(dp, -1, sizeof(dp));

        // Start from the 0th pile with k coins to pick
        return hlo(piles, k, 0);
    }
};
