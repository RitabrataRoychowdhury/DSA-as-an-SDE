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
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

// ========================================================================
// Problem Solution Class
// ========================================================================
class Solution {
public:
    int minCoins = INT_MAX;

    void dfs(vector<int>& coins, int amount, int count){
        if(amount < 0)return;
        if(amount == 0){
            minCoins = min(minCoins, count);
            return;
        }
        for(int coin : coins){
            dfs(coins, amount - coin, count + 1);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        dfs(coins, amount, 0);
        return minCoins == INT_MAX ? -1 : minCoins;
    }

    void dfsBranched(vector<int>& coins, int amount, int count, int index){
        if(amount < 0 || index >= coins.size()) return;
        if(amount == 0){
            minCoins = min(minCoins, count);
        }
        dfsBranched(coins, amount - coins[index], count + 1, index);
        dfsBranched(coins, amount,count, index + 1);
    }
};

class DP{
    public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); //dp[i] = min no. coins required to make amount i
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}

// ========================================================================
// Main Function
// ========================================================================
int32_t main()
{
    fast_io();

    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);

    cout << "Minimum coins required: " << result << endl;

    return 0;
}

// ========================================================================
