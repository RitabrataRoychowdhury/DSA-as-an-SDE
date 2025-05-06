===========================
🗼 Tower of Hanoi - Recursion
===========================

Problem:
---------
Move 'n' disks from source peg A to destination peg C using auxiliary peg B, following these rules:
1. Only one disk can be moved at a time.
2. Only the top disk of any rod can be moved.
3. A larger disk cannot be placed on a smaller disk.

Recursive Strategy:
-------------------
To move n disks from A → C:
1. Move n-1 disks from A → B using C as auxiliary.
2. Move the nth (largest) disk from A → C.
3. Move n-1 disks from B → C using A as auxiliary.

Recursion Subproblems:
-----------------------
1. Move the smaller discs from A → B using C  
   ↳ Think of this as isolating the largest disk.
2. Move the largest (nth) disk directly from A → C  
3. Move the lower (previously moved) discs from B → C using A  

Code Pattern:
-------------
void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disk 1 from " << A << " to " << C << "\n";
        return;
    }
    hanoi(n - 1, A, C, B);                     // Step 1
    cout << "Move disk " << n << " from " << A << " to " << C << "\n";  // Step 2
    hanoi(n - 1, B, A, C);                     // Step 3
}

Time and Space:
---------------
- Moves required: 2^n - 1
- Time Complexity: O(2^n)
- Space Complexity: O(n) (recursion stack)

Mnemonic:
----------
"Move n-1 away → Move the big one → Bring n-1 back"

Example Flow (n = 3):
---------------------
hanoi(3, A, B, C)
├── hanoi(2, A, C, B)
│   ├── hanoi(1, A, B, C) → Move 1 A → C
│   ├── Move 2 A → B
│   └── hanoi(1, C, A, B) → Move 1 C → B
├── Move 3 A → C
└── hanoi(2, B, A, C)
    ├── hanoi(1, B, C, A) → Move 1 B → A
    ├── Move 2 B → C
    └── hanoi(1, A, B, C) → Move 1 A → C
