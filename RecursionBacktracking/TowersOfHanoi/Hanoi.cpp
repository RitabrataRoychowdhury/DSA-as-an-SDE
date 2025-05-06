// GCC Optimizations
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const int INF = 1e9 + 5;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Fast I/O
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Debugging (disable before submission)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

// Memory Management
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

// Macro for Test Cases
#define TEST_CASES int tc; cin >> tc; while(tc--)

// Hanoi Recursive Function to solve the puzzle
void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << "\n";
        return;
    }
    // Move top n-1 disks from A to B using C as auxiliary
    hanoi(n - 1, A, C, B);

    // Move the nth disk from A to C
    cout << "Move disk " << n << " from " << A << " to " << C << "\n";

    // Move n-1 disks from B to C using A as auxiliary
    hanoi(n - 1, B, A, C);
}


// Main Solution Class
class Solution {
public:
    void solve() {
        int n; 
        cin >> n; // Number of disks
        hanoi(n, 'A', 'B', 'C'); // 'A' is source, 'B' is auxiliary, 'C' is destination
    }
};

int main() {
    fast_io(); // Enable fast I/O
    TEST_CASES {
        Solution sol;
        sol.solve();
    }
    return 0;
}
