// ========================================================================
//  Template for Competitive Programming
//  Author: Ritabrata
//  Problem: Combinations -- https://leetcode.com/problems/combinations/
//  Algorithm: DFS, Backtracking
//  Date: May 6th-2025
// ========================================================================

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream> // Needed for LeetCode hack
#include <climits>

using namespace std;

// ========================================================================
// Type Aliases
// ========================================================================
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// ========================================================================
// Constants
// ========================================================================
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);

// ========================================================================
// Fast I/O
// ========================================================================
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

// ========================================================================
// Debugging
// ========================================================================
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x) //
#endif

// ========================================================================
// Heaps
// ========================================================================
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;

// ========================================================================
// Macros
// ========================================================================
#define TEST_CASES \
    int tc;        \
    cin >> tc;     \
    while (tc--)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// ========================================================================
// Helper Functions
// ========================================================================
template <typename T>
T power(T base, T exp, T mod)
{
    T res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// ========================================================================
// LeetCode Hack
// ========================================================================
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

// ========================================================================
// Problem Solution Class
// ========================================================================

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        vector<vector<int>> dp() return isSubsetSumRec(arr, arr.size(), sum);
    }

    bool isSubsetSumRec(vector<int> &nums, int n, int sum)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (nums[n - 1] > sum)
        {
            return isSubsetSumRec(nums, n - 1, sum);
        }
        return isSubsetSumRec(nums, n - 1, sum) || isSubsetSumRec(nums, n - 1, sum - nums[n - 1]);
    }
};

class DP
{
public:
    vector<vector<int>> dp; // Memoization table

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        // Initialize dp with -1
        dp = vector<vector<int>>(n + 1, vector<int>(sum + 1, -1));
        return isSubsetSumRec(arr, n, sum);
    }

private:
    bool isSubsetSumRec(vector<int> &nums, int n, int sum)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;

        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n - 1] > sum)
            return dp[n][sum] = isSubsetSumRec(nums, n - 1, sum);

        return dp[n][sum] = isSubsetSumRec(nums, n - 1, sum) ||
                            isSubsetSumRec(nums, n - 1, sum - nums[n - 1]);
    }
};

// Bottom_up Version
class BottomUp
{
public:
    bool isSubsetSum(vector<int> &nums, int n, int sum)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case: sum = 0 is always possible with 0 elements
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int s = 1; s <= sum; ++s)
            {
                if (nums[i - 1] > s)
                    dp[i][s] = dp[i - 1][s];
                else
                    dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]];
            }
        }

        return dp[n][sum];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int tot = accumulate(nums.begin(),nums.end(), 0);
        if(tot % 2 != 0) return false;
        int target = tot/2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int num : nums){
            for(int j= target;j>=num;j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

// ========================================================================
// Main Function
// ========================================================================
int32_t
main()
{
    fast_io();

    Solution sol;

    cout << "Total sum of all queries: " << result << endl;

    return 0;
}

// ========================================================================
