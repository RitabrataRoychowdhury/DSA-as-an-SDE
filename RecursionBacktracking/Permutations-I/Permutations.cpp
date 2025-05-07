// ========================================================================
//  Template for Competitive Programming
//  Author: Ritabrata
//  Problem: Subsets -- https://leetcode.com/problems/subsets/description/
//  Algorithm: DFS, Backtracking
//  Date: May 6th- 2025
// ========================================================================

// GCC Optimizations (Optional, for performance-critical problems)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

// Include Header Files
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
// Add more as needed, but keep the list minimal for faster compilation

using namespace std;

// ========================================================================
// Type Aliases (for cleaner code)
// ========================================================================
using ll = long long;           // Signed 64-bit integer
using ull = unsigned long long; // Unsigned 64-bit integer
using ld = long double;         // Long double for higher precision

// ========================================================================
// Constants (for frequently used values)
// ========================================================================
const int INF = 1e9 + 5;      // A large integer (10^9 + 5)
const ll LINF = 1e18;         // A large long long (10^18)
const int MOD = 1e9 + 7;      // Modulo for problems involving modular arithmetic
const double PI = acos(-1.0); //  Value of PI

// ========================================================================
// Fast I/O (for faster input/output)
// ========================================================================
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

// ========================================================================
// Debugging (for development, disable before submission)
// ========================================================================
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x) //
#endif

// ========================================================================
// Memory Management (Optional: for specific data structures)
// ========================================================================
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>; // Min-Priority Queue

template <typename T>
using max_heap = priority_queue<T>; // Max-Priority Queue

// ========================================================================
// Macros (for common code patterns)
// ========================================================================
#define TEST_CASES \
    int tc;        \
    cin >> tc;     \
    while (tc--)                                     // For multiple test cases
#define FOR(i, a, b) for (int i = (a); i < (b); ++i) //  For loop
#define REP(i, n) FOR(i, 0, n)                       //  For loop from 0 to n-1
#define all(x) (x).begin(), (x).end()                //  For iterating over a container
#define sz(x) (int)(x).size()                        //  Size of a container

// ========================================================================
// Helper Functions (Optional: for common operations)
// ========================================================================
template <typename T>
T power(T base, T exp, T mod)
{ // Modular exponentiation
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
// Problem Solution Class
// ========================================================================

// Solution1 by saving the used elements in isUsed
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;               // To store the result
        vector<int> temp;                      // To store current permutation
        vector<bool> used(nums.size(), false); // Used array to track elements
        dfs(nums, used, temp, res, 0);         // Start recursion
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &temp, vector<vector<int>> &res, int index)
    {
        if (temp.size() == nums.size())
        {                        // If the current permutation is complete
            res.push_back(temp); // Store the permutation
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue; // If this number is already used, skip

            used[i] = true;          // Mark this number as used
            temp.push_back(nums[i]); // Add number to the current permutation

            dfs(nums, used, temp, res, i + 1); // Recur to the next level

            temp.pop_back(); // Backtrack: remove the number
            used[i] = false; // Mark this number as not used
        }
    }
};

class TraditionalSwap
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        solve(0, nums,res);
        return res;
    }
    void solve(int index, vector<int>& nums, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            solve(index + 1, nums,res);
            swap(nums[index], nums[i]);
        }
    }
};

// ========================================================================
// Main Function
// ========================================================================
int32_t main()
{
    fast_io(); // Enable fast input/output

    // Handle multiple test cases (if applicable)
    // int t; cin >> t; while(t--)
    //{
    //    Solution sol;
    //    sol.solve();
    //}

    // Handle a single test case
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> result = sol.permute(nums);

    // Print the result
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
