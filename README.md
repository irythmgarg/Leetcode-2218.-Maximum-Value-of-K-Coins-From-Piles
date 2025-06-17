# Leetcode-2218.-Maximum-Value-of-K-Coins-From-Piles
# 💰 Maximum Value of Coins From Piles

## 🧩 Problem Statement

You have `n` **piles** of coins. Each pile contains a list of positive integers representing coin values from top to bottom. You can pick **at most** `k` coins **total** from these piles. Pick the coins in **order** from the top (you cannot skip coins in a pile).

**Goal:** Return the **maximum total value** of coins you can get by picking at most `k` coins.

### 📥 Example:

```
Input:
piles = [[1,100,3],[7,8,9]]
k = 2

Output: 101

Explanation:
Take 1 coin from the first pile (value = 1), and 1 from the second pile (value = 100).
```

---

## 🚀 Approaches

### 🟢 1. Recursive Approach (No Memoization)

* **Idea:** At each pile, decide whether to skip or take coins one by one (up to `k`).
* **Time Complexity:** Exponential 😖
* **Space Complexity:** O(nk) stack space

```cpp
int hlo(vector<vector<int>>& piles, int k, int pile) {
    if (k <= 0 || pile >= piles.size()) return 0;
    int nottaken = hlo(piles, k, pile + 1);
    int maxans = 0, ans = 0;
    for (int i = 0; i < piles[pile].size() && i < k; i++) {
        ans += piles[pile][i];
        maxans = max(maxans, ans + hlo(piles, k - i - 1, pile + 1));
    }
    return max(nottaken, maxans);
}
```

---

### 🟡 2. Recursive + Memoization (Top-Down DP)

* **Idea:** Same as above but store results of overlapping subproblems in a `dp[k][pile]` table.
* **Time Complexity:** O(n \* k)
* **Space Complexity:** O(n \* k)

```cpp
int dp[2001][1001];
int hlo(vector<vector<int>>& piles, int k, int pile) {
    if (k <= 0 || pile >= piles.size()) return 0;
    if (dp[k][pile] != -1) return dp[k][pile];
    int nottaken = hlo(piles, k, pile + 1);
    int maxans = 0, ans = 0;
    for (int i = 0; i < piles[pile].size() && i < k; i++) {
        ans += piles[pile][i];
        maxans = max(maxans, ans + hlo(piles, k - i - 1, pile + 1));
    }
    return dp[k][pile] = max(nottaken, maxans);
}
```

---

### 🔵 3. Bottom-Up Dynamic Programming

* **Idea:** Convert the recursive logic into an iterative 2D `dp[i][j]` table:

  * `dp[i][j]` = max value from first `i` piles and `j` coins
* **Time Complexity:** O(n \* k^2)
* **Space Complexity:** O(n \* k)

```cpp
vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1, 0));
for (int i = 1; i <= piles.size(); i++) {
    for (int coin = 0; coin <= k; coin++) {
        int sum = 0;
        for (int currcoin = 0; currcoin <= piles[i - 1].size() && currcoin <= coin; currcoin++) {
            if (currcoin - 1 >= 0) sum += piles[i - 1][currcoin - 1];
            dp[i][coin] = max(dp[i][coin], sum + dp[i - 1][coin - currcoin]);
        }
    }
}
```

---

## ⚔️ Comparison Table

| Approach               | Time Complexity | Space Complexity | Notes                          |
| ---------------------- | --------------- | ---------------- | ------------------------------ |
| Recursive (No Memo)    | Exponential     | O(nk)            | Very slow for large inputs     |
| Top-Down DP (Memoized) | O(n \* k^2)     | O(n \* k)        | Much faster, optimal recursive |
| Bottom-Up DP           | O(n \* k^2)     | O(n \* k)        | Clean and iterative            |

---

## 👨‍💻 Author Info

**Name:** Ridham Garg
**Institute:** Thapar Institute of Engineering and Technology, Patiala
**Roll Number:** 102203014
**Passion:** Optimizing recursive problems like a boss! 🚀💡

---

📌 If you understood all approaches, congratulations! You're one step closer to mastering dynamic programming. 🌟
