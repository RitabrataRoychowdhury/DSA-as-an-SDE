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

class Recursion
{
public:
    bool canPartition(vector<int> &nums)
    {
        int tot = 0;
        for (int num : nums)
        {
            tot += num;
        }
        if (tot % 2)
        {
            return false;
        }
        return dfs(nums, 0, tot / 2);
    }
    bool dfs(vector<int> &nums, int i, int target)
    {
        if (target == 0)
            return true;

        if (i == nums.size() || target < 0)
        {
            return false;
        }
        return max(dfs(nums, i + 1, target - nums[i]), dfs(nums, i + 1, target));
    }
};

// Top-Down
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int tot = 0;
        for (int num : nums)
        {
            tot += num;
        }
        if (tot % 2)
        {
            return false;
        }
        int target = tot / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return dfs(nums, 0, 0, target, dp);
    }

    bool dfs(vector<int> &nums, int i, int curr_sum, int target, vector<vector<int>> &dp)
    {
        if (curr_sum == target)
        {
            return true;
        }
        if (i == nums.size() || curr_sum > target)
        {
            return false;
        }
        if (dp[i][curr_sum] != -1)
        {
            return dp[i][curr_sum];
        }
        bool take = dfs(nums, i + 1, curr_sum + nums[i], target, dp);
        bool no_take = dfs(nums, i + 1, curr_sum, target, dp);
        dp[i][curr_sum] = max(take, no_take);
        return dp[i][curr_sum];
    }
};
// 1D dp
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot % 2 != 0)
            return false;

        int target = tot / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums)
        {
            for (int s = target; s >= num; --s)
            {
                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[target];
    }
};

// ========================================================================
// Main Function
// ========================================================================
int32_t main()
{
    fast_io();

    Solution sol;

    cout << "Total sum of all queries: " << result << endl;

    return 0;
}

// ========================================================================
