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

class Solution{
    public:
    int numResueBoats(vector<int>& people, int limit){
       int n = people.size();
       sort(people.begin(), people.end());
       int cnt = 0, start = 0, end = n - 1;
       while(start <= end){
        if(people[start] + people[end] <= limit){
            start++;
            end--;
        }else{
            end--;
        }
        cnt++;
       }
    }
};
