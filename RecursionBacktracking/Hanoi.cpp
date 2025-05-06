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

// Function to print the Hanoi banner
void printHanoiBanner() {
    cout << R"(hanoi(3, A, B, C)
├── hanoi(2, A, C, B)
│   ├── hanoi(1, A, B, C) → Move 1 A → C
│   ├── Move 2 A → B
│   └── hanoi(1, C, A, B) → Move 1 C → B
├── Move 3 A → C
└── hanoi(2, B, A, C)
    ├── hanoi(1, B, C, A) → Move 1 B → A
    ├── Move 2 B → C
    └── hanoi(1, A, B, C) → Move 1 A → C
    )" << "\n\n";
}

// Hanoi Recursive Function to solve the puzzle
void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << "\n";
        return;
    }
    // Move top n-1 disks from source to auxiliary
    hanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << "\n";
    
    // Move n-1 disks from auxiliary to destination
    hanoi(n - 1, auxiliary, source, destination);
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
    printHanoiBanner(); // Print the Hanoi banner before running test cases
    TEST_CASES {
        Solution sol;
        sol.solve();
    }
    return 0;
}
