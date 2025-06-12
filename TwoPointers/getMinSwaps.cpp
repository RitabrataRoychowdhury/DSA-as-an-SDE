class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        
        // Step 1: Get the k-th next permutation
        for (int i = 0; i < k; ++i) {
            next_permutation(target.begin(), target.end());
        }
        
        // Step 2: Use two pointers: left for current position, right to find matching digit
        int swaps = 0;
        for (int left = 0; left < num.size(); ++left) {
            if (num[left] == target[left]) continue;
            
            int right = left + 1;
            // Find the digit in 'num' that matches target[left]
            while (right < num.size() && num[right] != target[left]) {
                ++right;
            }

            // Bubble the matching digit to the left position using adjacent swaps
            while (right > left) {
                swap(num[right], num[right - 1]);
                --right;
                ++swaps;
            }
        }
        
        return swaps;
    }
};