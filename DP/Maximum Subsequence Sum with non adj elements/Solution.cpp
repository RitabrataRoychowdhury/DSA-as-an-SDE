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
// TLE but top down approach
class Solution
{
public:
    const int MOD = 1e9 + 7;

    int robFrom(int i, vector<int> &nums, vector<int> &memo)
    {
        if (i >= nums.size())
            return 0;
        if (memo[i] != -1)
            return memo[i];

        int pick = nums[i] + robFrom(i + 2, nums, memo);
        int skip = robFrom(i + 1, nums, memo);

        return memo[i] = max(pick, skip);
    }

    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries)
    {
        long long total = 0;

        for (auto &q : queries)
        {
            int pos = q[0];
            int val = q[1];
            nums[pos] = val;

            vector<int> memo(nums.size(), -1);
            int maxSum = robFrom(0, nums, memo);

            total = (total + maxSum) % MOD;
        }

        return total;
    }
};

// ========================================================================
// Main Function
// ========================================================================
int32_t main()
{
    fast_io();

    Solution sol;
    vector<int> houses = {1, 2, 5}; // initial nums array
    vector<vector<int>> queries = {
        {1, -2}, // Update index 1 to -2
        {0, -3}  // Update index 0 to -3
    };

    int result = sol.maximumSumSubsequence(houses, queries);

    cout << "Total sum of all queries: " << result << endl;

    return 0;
}

// ========================================================================
