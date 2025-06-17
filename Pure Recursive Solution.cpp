class Solution {
public:

    // Recursive function to find the maximum value by picking coins
    int hlo(vector<vector<int>>& piles, int k, int pile) {

        // Base case: if no coins left to pick, return 0
        if (k <= 0) return 0;

        // Base case: if all piles are exhausted, return 0
        if (pile >= piles.size()) return 0;

        // Case 1: Skip the current pile
        int nottaken = hlo(piles, k, pile + 1);

        int maxans = 0;  // Stores the maximum answer for current pile
        int ans = 0;     // Sum of coins taken from the current pile

        // Try taking 1 to min(k, size of pile) coins from the current pile
        for (int i = 0; i < piles[pile].size() && i < k; i++) {
            ans += piles[pile][i];  // Add current coin to the sum

            // Case 2: Take (i+1) coins from the current pile and recursively process remaining
            maxans = max(maxans, ans + hlo(piles, k - i - 1, pile + 1));
        }

        // Return the maximum of taking or not taking coins from the current pile
        return max(nottaken, maxans);
    }

    // Main function to start recursion
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return hlo(piles, k, 0);  // Start from the first pile with k coins to pick
    }
};
