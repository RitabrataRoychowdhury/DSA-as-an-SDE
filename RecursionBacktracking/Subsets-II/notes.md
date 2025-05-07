
# 📘 Subsets & Subsets with Duplicates – Recursion Notes

### 🧠 Problem 1: Subsets (Without Duplicates)
- Leetcode Link: [Subsets](https://leetcode.com/problems/subsets/description/)
- Approach: DFS + Backtracking
- Key Idea: For each index, choose to include or exclude the element

#### Example: nums = [1, 2, 3]
```
Recursion Tree:

                            []
                    /                \
                [1]                   []
            /       \             /       \
        [1,2]     [1]         [2]       []
       /    \     |         /   \       |
 [1,2,3]  [1,2]  |    [2,3]   [2]      [3]
```

### ✍️ Code Highlights (Solution Class)
```cpp
sort(nums.begin(), nums.end());   // To ensure consistent order
dfs(...);                         // Classic backtracking
if (i != index && nums[i] == nums[i - 1]) continue;  // Skip duplicates
```

---

### 🧠 Problem 2: Subsets With Duplicates (Binary Choice Style)
- Leetcode Variant: Subsets II
- Approach: Binary Recursion with `included[]` array to track last inclusion
- Key Insight: Allow duplicate only if previous identical number was **included**

#### Why this condition?
```cpp
if (index == 0 || nums[index] != nums[index - 1] || included[index - 1])
```
- ✅ `index == 0`: Always include first element
- ✅ `nums[index] != nums[index - 1]`: Not a duplicate, safe to include
- ✅ `included[index - 1]`: Include duplicate only if the previous one was included (same branch)

#### Why **not** `!included[index - 1]`?
- It would allow duplicate subset paths like `[2]` and `[2]` from skipping vs including first `2`.

#### Example: nums = [2, 2]
```
Recursion Tree:

                  []
              /        \
           []          [2]  ← included[0] = true
           |             \
           |            [2,2]
```

#### Example2: nums = [1, 2, 2]
```
Recursion Tree:
                       []
            /                        \\
       [] (no 1)                 [1] (yes 1)
     /         \\                 /        \\
  []           [2]          [1]         [1,2]
 /  \\          / \\         /  \\          /    \\
[] [2]    [2] [2,2]     [1] [1,2]    [1,2] [1,2,2]

```

### ✍️ Code Highlights (SolutionBinary Class)
```cpp
included[index] = false;
binaryRecurse(...);

if (index == 0 || nums[index] != nums[index - 1] || included[index - 1]) {
    temp.push_back(...);
    included[index] = true;
    binaryRecurse(...);
    temp.pop_back();
    included[index] = false;
}
```

---

### 🛠️ Optimization Notes
- `sort(nums.begin(), nums.end())` is **crucial** for grouping duplicates.
- `included[]` lets you remember "which path" you're on in the recursion tree.
- DFS + pruning is powerful for subset problems with constraints.

---

### ✅ Summary:
| Version             | Handles Duplicates? | Approach            | Deduplication Logic                     |
|---------------------|---------------------|---------------------|------------------------------------------|
| `subsets`           | ❌                  | DFS / Backtracking  | None needed                              |
| `subsetsWithDup`    | ✅                  | Binary Choice Tree  | Use `included[i - 1]` to prevent repeats |

---

Author: Ritabrata  
Date: May 6th, 2025  