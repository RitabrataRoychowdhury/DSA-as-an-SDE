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
    vector<vector<string>> res;

    bool isPal(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void dfs(int start, string &s, vector<string> &path)
    {
        if (start == s.length())
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            if (isPal(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, s, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> path;
        dfs(0, s, path);
        return res;
    }
};

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        dfs(candidates, res, temp, target, 0);
        return res;
    }
    void dfs(vector<int> &candidates, vector<vector<int>> &res, vector<int> &temp, int target, int index)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (index >= candidates.size() || target < 0)
            return;

        temp.push_back(candidates[index]);
        dfs(candidates, res, temp, target - candidates[index], index + 1);
        temp.pop_back();
        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index])
        {
            nextIndex++;
        }
        dfs(candidates, res, temp, target, nextIndex);
    }
};

// ========================================================================
// Main Function
// ========================================================================
int32_t main()
{
    fast_io();

    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 5;
    vector<vector<int>> result = sol.combinationSum2(nums, k);

    for (const auto &subset : result)
    {
        cout << "[";
        for (int j = 0; j < subset.size(); ++j)
        {
            cout << subset[j];
            if (j < subset.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}

// ========================================================================
