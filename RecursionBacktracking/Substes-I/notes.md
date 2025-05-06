# Subsets Problem

## Problem Description

Given a collection of distinct integers, `nums`, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

---

### Example:
**Input**:
```text
nums = [1, 2, 3]
```

**Output**:
```text
[
  [],
  [1],
  [2],
  [3],
  [1,2],
  [1,3],
  [2,3],
  [1,2,3]
]
```

---

## Approach 1: Iterative (For Loop Based)

### Explanation:
The for-loop based approach generates subsets iteratively by building upon existing subsets.

1. Initialize an empty result list `res` with an empty subset `[[]]`.
2. Iterate through each element in the `nums` array.
3. For each element, add it to the subsets that have already been created, creating new subsets.
4. Append these new subsets to the result list.

### Code:
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({}); // Start with an empty subset

    for (int num : nums) {
        int n = res.size();
        for (int i = 0; i < n; i++) {
            vector<int> temp = res[i];
            temp.push_back(num);
            res.push_back(temp);
        }
    }

    return res;
}
```

### Time and Space Complexity:
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(2^n)

---

## Approach 2: Recursive (Binary Recursion Based)

### Explanation:
This uses binary recursion to decide whether to include or exclude each element at every step. Subsets are only added at the leaf level.

### Code:
```cpp
void binaryRecurse(vector<int>& nums, vector<vector<int>> &res, vector<int>& temp, int index) {
    if (nums.size() == index) {
        res.push_back(temp);
        return;
    }

    // Include the current number
    temp.push_back(nums[index]);
    binaryRecurse(nums, res, temp, index + 1);
    temp.pop_back();

    // Exclude the current number
    binaryRecurse(nums, res, temp, index + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    binaryRecurse(nums, res, temp, 0);
    return res;
}
```

### Time and Space Complexity:
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n) (Recursion depth)

---

## Approach 3: Recursive (DFS Based with For-Loop)

### Explanation:
This DFS (depth-first search) based method uses a for-loop inside recursion to generate all subsets starting from the current index.

### Code:
```cpp
void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int index) {
    res.push_back(temp);
    for (int i = index; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        dfs(nums, res, temp, i + 1);
        temp.pop_back(); // backtrack
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(nums, res, temp, 0);
    return res;
}
```

### Time and Space Complexity:
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n) (Recursion depth)

---

## Summary Table

| Approach Type | Technique        | Code Structure | Adds Subsets At |
|---------------|------------------|----------------|-----------------|
| Iterative     | For-loop         | Two loops      | Every step      |
| Recursive     | Binary Recursion | Two recursive calls | Leaf nodes only |
| Recursive     | DFS + For-loop   | For loop + Rec | Every recursion step |

---

## Tips
- For interview purposes, the **binary recursion** approach is most intuitive to reason about.
- The **DFS + for-loop** version is useful for problems like **combinations** or **permutations**.