
# Subsets Problem

## Problem Description

Given a collection of distinct integers, `nums`, return all possible subsets (the power set). 

The solution set must not contain duplicate subsets.

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

## Approach 1: Iterative (For Loop Based)

### Explanation:
The for-loop based approach generates subsets iteratively by building upon existing subsets.

1. Initialize an empty result list `res` with an empty subset `[[]]`.
2. Iterate through each element in the `nums` array.
3. For each element, add it to the subsets that have already been created, creating new subsets.
4. Append these new subsets to the result list.

### Code:
```cpp
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({}); // Start with an empty subset

    // Iterate through each element in nums
    for (int num : nums) {
        int n = res.size(); // Get the current size of the result list
        for (int i = 0; i < n; i++) {
            // Copy existing subsets and add the current number to each of them
            vector<int> temp = res[i];
            temp.push_back(num);
            res.push_back(temp);
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    
    // Print the result
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Time and Space Complexity:
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(2^n)

---

## Approach 2: Recursive (Binary Recursion Based)

### Explanation:
The recursive approach uses a **binary recursion** strategy similar to the inorder traversal technique, where we decide at each point whether to include the current number in the subset or not.

1. Use a recursive function to build subsets.
2. For each index, we either include the element at that index or exclude it.
3. Recursion explores both possibilities (include or exclude) and builds the subsets.
4. The base case is when all elements have been considered.

### Code:
```cpp
#include <vector>
#include <iostream>

using namespace std;

void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    // Base case: When we've considered all elements, add the current subset
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Exclude the current number and move to the next
    backtrack(nums, index + 1, current, result);
    
    // Include the current number and move to the next
    current.push_back(nums[index]);
    backtrack(nums, index + 1, current, result);
    // Backtrack: remove the last added element before moving to the next possibility
    current.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    // Print the result
    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### Time and Space Complexity:
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n) (Recursion depth)

---

## Summary:
- **For-Loop Approach**: Iterates through the elements and builds subsets iteratively. Simple to implement and easy to understand.
- **Recursive Approach (Binary Recursion)**: Explores both the inclusion and exclusion of each element at each step, using backtracking to ensure all possibilities are covered.