#include <bits/stdc++.h>


class Solution {
public:
    bool isMagic(const vector<vector<int>>& g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        int mask = 0;
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int x = g[i][j];
                if (x < 1 || x > 9) return false;
                int bit = 1 << x;
                if (mask & bit) return false; // duplicate/perfect mask
                mask |= bit;
            }
        }

        for (int i = 0; i < 3; ++i) {
            int row = g[r+i][c] + g[r+i][c+1] + g[r+i][c+2];
            int col = g[r][c+i] + g[r+1][c+i] + g[r+2][c+i];
            if (row != 15 || col != 15) return false;
        }

        int d1 = g[r][c] + g[r+1][c+1] + g[r+2][c+2];
        int d2 = g[r][c+2] + g[r+1][c+1] + g[r+2][c];
        return d1 == 15 && d2 == 15;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < R; ++i) {
            for (int j = 0; j + 2 < C; ++j) {
                if (isMagic(grid, i, j)) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};