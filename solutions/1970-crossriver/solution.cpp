#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canCross(vector<vector<int>>& cells, int rows, int cols, int day) {
        static int dx[4] = {1, -1, 0, 0};
        static int dy[4] = {0, 0, 1, -1};

        vector<vector<char>> grid(rows, vector<char>(cols, 0));
        vector<vector<char>> visited(rows, vector<char>(cols, 0));

        for (int i = 0; i < day; ++i) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;

        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                visited[0][c] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == rows - 1) return true;

            for (int k = 0; k < 4; ++k) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                if (grid[nr][nc]) continue;
                if (visited[nr][nc]) continue;

                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = cells.size();
        int ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canCross(cells, row, col, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
