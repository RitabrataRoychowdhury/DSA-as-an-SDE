#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    
    //[1,2,3] i = n - 2 = 1 => nums[1] = 2 is greater than or equal to nums[2] = 3 which is false
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    // If we found a pair where nums[i] < nums[i + 1], we need to find the next greater element
    if (i >= 0) {
        //j = 2 which is the last elm
        int j = n - 1;
        // Find the smallest element on the right side of nums[i] that is greater than nums[i]
        //nums[j] > nums[i]:
        // nums[2] (3) > nums[1] (2) → True 
        // We found j = 2.
        while (nums[j] <= nums[i]) {
            j--;
        }
        //[1,3,2] i = 1, j = 2
        swap(nums[i], nums[j]);
    }
    // Reverse the elements after index i to get the next permutation
    reverse(nums.begin() + i + 1, nums.end());
}
};