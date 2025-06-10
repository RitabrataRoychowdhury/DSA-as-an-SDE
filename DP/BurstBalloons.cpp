class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons(n + 2);
        balloons[0] = 1;
        balloons[n + 1] = 1;

        // ✅ Correct copy from nums into balloons
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }

        // ✅ Initialize dp with -1 for memoization
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return burst(balloons, 0, n + 1, dp);  // ✅ should be n+1, not n+2
    }

    int burst(vector<int>& balloons, int left, int right, vector<vector<int>>& dp){
        if (left + 1 == right) {
            return 0;
        }

        if (dp[left][right] != -1) return dp[left][right];

        int maxCoins = 0;
        for (int k = left + 1; k < right; ++k) {
            int coins = balloons[left] * balloons[k] * balloons[right];
            coins += burst(balloons, left, k, dp);
            coins += burst(balloons, k, right, dp);
            maxCoins = max(maxCoins, coins);
        }

        dp[left][right] = maxCoins;
        return maxCoins;
    }
};
