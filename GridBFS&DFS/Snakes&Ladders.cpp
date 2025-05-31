class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0}); // {square_number, moves}
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) break;

                auto [row, col] = getCoords(next, n);
                if (board[row][col] != -1) {
                    next = board[row][col]; // ladder or snake jump
                }

                if (next == n * n) return moves + 1;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }

    pair<int, int> getCoords(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        int row = n - 1 - r;
        int col = (row % 2 == n % 2) ? (n - 1 - c) : c;
        return {row, col};
    }
};
