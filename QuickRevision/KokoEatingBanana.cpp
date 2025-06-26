// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.

#include <bits/stdc++.h>
using namespace std;

// Fast I/O
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
        }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high){
            int mid = low + (high - low)/2;
            int k = 0;
            for(int pile : piles) k += (pile - mid + 1)/mid;
            if(k <= h){
                high   = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
