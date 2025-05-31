#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <climits>
#include <unordered_map>
#include <numeric>

using namespace std;

using ll = long long;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return dfs(nums, 0, target);
    }

    int dfs(vector<int> &nums, int index, int target)
    {
        if (index == nums.size())
        {
            return target == 0 ? 1 : 0;
        }
        int add = dfs(nums, index + 1, target - nums[index]);
        int sub = dfs(nums, index + 1, target + nums[index]);
        return add + sub;
    }
};

class DPSol
{
public:
    unordered_map<string, int> memo;

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return dfs(nums, 0, target);
    }

    int dfs(vector<int> &nums, int index, int target)
    {
        string key = to_string(index) + "," + to_string(target);
        if (memo.count(key)) return memo[key];

        if (index == nums.size())
            return target == 0 ? 1 : 0;

        int add = dfs(nums, index + 1, target - nums[index]);
        int sub = dfs(nums, index + 1, target + nums[index]);

        return memo[key] = add + sub;
    }
};

class DPMeth
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((target + total) % 2 != 0 || abs(target) > total)
            return 0;

        int subsetSum = (target + total) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int num : nums)
        {
            for (int j = subsetSum; j >= num; --j)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};

int32_t main()
{
    fast_io();

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution sol;
    int result = sol.findTargetSumWays(nums, target);

    cout << "Total ways to reach target = " << result << endl;

    return 0;
}
