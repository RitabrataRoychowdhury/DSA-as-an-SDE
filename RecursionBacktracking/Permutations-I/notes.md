
# Permutations - Leetcode [46](https://leetcode.com/problems/permutations/description/)

This document explains two approaches for generating permutations of a list of numbers.

---

## 🔢 Input Example

```cpp
vector<int> nums = {1, 2, 3};
```

---

## 🧠 Approach 1: Using `used[]` Array (Backtracking)

### Code

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, temp, res);
        return res;
    }

    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &temp, vector<vector<int>> &res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            dfs(nums, used, temp, res);
            temp.pop_back();
            used[i] = false;
        }
    }
};
```

### Recursion Tree for [1, 2, 3]

```
[]
├── [1]
│   ├── [1,2]
│   │   └── [1,2,3] ✅
│   └── [1,3]
│       └── [1,3,2] ✅
├── [2]
│   ├── [2,1]
│   │   └── [2,1,3] ✅
│   └── [2,3]
│       └── [2,3,1] ✅
└── [3]
    ├── [3,1]
    │   └── [3,1,2] ✅
    └── [3,2]
        └── [3,2,1] ✅
```

---

## 🔁 Approach 2: Traditional Swap (In-place Permutation)

### Code

```cpp
class TraditionalSwap {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        solve(0, nums, res);
        return res;
    }

    void solve(int index, vector<int>& nums, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(index + 1, nums, res);
            swap(nums[index], nums[i]); // backtrack
        }
    }
};
```

### Recursion Tree for [1, 2, 3]

```
[1,2,3]
├── swap(0,0) → [1,2,3]
│   ├── swap(1,1) → [1,2,3] ✅
│   └── swap(1,2) → [1,3,2] ✅
├── swap(0,1) → [2,1,3]
│   ├── swap(1,1) → [2,1,3] ✅
│   └── swap(1,2) → [2,3,1] ✅
└── swap(0,2) → [3,2,1]
    ├── swap(1,1) → [3,2,1] ✅
    └── swap(1,2) → [3,1,2] ✅
```

---

## ✅ Final Output

```
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,2,1]
[3,1,2]
```

---

## 🧠 Key Takeaways

- `used[]` approach avoids modifying the original input and uses extra space.
- `swap` approach is space-optimized but modifies the input array in-place.
- Always use `solve(index + 1)` (not `i + 1`) in the swap approach to ensure correct recursive depth.
