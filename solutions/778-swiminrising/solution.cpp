/*
My first djikstra solution

Its a bit hard to understand but i think i got it D:
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // We can just assume the grid is a graph, djikstras over it

        int n = grid.size();

        // best[r][c] cost to get to each cell
        vector<vector<int>> best(n, vector<int>(n, INT_MAX));

        // Min heap to store the next cheapest path to search thru
        // We wanna store the best cost so its min cost, r, c for the tuple
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        best[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        const int d[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            // If we've reached bottom right we just return the cost
            if (r == n - 1 && c == n - 1) {
                return cost;
            }

            // Check if current path is stale aka we don't need to check
            if (cost > best[r][c]) {
                continue;
            }

            // We can now go ahead and check for better options
            for (auto &dd : d) {
                int nr = r + dd[0];
                int nc = c + dd[1];

                // invalid
                if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                    continue;
                }

                int newCost = max(cost, grid[nr][nc]);

                // we now need to push only if this newcost is a better option, else we don't care for now
                if (newCost < best[nr][nc]) {
                    best[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }

        return -1;
    }
};
