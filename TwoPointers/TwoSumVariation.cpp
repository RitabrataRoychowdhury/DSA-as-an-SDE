// Ques. Given an array of ‘n’ integers, your task is to print the indices of four integers (a, b, c, d) such that ‘a+b = c+d’. (It was a very loose ended question. I had to explicitly clarify a lot of things before getting a clear picture of output).

#include <bits/stdc++.h>
using namespace std;

// Function that returns 4 indices: i, j, k, l such that arr[i] + arr[j] == arr[k] + arr[l]
vector<int> findFourIndices(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, pair<int, int>> sumMap;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = arr[i] + arr[j];

            if (sumMap.count(sum)) {
                auto [x, y] = sumMap[sum];
                // Ensure all indices are distinct
                if (x != i && x != j && y != i && y != j) {
                    return {x, y, i, j};
                }
                // We don't overwrite to preserve the first valid pair found
            } else {
                sumMap[sum] = {i, j};
            }
        }
    }

    return {}; // No solution found
}
