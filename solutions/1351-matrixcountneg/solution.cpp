#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int row = 0, col = cols - 1;
        int total = 0;

        while (row < rows && col >= 0) {
            if (grid[row][col] < 0) {
                total += rows - row;
                col--;
            } else {
                row++;
            }
        }

        return total;
    }
};
